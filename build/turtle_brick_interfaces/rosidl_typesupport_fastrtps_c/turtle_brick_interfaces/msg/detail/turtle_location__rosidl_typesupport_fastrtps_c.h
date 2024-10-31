// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from turtle_brick_interfaces:msg/TurtleLocation.idl
// generated code does not contain a copyright notice
#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "turtle_brick_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "turtle_brick_interfaces/msg/detail/turtle_location__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
bool cdr_serialize_turtle_brick_interfaces__msg__TurtleLocation(
  const turtle_brick_interfaces__msg__TurtleLocation * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
bool cdr_deserialize_turtle_brick_interfaces__msg__TurtleLocation(
  eprosima::fastcdr::Cdr &,
  turtle_brick_interfaces__msg__TurtleLocation * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
size_t get_serialized_size_turtle_brick_interfaces__msg__TurtleLocation(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
size_t max_serialized_size_turtle_brick_interfaces__msg__TurtleLocation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
bool cdr_serialize_key_turtle_brick_interfaces__msg__TurtleLocation(
  const turtle_brick_interfaces__msg__TurtleLocation * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
size_t get_serialized_size_key_turtle_brick_interfaces__msg__TurtleLocation(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
size_t max_serialized_size_key_turtle_brick_interfaces__msg__TurtleLocation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtle_brick_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, msg, TurtleLocation)();

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
