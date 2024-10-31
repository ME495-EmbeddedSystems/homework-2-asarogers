// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_brick_interfaces:srv/StopGravity.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/srv/stop_gravity.hpp"


#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__TRAITS_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_brick_interfaces/srv/detail/stop_gravity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_brick_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StopGravity_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: stopped
  {
    out << "stopped: ";
    rosidl_generator_traits::value_to_yaml(msg.stopped, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StopGravity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stopped
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stopped: ";
    rosidl_generator_traits::value_to_yaml(msg.stopped, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StopGravity_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_brick_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_brick_interfaces::srv::StopGravity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::srv::StopGravity_Request & msg)
{
  return turtle_brick_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::srv::StopGravity_Request>()
{
  return "turtle_brick_interfaces::srv::StopGravity_Request";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::StopGravity_Request>()
{
  return "turtle_brick_interfaces/srv/StopGravity_Request";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::StopGravity_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::StopGravity_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::srv::StopGravity_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace turtle_brick_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StopGravity_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StopGravity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StopGravity_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_brick_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_brick_interfaces::srv::StopGravity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::srv::StopGravity_Response & msg)
{
  return turtle_brick_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::srv::StopGravity_Response>()
{
  return "turtle_brick_interfaces::srv::StopGravity_Response";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::StopGravity_Response>()
{
  return "turtle_brick_interfaces/srv/StopGravity_Response";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::StopGravity_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::StopGravity_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_brick_interfaces::srv::StopGravity_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace turtle_brick_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StopGravity_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StopGravity_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StopGravity_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_brick_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_brick_interfaces::srv::StopGravity_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_brick_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_brick_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtle_brick_interfaces::srv::StopGravity_Event & msg)
{
  return turtle_brick_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_brick_interfaces::srv::StopGravity_Event>()
{
  return "turtle_brick_interfaces::srv::StopGravity_Event";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::StopGravity_Event>()
{
  return "turtle_brick_interfaces/srv/StopGravity_Event";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::StopGravity_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::StopGravity_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<turtle_brick_interfaces::srv::StopGravity_Request>::value && has_bounded_size<turtle_brick_interfaces::srv::StopGravity_Response>::value> {};

template<>
struct is_message<turtle_brick_interfaces::srv::StopGravity_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turtle_brick_interfaces::srv::StopGravity>()
{
  return "turtle_brick_interfaces::srv::StopGravity";
}

template<>
inline const char * name<turtle_brick_interfaces::srv::StopGravity>()
{
  return "turtle_brick_interfaces/srv/StopGravity";
}

template<>
struct has_fixed_size<turtle_brick_interfaces::srv::StopGravity>
  : std::integral_constant<
    bool,
    has_fixed_size<turtle_brick_interfaces::srv::StopGravity_Request>::value &&
    has_fixed_size<turtle_brick_interfaces::srv::StopGravity_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtle_brick_interfaces::srv::StopGravity>
  : std::integral_constant<
    bool,
    has_bounded_size<turtle_brick_interfaces::srv::StopGravity_Request>::value &&
    has_bounded_size<turtle_brick_interfaces::srv::StopGravity_Response>::value
  >
{
};

template<>
struct is_service<turtle_brick_interfaces::srv::StopGravity>
  : std::true_type
{
};

template<>
struct is_service_request<turtle_brick_interfaces::srv::StopGravity_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtle_brick_interfaces::srv::StopGravity_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__TRAITS_HPP_
