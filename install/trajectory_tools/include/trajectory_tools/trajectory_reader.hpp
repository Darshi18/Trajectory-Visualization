#ifndef TRAJECTORY_READER_HPP
#define TRAJECTORY_READER_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include <vector>

class TrajectoryReader : public rclcpp::Node
{
public:
    TrajectoryReader();

private:
    void loadTrajectoryFromCSV(const std::string &filename);
    void publishMarkers();

    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr marker_pub_;
    std::vector<geometry_msgs::msg::PoseStamped> trajectory_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif // TRAJECTORY_READER_HPP
