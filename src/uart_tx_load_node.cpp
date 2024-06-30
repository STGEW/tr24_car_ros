#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "tr24_ros_interfaces/msg/car_engines_state.hpp"

using namespace std::chrono_literals;


class UartTxLoadNode : public rclcpp::Node
{
public:
  UartTxLoadNode()
  : Node("uart_tx_load_node")
  {
    publisher_ = this->create_publisher<tr24_ros_interfaces::msg::CarEnginesState>(
      "rc_car_engines_state", 10);
    auto timer_callback =
      [this]() -> void {
        auto message = tr24_ros_interfaces::msg::CarEnginesState();
        message.left = 150;
        message.right = 180;
        RCLCPP_INFO(
          this->get_logger(),
          "Publishing: '%d', '%d'",
          message.left,
          message.right);
        this->publisher_->publish(message);
      };
    timer_ = this->create_wall_timer(500ms, timer_callback);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<tr24_ros_interfaces::msg::CarEnginesState>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<UartTxLoadNode>());
  rclcpp::shutdown();
  return 0;
}
