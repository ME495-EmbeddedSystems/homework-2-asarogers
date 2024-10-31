// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_brick_interfaces:msg/Tilt.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/tilt.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__BUILDER_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_brick_interfaces/msg/detail/tilt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_brick_interfaces
{

namespace msg
{

namespace builder
{

class Init_Tilt_tilt
{
public:
  Init_Tilt_tilt()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_brick_interfaces::msg::Tilt tilt(::turtle_brick_interfaces::msg::Tilt::_tilt_type arg)
  {
    msg_.tilt = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::msg::Tilt msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::msg::Tilt>()
{
  return turtle_brick_interfaces::msg::builder::Init_Tilt_tilt();
}

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__BUILDER_HPP_
