// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_brick_interfaces:msg/BrickLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/brick_location.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_LOCATION__BUILDER_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_LOCATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_brick_interfaces/msg/detail/brick_location__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_brick_interfaces
{

namespace msg
{

namespace builder
{

class Init_BrickLocation_z
{
public:
  explicit Init_BrickLocation_z(::turtle_brick_interfaces::msg::BrickLocation & msg)
  : msg_(msg)
  {}
  ::turtle_brick_interfaces::msg::BrickLocation z(::turtle_brick_interfaces::msg::BrickLocation::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::msg::BrickLocation msg_;
};

class Init_BrickLocation_y
{
public:
  explicit Init_BrickLocation_y(::turtle_brick_interfaces::msg::BrickLocation & msg)
  : msg_(msg)
  {}
  Init_BrickLocation_z y(::turtle_brick_interfaces::msg::BrickLocation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_BrickLocation_z(msg_);
  }

private:
  ::turtle_brick_interfaces::msg::BrickLocation msg_;
};

class Init_BrickLocation_x
{
public:
  Init_BrickLocation_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BrickLocation_y x(::turtle_brick_interfaces::msg::BrickLocation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_BrickLocation_y(msg_);
  }

private:
  ::turtle_brick_interfaces::msg::BrickLocation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::msg::BrickLocation>()
{
  return turtle_brick_interfaces::msg::builder::Init_BrickLocation_x();
}

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_LOCATION__BUILDER_HPP_
