// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtle_brick_interfaces:msg/BrickDropped.idl
// generated code does not contain a copyright notice

#include "turtle_brick_interfaces/msg/detail/brick_dropped__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtle_brick_interfaces
const rosidl_type_hash_t *
turtle_brick_interfaces__msg__BrickDropped__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x16, 0x7b, 0xed, 0xdc, 0xf5, 0x8b, 0xf2, 0xb3,
      0xb3, 0x41, 0xae, 0xaa, 0x1d, 0xf3, 0xa8, 0x6c,
      0x8d, 0xbf, 0x99, 0x1f, 0xc7, 0x10, 0x33, 0xe1,
      0x28, 0x03, 0xb8, 0xc3, 0xb2, 0x94, 0x31, 0xf5,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char turtle_brick_interfaces__msg__BrickDropped__TYPE_NAME[] = "turtle_brick_interfaces/msg/BrickDropped";

// Define type names, field names, and default values
static char turtle_brick_interfaces__msg__BrickDropped__FIELD_NAME__is_dropped[] = "is_dropped";

static rosidl_runtime_c__type_description__Field turtle_brick_interfaces__msg__BrickDropped__FIELDS[] = {
  {
    {turtle_brick_interfaces__msg__BrickDropped__FIELD_NAME__is_dropped, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtle_brick_interfaces__msg__BrickDropped__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtle_brick_interfaces__msg__BrickDropped__TYPE_NAME, 40, 40},
      {turtle_brick_interfaces__msg__BrickDropped__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool is_dropped";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtle_brick_interfaces__msg__BrickDropped__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtle_brick_interfaces__msg__BrickDropped__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 15, 15},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtle_brick_interfaces__msg__BrickDropped__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtle_brick_interfaces__msg__BrickDropped__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
