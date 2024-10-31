// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_brick_interfaces:msg/TurtleLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/turtle_location.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__TRAITS_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_brick_interfaces/msg/detail/turtle_location__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_brick_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TurtleLocation & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TurtleLocation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TurtleLocation & msg, bool use_flow_style = false)
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
  const turtle_brick_interfaces::msg::TurtleLocation & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::msg::TurtleLocation & msg)
{
  return turtle_brick_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::msg::TurtleLocation>()
{
  return "turtle_brick_interfaces::msg::TurtleLocation";
}

template<>
inline const char * name<turtle_brick_interfaces::msg::TurtleLocation>()
{
  return "turtle_brick_interfaces/msg/TurtleLocation";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::msg::TurtleLocation>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::msg::TurtleLocation>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::msg::TurtleLocation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__TRAITS_HPP_