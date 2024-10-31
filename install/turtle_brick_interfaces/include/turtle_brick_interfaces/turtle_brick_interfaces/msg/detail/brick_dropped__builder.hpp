// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_brick_interfaces:msg/BrickDropped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/brick_dropped.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_DROPPED__BUILDER_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_DROPPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_brick_interfaces/msg/detail/brick_dropped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_brick_interfaces
{

namespace msg
{

namespace builder
{

class Init_BrickDropped_is_dropped
{
public:
  Init_BrickDropped_is_dropped()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_brick_interfaces::msg::BrickDropped is_dropped(::turtle_brick_interfaces::msg::BrickDropped::_is_dropped_type arg)
  {
    msg_.is_dropped = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::msg::BrickDropped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::msg::BrickDropped>()
{
  return turtle_brick_interfaces::msg::builder::Init_BrickDropped_is_dropped();
}

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_DROPPED__BUILDER_HPP_
