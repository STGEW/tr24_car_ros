


### useful commands
https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-A-Workspace/Creating-A-Workspace.html

```
ros2 topic pub -1 /car_new_coords tr24_ros_interfaces/msg/CarEnginesState "{left: 0.0, right: 50.0}"
```


For Ubuntu Server 22.04
https://robofoundry.medium.com/running-ros2-foxy-on-raspberry-pi-zero-2w-a4720334d3bb

```
sudo apt-get install ros-humble-desktop
```

Install yolov8 package
https://docs.ultralytics.com/quickstart/#__tabbed_1_1
```
pip install ultralytics
```

```
source /opt/ros/jazzy/setup.bash
source /opt/ros/humble/setup.bash
source /opt/ros/foxy/setup.bash

https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html

rosdep install -i --from-path src --rosdistro foxy -y

cd ~/ros2_ws
source install/local_setup.bash
colcon build --packages-select py_pubsub
```

# To build a package with name tr24_car_ros
```
cd ~/ros2_ws/src
colcon build --executor sequential
# colcon build --packages-select tr24_car_ros
# colcon build --packages-select tr24_car_ros --parallel-workers 2
```


# To run uart_tx_node of a package tr24_car_ros
```
cd ~/ros2_ws
ros2 run tr24_car_ros uart_tx_node
ros2 run tr24_car_ros uart_tx_load_node


colcon build --packages-select tr24_ros_interfaces

source install/setup.bash
ros2 interface show tr24_ros_interfaces/msg/CarEnginesState
```


### rpi and UARTS
We need 2 uarts

```
sudo raspi-config

    Go to Interface Options > Serial Port.

    When prompted:
        Would you like a login shell to be accessible over serial? -> Select No.
        Would you like the serial port hardware to be enabled? -> Select Yes.
```


```
sudo nano /boot/config.txt
```

```
# Enable the main UART (PL011) on GPIO 14 (TX) and GPIO 15 (RX)
enable_uart=1

# Enable the mini UART (on GPIO 32 (TX) and GPIO 33 (RX) for UART1)
dtoverlay=uart1

# Optionally set the core frequency to a fixed value to stabilize the mini UART baud rate
core_freq=250
```

```
sudo reboot
```
