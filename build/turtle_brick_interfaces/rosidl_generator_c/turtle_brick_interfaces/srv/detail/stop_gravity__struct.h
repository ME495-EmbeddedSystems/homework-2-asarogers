// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_brick_interfaces:srv/StopGravity.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/srv/stop_gravity.h"


#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__STRUCT_H_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/StopGravity in the package turtle_brick_interfaces.
typedef struct turtle_brick_interfaces__srv__StopGravity_Request
{
  bool stopped;
} turtle_brick_interfaces__srv__StopGravity_Request;

// Struct for a sequence of turtle_brick_interfaces__srv__StopGravity_Request.
typedef struct turtle_brick_interfaces__srv__StopGravity_Request__Sequence
{
  turtle_brick_interfaces__srv__StopGravity_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_brick_interfaces__srv__StopGravity_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/StopGravity in the package turtle_brick_interfaces.
typedef struct turtle_brick_interfaces__srv__StopGravity_Response
{
  bool success;
} turtle_brick_interfaces__srv__StopGravity_Response;

// Struct for a sequence of turtle_brick_interfaces__srv__StopGravity_Response.
typedef struct turtle_brick_interfaces__srv__StopGravity_Response__Sequence
{
  turtle_brick_interfaces__srv__StopGravity_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_brick_interfaces__srv__StopGravity_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  turtle_brick_interfaces__srv__StopGravity_Event__request__MAX_SIZE = 1
};
// response
enum
{
  turtle_brick_interfaces__srv__StopGravity_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/StopGravity in the package turtle_brick_interfaces.
typedef struct turtle_brick_interfaces__srv__StopGravity_Event
{
  service_msgs__msg__ServiceEventInfo info;
  turtle_brick_interfaces__srv__StopGravity_Request__Sequence request;
  turtle_brick_interfaces__srv__StopGravity_Response__Sequence response;
} turtle_brick_interfaces__srv__StopGravity_Event;

// Struct for a sequence of turtle_brick_interfaces__srv__StopGravity_Event.
typedef struct turtle_brick_interfaces__srv__StopGravity_Event__Sequence
{
  turtle_brick_interfaces__srv__StopGravity_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_brick_interfaces__srv__StopGravity_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__STRUCT_H_
