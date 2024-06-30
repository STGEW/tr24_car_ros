#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tr24_ros_interfaces/msg/car_engines_state.hpp"


class UartTxNode : public rclcpp::Node
{
public:
  UartTxNode()
  : Node("uart_tx_node")
  {
    auto topic_callback =
      [this](tr24_ros_interfaces::msg::CarEnginesState::UniquePtr msg) -> void {
        RCLCPP_INFO(
          this->get_logger(),
          "I heard: '%d', '%d'",
          msg->left,
          msg->right);
      };
    subscription_ =
      this->create_subscription<tr24_ros_interfaces::msg::CarEnginesState>(
        "rc_car_engines_state", 10, topic_callback);
  }

private:
  rclcpp::Subscription<tr24_ros_interfaces::msg::CarEnginesState>::SharedPtr subscription_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<UartTxNode>());
  rclcpp::shutdown();
  return 0;
}
