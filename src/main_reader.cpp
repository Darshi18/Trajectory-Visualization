/*#include "trajectory_tools/trajectory_reader.hpp"


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TrajectoryReader>());
    rclcpp::shutdown();
    return 0;
} */

#include "rclcpp/rclcpp.hpp"
#include "trajectory_reader.cpp"  // or use a header if split

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TrajectoryReader>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

