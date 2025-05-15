#ifndef TRAJECTORY_SAVER_HPP
#define TRAJECTORY_SAVER_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "trajectory_tools/srv/save_trajectory.hpp"

#include <vector>
#include <string>

class TrajectorySaver : public rclcpp::Node
{
public:
    //TrajectorySaver();
    explicit TrajectorySaver(const rclcpp::NodeOptions & options);

private:
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void publishMarkers();
    void saveServiceCallback(
        const std::shared_ptr<trajectory_tools::srv::SaveTrajectory::Request> request,
        std::shared_ptr<trajectory_tools::srv::SaveTrajectory::Response> response);

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr marker_pub_;
    rclcpp::Service<trajectory_tools::srv::SaveTrajectory>::SharedPtr save_srv_;
    std::vector<geometry_msgs::msg::PoseStamped> trajectory_;
};

#endif // TRAJECTORY_SAVER_HPP
