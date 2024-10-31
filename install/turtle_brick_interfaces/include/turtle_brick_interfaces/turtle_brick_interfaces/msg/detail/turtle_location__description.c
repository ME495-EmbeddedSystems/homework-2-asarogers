// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtle_brick_interfaces:msg/TurtleLocation.idl
// generated code does not contain a copyright notice

#include "turtle_brick_interfaces/msg/detail/turtle_location__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtle_brick_interfaces
const rosidl_type_hash_t *
turtle_brick_interfaces__msg__TurtleLocation__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1c, 0x27, 0x8e, 0xc4, 0xb9, 0xa1, 0xc9, 0x23,
      0xf3, 0x7b, 0x99, 0x00, 0xb6, 0xae, 0xac, 0xc9,
      0xac, 0x2f, 0xbc, 0x6a, 0x14, 0x88, 0xce, 0x43,
      0xf1, 0x3a, 0xbc, 0xf4, 0x37, 0xa3, 0x30, 0xe6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char turtle_brick_interfaces__msg__TurtleLocation__TYPE_NAME[] = "turtle_brick_interfaces/msg/TurtleLocation";

// Define type names, field names, and default values
static char turtle_brick_interfaces__msg__TurtleLocation__FIELD_NAME__x[] = "x";
static char turtle_brick_interfaces__msg__TurtleLocation__FIELD_NAME__y[] = "y";
static char turtle_brick_interfaces__msg__TurtleLocation__FIELD_NAME__theta[] = "theta";

static rosidl_runtime_c__type_description__Field turtle_brick_interfaces__msg__TurtleLocation__FIELDS[] = {
  {
    {turtle_brick_interfaces__msg__TurtleLocation__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtle_brick_interfaces__msg__TurtleLocation__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtle_brick_interfaces__msg__TurtleLocation__FIELD_NAME__theta, 5, 5},
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
turtle_brick_interfaces__msg__TurtleLocation__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtle_brick_interfaces__msg__TurtleLocation__TYPE_NAME, 42, 42},
      {turtle_brick_interfaces__msg__TurtleLocation__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y\n"
  "float64 theta";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtle_brick_interfaces__msg__TurtleLocation__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtle_brick_interfaces__msg__TurtleLocation__TYPE_NAME, 42, 42},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 33, 33},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtle_brick_interfaces__msg__TurtleLocation__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtle_brick_interfaces__msg__TurtleLocation__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
