#include "trajectory_tools/trajectory_saver.hpp"
#include <fstream>

TrajectorySaver::TrajectorySaver(const rclcpp::NodeOptions & options)
: Node("trajectory_saver_node", options)
{
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10,
        std::bind(&TrajectorySaver::odomCallback, this, std::placeholders::_1));

    marker_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>(
        "/saved_trajectory_markers", 10);

    save_srv_ = this->create_service<trajectory_tools::srv::SaveTrajectory>(
        "save_trajectory",
        std::bind(&TrajectorySaver::saveServiceCallback, this, std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(this->get_logger(), "Trajectory saver node has started.");
}

void TrajectorySaver::odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    geometry_msgs::msg::PoseStamped pose;
    //rclcpp::Clock clock(RCL_SYSTEM_TIME);
    //pose.header.stamp = clock.now();

    pose.header.stamp = this->now();
    pose.header.frame_id = "odom";
    pose.pose = msg->pose.pose;

    trajectory_.push_back(pose);
    publishMarkers();
    
    RCLCPP_INFO(this->get_logger(), "Received pose: x=%.2f, y=%.2f, z=%.2f",
                    pose.pose.position.x, pose.pose.position.y, pose.pose.position.z);
}

void TrajectorySaver::publishMarkers()
{
    visualization_msgs::msg::MarkerArray marker_array;
    visualization_msgs::msg::Marker marker;
    marker.header.frame_id = "odom";
    marker.header.stamp = this->now();
    marker.type = visualization_msgs::msg::Marker::SPHERE_LIST;
    marker.action = visualization_msgs::msg::Marker::ADD;
    marker.scale.x = marker.scale.y = marker.scale.z = 0.05;
    //marker.color = {1.0, 0.0, 0.0, 1.0};
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 0.0;
    marker.color.a = 1.0;

    marker.id = 0;

    for (const auto &pose : trajectory_)
    {
        geometry_msgs::msg::Point p;
        p.x = pose.pose.position.x;
        p.y = pose.pose.position.y;
        p.z = pose.pose.position.z;
        marker.points.push_back(p);
    }

    marker_array.markers.push_back(marker);
    marker_pub_->publish(marker_array);
}

void TrajectorySaver::saveServiceCallback(
    const std::shared_ptr<trajectory_tools::srv::SaveTrajectory::Request> request,
    std::shared_ptr<trajectory_tools::srv::SaveTrajectory::Response> response)
{
    rclcpp::Time now = this->now();
    //rclcpp::Clock clock(RCL_SYSTEM_TIME);
    //rclcpp::Time now = clock.now();

    std::vector<geometry_msgs::msg::PoseStamped> filtered;
    RCLCPP_INFO(this->get_logger(), "Filtering trajectory for last %.1f seconds", request->duration_sec);

    /*for (const auto &pose : trajectory_)
    {
        rclcpp::Time pose_time(pose.header.stamp);
        if ((now - pose_time).seconds() <= request->duration_sec)
        {
            filtered.push_back(pose);
        }
    }
    
    RCLCPP_INFO(this->get_logger(), "Trajectory points total: %zu", trajectory_.size());
    RCLCPP_INFO(this->get_logger(), "Filtered (last %.1f sec): %zu", request->duration_sec, filtered.size()); */
    
    for (const auto &pose : trajectory_)
    {
        rclcpp::Time pose_time(pose.header.stamp);
        double age = (now - pose_time).seconds();

        RCLCPP_DEBUG(this->get_logger(), "Pose time: %.2f, Age: %.2f", pose_time.seconds(), age);

        if (age <= request->duration_sec)
        {
            filtered.push_back(pose);
        }
    }

    RCLCPP_INFO(this->get_logger(), "Total poses recorded: %zu", trajectory_.size());
    RCLCPP_INFO(this->get_logger(), "Filtered poses: %zu", filtered.size());

	
    std::ofstream file(request->filename, std::ios::out);
    if (!file.is_open())
    {
        response->success = false;
        response->message = "Failed to open file: " + request->filename;
        return;
    }
    
    file << std::fixed << std::setprecision(6);
    for (const auto &pose : filtered)
    {
        /*file << pose.header.stamp.sec << "." << pose.header.stamp.nanosec << ","
             << pose.pose.position.x << ","
             << pose.pose.position.y << ","
             << pose.pose.position.z << "\n"; */
       double time_sec = rclcpp::Time(pose.header.stamp).seconds();      
       file << rclcpp::Time(pose.header.stamp).seconds() << ","
            << pose.pose.position.x << ","
            << pose.pose.position.y << ","
            << pose.pose.position.z << "\n";
            
      RCLCPP_INFO(this->get_logger(), "Saved: %.6f, %.3f, %.3f, %.3f",
                time_sec,
                pose.pose.position.x,
                pose.pose.position.y,
                pose.pose.position.z);
    }

    /*for (const auto &pose : filtered)
    {
        /*file << pose.header.stamp.sec << "." << pose.header.stamp.nanosec << ","
             << pose.pose.position.x << "," << pose.pose.position.y << ","
             << pose.pose.position.z << "\n"; */
       /* file << pose.header.stamp.sec << "." << pose.header.stamp.nanosec << ","
             << std::fixed << pose.pose.position.x << ","
             << pose.pose.position.y << ","
             << pose.pose.position.z << "\n";
     
             
    } */

    file.close();
    response->success = true;
    response->message = "Trajectory saved to: " + request->filename;
    RCLCPP_INFO(this->get_logger(), "%s", response->message.c_str());
}
