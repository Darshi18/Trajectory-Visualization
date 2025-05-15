/*#include "trajectory_tools/trajectory_saver.hpp"


int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TrajectorySaver>());
    rclcpp::shutdown();
    return 0;
} */

#include "rclcpp/rclcpp.hpp"
#include "trajectory_tools/trajectory_saver.hpp"


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TrajectorySaver>(rclcpp::NodeOptions()));
  rclcpp::shutdown();
  return 0;
}
