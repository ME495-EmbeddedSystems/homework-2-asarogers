// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_brick_interfaces:msg/TurtleLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/turtle_location.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__BUILDER_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_brick_interfaces/msg/detail/turtle_location__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_brick_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtleLocation_theta
{
public:
  explicit Init_TurtleLocation_theta(::turtle_brick_interfaces::msg::TurtleLocation & msg)
  : msg_(msg)
  {}
  ::turtle_brick_interfaces::msg::TurtleLocation theta(::turtle_brick_interfaces::msg::TurtleLocation::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::msg::TurtleLocation msg_;
};

class Init_TurtleLocation_y
{
public:
  explicit Init_TurtleLocation_y(::turtle_brick_interfaces::msg::TurtleLocation & msg)
  : msg_(msg)
  {}
  Init_TurtleLocation_theta y(::turtle_brick_interfaces::msg::TurtleLocation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TurtleLocation_theta(msg_);
  }

private:
  ::turtle_brick_interfaces::msg::TurtleLocation msg_;
};

class Init_TurtleLocation_x
{
public:
  Init_TurtleLocation_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtleLocation_y x(::turtle_brick_interfaces::msg::TurtleLocation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TurtleLocation_y(msg_);
  }

private:
  ::turtle_brick_interfaces::msg::TurtleLocation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::msg::TurtleLocation>()
{
  return turtle_brick_interfaces::msg::builder::Init_TurtleLocation_x();
}

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__BUILDER_HPP_
