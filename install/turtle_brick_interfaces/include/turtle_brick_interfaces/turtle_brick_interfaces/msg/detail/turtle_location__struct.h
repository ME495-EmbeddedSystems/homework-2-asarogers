// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_brick_interfaces:msg/TurtleLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/turtle_location.h"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__STRUCT_H_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/TurtleLocation in the package turtle_brick_interfaces.
typedef struct turtle_brick_interfaces__msg__TurtleLocation
{
  double x;
  double y;
  double theta;
} turtle_brick_interfaces__msg__TurtleLocation;

// Struct for a sequence of turtle_brick_interfaces__msg__TurtleLocation.
typedef struct turtle_brick_interfaces__msg__TurtleLocation__Sequence
{
  turtle_brick_interfaces__msg__TurtleLocation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_brick_interfaces__msg__TurtleLocation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__STRUCT_H_
