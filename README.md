


### useful commands


source /opt/ros/jazzy/setup.bash

https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html

source install/local_setup.bash

cd ~/ros2_ws

colcon build

# To build a package with name tr24_car_ros
cd ~/ros2_ws/src
colcon build --packages-select tr24_car_ros

# To run uart_tx_node of a package tr24_car_ros
cd ~/ros2_ws
ros2 run tr24_car_ros uart_tx_node
ros2 run tr24_car_ros uart_tx_load_node


colcon build --packages-select tr24_ros_interfaces

source install/setup.bash
ros2 interface show tr24_ros_interfaces/msg/CarEnginesState