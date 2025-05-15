Trajectory-Visualization

A ROS 2 C++ package for reading, processing, and saving robot trajectory data for visualization and motion analysis.
📌 Features

    ✅ Read trajectory data from CSV files (trajectory_reader.cpp)

    ✅ Save trajectory data from odometry topics to CSV files (trajectory_saver.cpp)

📁 Project Structure

trajectory_tools/
├── build/
├── data/                     # Sample CSV files or saved output
├── include/
├── install/
├── log/
├── package.xml
├── README.md
├── src/
│   ├── main_reader.cpp
│   ├── main_saver.cpp
│   ├── trajectory_reader.cpp
│   ├── trajectory_saver.cpp
└── srv/

🚀 Usage
Reading a trajectory file

Run the trajectory reader node with a custom CSV file path:

ros2 run trajectory_tools trajectory_reader_node \
  --ros-args -p trajectory_file:=/path/to/your/trajectory.csv

    Replace /path/to/your/trajectory.csv with the full path to your CSV file.

Saving trajectory data

Run the trajectory saver node with the desired odometry topic and output file path:

ros2 run trajectory_tools trajectory_saver_node \
  --ros-args -p odom_topic:=/odom -p output_file:=/path/to/save/trajectory.csv

    Replace /path/to/save/trajectory.csv with the desired file output path.

✅ Example

ros2 run trajectory_tools trajectory_saver_node \
  --ros-args -p odom_topic:=/odom \
  -p output_file:=/home/dd/trajectory_tools/data/trajectory.csv

ros2 run trajectory_tools trajectory_reader_node \
  --ros-args -p trajectory_file:=/home/dd/trajectory_tools/data/trajectory.csv

⚠️ Notes

    Ensure your trajectory files are properly formatted CSVs.

    You can extend the reader/saver logic to support other formats or add filtering, interpolation, etc.

👤 Author

Darshi18
