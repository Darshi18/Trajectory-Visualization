#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/path.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/LinearMath/Quaternion.h>

class TrajectoryReader : public rclcpp::Node
{
public:
    TrajectoryReader()
        : Node("trajectory_reader")
    {
        this->declare_parameter<std::string>("trajectory_file", "");

        rclcpp::Parameter param;
        if (!this->get_parameter("trajectory_file", param)) {
            RCLCPP_ERROR(this->get_logger(), "Parameter 'trajectory_file' not set!");
            rclcpp::shutdown();
            return;
        }

        std::string filepath = param.as_string();
        if (filepath.empty()) {
            RCLCPP_ERROR(this->get_logger(), "trajectory_file parameter is empty.");
            rclcpp::shutdown();
            return;
        }

        path_pub_ = this->create_publisher<nav_msgs::msg::Path>("planned_path", 10);
        path_.header.frame_id = "map";

        loadTrajectoryFromCSV(filepath);
    }

private:
    void loadTrajectoryFromCSV(const std::string &filepath)
    {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "Could not open trajectory file: %s", filepath.c_str());
            rclcpp::shutdown();
            return;
        }

        std::string line;
        size_t line_number = 0;
        while (std::getline(file, line)) {
            ++line_number;
            if (line.empty()) continue;
            
            RCLCPP_INFO(this->get_logger(), "Reading line %zu: '%s'", line_number, line.c_str());

            std::stringstream ss(line);
            std::string time_str, x_str, y_str, z_str;

            if (std::getline(ss, time_str, ',') &&
                std::getline(ss, x_str, ',') &&
                std::getline(ss, y_str, ',') &&
                std::getline(ss, z_str, ',')) {
                try {
                    double x = std::stod(x_str);
                    double y = std::stod(y_str);
                    double z = std::stod(z_str);

                    geometry_msgs::msg::PoseStamped pose;
                    pose.header.frame_id = "map";
                    pose.header.stamp = this->now();

                    pose.pose.position.x = x;
                    pose.pose.position.y = y;
                    pose.pose.position.z = z;

                    tf2::Quaternion q;
                    q.setRPY(0, 0, 0);
                    pose.pose.orientation = tf2::toMsg(q);

                    path_.poses.push_back(pose);
                } catch (const std::exception &e) {
                    RCLCPP_WARN(this->get_logger(), "Skipping line %zu due to parse error: %s", line_number, e.what());
                }
            } else {
                RCLCPP_WARN(this->get_logger(), "Skipping malformed line %zu: '%s'", line_number, line.c_str());
            }
        }

        //file.close();

        path_.header.stamp = this->now();
        path_pub_->publish(path_);
        RCLCPP_INFO(this->get_logger(), "Published path with %zu poses", path_.poses.size());
    }

    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;
    nav_msgs::msg::Path path_;
};

