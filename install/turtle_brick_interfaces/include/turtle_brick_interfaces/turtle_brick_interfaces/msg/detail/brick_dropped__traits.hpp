// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_brick_interfaces:msg/BrickDropped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/brick_dropped.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_DROPPED__TRAITS_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_DROPPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_brick_interfaces/msg/detail/brick_dropped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_brick_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BrickDropped & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_dropped
  {
    out << "is_dropped: ";
    rosidl_generator_traits::value_to_yaml(msg.is_dropped, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BrickDropped & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_dropped
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_dropped: ";
    rosidl_generator_traits::value_to_yaml(msg.is_dropped, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BrickDropped & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtle_brick_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_brick_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_brick_interfaces::msg::BrickDropped & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::msg::BrickDropped & msg)
{
  return turtle_brick_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::msg::BrickDropped>()
{
  return "turtle_brick_interfaces::msg::BrickDropped";
}

template<>
inline const char * name<turtle_brick_interfaces::msg::BrickDropped>()
{
  return "turtle_brick_interfaces/msg/BrickDropped";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::msg::BrickDropped>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::msg::BrickDropped>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::msg::BrickDropped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_DROPPED__TRAITS_HPP_
