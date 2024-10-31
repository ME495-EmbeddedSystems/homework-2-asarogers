// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtle_brick_interfaces:msg/BrickLocation.idl
// generated code does not contain a copyright notice

#include "turtle_brick_interfaces/msg/detail/brick_location__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtle_brick_interfaces
const rosidl_type_hash_t *
turtle_brick_interfaces__msg__BrickLocation__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa4, 0xb2, 0x6c, 0x25, 0x72, 0x08, 0x66, 0x31,
      0xc5, 0x24, 0x96, 0x2b, 0x70, 0xa4, 0x60, 0x95,
      0x74, 0x2b, 0x83, 0xb3, 0x71, 0xec, 0xda, 0xbf,
      0xb9, 0xb6, 0x4c, 0x05, 0x27, 0x73, 0x68, 0x77,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char turtle_brick_interfaces__msg__BrickLocation__TYPE_NAME[] = "turtle_brick_interfaces/msg/BrickLocation";

// Define type names, field names, and default values
static char turtle_brick_interfaces__msg__BrickLocation__FIELD_NAME__x[] = "x";
static char turtle_brick_interfaces__msg__BrickLocation__FIELD_NAME__y[] = "y";
static char turtle_brick_interfaces__msg__BrickLocation__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field turtle_brick_interfaces__msg__BrickLocation__FIELDS[] = {
  {
    {turtle_brick_interfaces__msg__BrickLocation__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtle_brick_interfaces__msg__BrickLocation__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtle_brick_interfaces__msg__BrickLocation__FIELD_NAME__z, 1, 1},
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
turtle_brick_interfaces__msg__BrickLocation__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtle_brick_interfaces__msg__BrickLocation__TYPE_NAME, 41, 41},
      {turtle_brick_interfaces__msg__BrickLocation__FIELDS, 3, 3},
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
  "float64 z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtle_brick_interfaces__msg__BrickLocation__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtle_brick_interfaces__msg__BrickLocation__TYPE_NAME, 41, 41},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtle_brick_interfaces__msg__BrickLocation__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtle_brick_interfaces__msg__BrickLocation__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
