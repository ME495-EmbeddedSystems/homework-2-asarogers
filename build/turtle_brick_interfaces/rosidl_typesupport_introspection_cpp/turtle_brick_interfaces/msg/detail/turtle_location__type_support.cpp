// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from turtle_brick_interfaces:msg/TurtleLocation.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "turtle_brick_interfaces/msg/detail/turtle_location__functions.h"
#include "turtle_brick_interfaces/msg/detail/turtle_location__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace turtle_brick_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TurtleLocation_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) turtle_brick_interfaces::msg::TurtleLocation(_init);
}

void TurtleLocation_fini_function(void * message_memory)
{
  auto typed_message = static_cast<turtle_brick_interfaces::msg::TurtleLocation *>(message_memory);
  typed_message->~TurtleLocation();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TurtleLocation_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_brick_interfaces::msg::TurtleLocation, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_brick_interfaces::msg::TurtleLocation, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "theta",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_brick_interfaces::msg::TurtleLocation, theta),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TurtleLocation_message_members = {
  "turtle_brick_interfaces::msg",  // message namespace
  "TurtleLocation",  // message name
  3,  // number of fields
  sizeof(turtle_brick_interfaces::msg::TurtleLocation),
  false,  // has_any_key_member_
  TurtleLocation_message_member_array,  // message members
  TurtleLocation_init_function,  // function to initialize message memory (memory has to be allocated)
  TurtleLocation_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TurtleLocation_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TurtleLocation_message_members,
  get_message_typesupport_handle_function,
  &turtle_brick_interfaces__msg__TurtleLocation__get_type_hash,
  &turtle_brick_interfaces__msg__TurtleLocation__get_type_description,
  &turtle_brick_interfaces__msg__TurtleLocation__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace turtle_brick_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<turtle_brick_interfaces::msg::TurtleLocation>()
{
  return &::turtle_brick_interfaces::msg::rosidl_typesupport_introspection_cpp::TurtleLocation_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, turtle_brick_interfaces, msg, TurtleLocation)() {
  return &::turtle_brick_interfaces::msg::rosidl_typesupport_introspection_cpp::TurtleLocation_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
