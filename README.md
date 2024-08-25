


### useful commands

```
source /opt/ros/jazzy/setup.bash

https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html

source install/local_setup.bash

cd ~/ros2_ws

colcon build
```

# To build a package with name tr24_car_ros
```
cd ~/ros2_ws/src
colcon build --packages-select tr24_car_ros
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
