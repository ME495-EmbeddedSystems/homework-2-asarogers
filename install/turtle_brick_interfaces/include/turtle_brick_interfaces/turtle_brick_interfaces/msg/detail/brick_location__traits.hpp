// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_brick_interfaces:msg/BrickLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/brick_location.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_LOCATION__TRAITS_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_LOCATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_brick_interfaces/msg/detail/brick_location__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_brick_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BrickLocation & msg,
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

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BrickLocation & msg,
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

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BrickLocation & msg, bool use_flow_style = false)
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
  const turtle_brick_interfaces::msg::BrickLocation & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::msg::BrickLocation & msg)
{
  return turtle_brick_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::msg::BrickLocation>()
{
  return "turtle_brick_interfaces::msg::BrickLocation";
}

template<>
inline const char * name<turtle_brick_interfaces::msg::BrickLocation>()
{
  return "turtle_brick_interfaces/msg/BrickLocation";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::msg::BrickLocation>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::msg::BrickLocation>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::msg::BrickLocation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_LOCATION__TRAITS_HPP_
