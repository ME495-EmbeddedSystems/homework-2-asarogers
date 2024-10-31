// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from turtle_brick_interfaces:msg/BrickDropped.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "turtle_brick_interfaces/msg/detail/brick_dropped__functions.h"
#include "turtle_brick_interfaces/msg/detail/brick_dropped__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace turtle_brick_interfaces
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _BrickDropped_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _BrickDropped_type_support_ids_t;

static const _BrickDropped_type_support_ids_t _BrickDropped_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _BrickDropped_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _BrickDropped_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _BrickDropped_type_support_symbol_names_t _BrickDropped_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtle_brick_interfaces, msg, BrickDropped)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, turtle_brick_interfaces, msg, BrickDropped)),
  }
};

typedef struct _BrickDropped_type_support_data_t
{
  void * data[2];
} _BrickDropped_type_support_data_t;

static _BrickDropped_type_support_data_t _BrickDropped_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _BrickDropped_message_typesupport_map = {
  2,
  "turtle_brick_interfaces",
  &_BrickDropped_message_typesupport_ids.typesupport_identifier[0],
  &_BrickDropped_message_typesupport_symbol_names.symbol_name[0],
  &_BrickDropped_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t BrickDropped_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_BrickDropped_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &turtle_brick_interfaces__msg__BrickDropped__get_type_hash,
  &turtle_brick_interfaces__msg__BrickDropped__get_type_description,
  &turtle_brick_interfaces__msg__BrickDropped__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace turtle_brick_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<turtle_brick_interfaces::msg::BrickDropped>()
{
  return &::turtle_brick_interfaces::msg::rosidl_typesupport_cpp::BrickDropped_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, turtle_brick_interfaces, msg, BrickDropped)() {
  return get_message_type_support_handle<turtle_brick_interfaces::msg::BrickDropped>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
