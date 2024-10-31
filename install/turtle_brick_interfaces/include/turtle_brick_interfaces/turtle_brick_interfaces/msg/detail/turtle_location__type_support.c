// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtle_brick_interfaces:msg/TurtleLocation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtle_brick_interfaces/msg/detail/turtle_location__rosidl_typesupport_introspection_c.h"
#include "turtle_brick_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtle_brick_interfaces/msg/detail/turtle_location__functions.h"
#include "turtle_brick_interfaces/msg/detail/turtle_location__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtle_brick_interfaces__msg__TurtleLocation__init(message_memory);
}

void turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_fini_function(void * message_memory)
{
  turtle_brick_interfaces__msg__TurtleLocation__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_brick_interfaces__msg__TurtleLocation, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_brick_interfaces__msg__TurtleLocation, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_brick_interfaces__msg__TurtleLocation, theta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_message_members = {
  "turtle_brick_interfaces__msg",  // message namespace
  "TurtleLocation",  // message name
  3,  // number of fields
  sizeof(turtle_brick_interfaces__msg__TurtleLocation),
  false,  // has_any_key_member_
  turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_message_member_array,  // message members
  turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_init_function,  // function to initialize message memory (memory has to be allocated)
  turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_message_type_support_handle = {
  0,
  &turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_message_members,
  get_message_typesupport_handle_function,
  &turtle_brick_interfaces__msg__TurtleLocation__get_type_hash,
  &turtle_brick_interfaces__msg__TurtleLocation__get_type_description,
  &turtle_brick_interfaces__msg__TurtleLocation__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtle_brick_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_brick_interfaces, msg, TurtleLocation)() {
  if (!turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_message_type_support_handle.typesupport_identifier) {
    turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtle_brick_interfaces__msg__TurtleLocation__rosidl_typesupport_introspection_c__TurtleLocation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
