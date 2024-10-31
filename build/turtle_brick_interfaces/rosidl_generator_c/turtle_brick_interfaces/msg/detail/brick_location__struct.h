// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_brick_interfaces:msg/BrickLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/brick_location.h"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_LOCATION__STRUCT_H_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_LOCATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/BrickLocation in the package turtle_brick_interfaces.
typedef struct turtle_brick_interfaces__msg__BrickLocation
{
  double x;
  double y;
  double z;
} turtle_brick_interfaces__msg__BrickLocation;

// Struct for a sequence of turtle_brick_interfaces__msg__BrickLocation.
typedef struct turtle_brick_interfaces__msg__BrickLocation__Sequence
{
  turtle_brick_interfaces__msg__BrickLocation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_brick_interfaces__msg__BrickLocation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_LOCATION__STRUCT_H_
