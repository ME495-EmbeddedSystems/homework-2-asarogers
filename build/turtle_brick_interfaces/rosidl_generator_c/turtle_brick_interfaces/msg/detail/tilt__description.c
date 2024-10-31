// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtle_brick_interfaces:msg/Tilt.idl
// generated code does not contain a copyright notice

#include "turtle_brick_interfaces/msg/detail/tilt__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtle_brick_interfaces
const rosidl_type_hash_t *
turtle_brick_interfaces__msg__Tilt__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbb, 0x6f, 0x66, 0x41, 0xf4, 0xa0, 0xd7, 0xa9,
      0xac, 0xa9, 0xf1, 0xe6, 0x3c, 0x36, 0xaa, 0x8a,
      0xe5, 0x7f, 0x21, 0x81, 0xb4, 0x4b, 0xf7, 0xb4,
      0xc8, 0x3c, 0x13, 0x64, 0x17, 0xcc, 0x8a, 0x05,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char turtle_brick_interfaces__msg__Tilt__TYPE_NAME[] = "turtle_brick_interfaces/msg/Tilt";

// Define type names, field names, and default values
static char turtle_brick_interfaces__msg__Tilt__FIELD_NAME__tilt[] = "tilt";

static rosidl_runtime_c__type_description__Field turtle_brick_interfaces__msg__Tilt__FIELDS[] = {
  {
    {turtle_brick_interfaces__msg__Tilt__FIELD_NAME__tilt, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtle_brick_interfaces__msg__Tilt__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtle_brick_interfaces__msg__Tilt__TYPE_NAME, 32, 32},
      {turtle_brick_interfaces__msg__Tilt__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 tilt";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtle_brick_interfaces__msg__Tilt__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtle_brick_interfaces__msg__Tilt__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 13, 13},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtle_brick_interfaces__msg__Tilt__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtle_brick_interfaces__msg__Tilt__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
