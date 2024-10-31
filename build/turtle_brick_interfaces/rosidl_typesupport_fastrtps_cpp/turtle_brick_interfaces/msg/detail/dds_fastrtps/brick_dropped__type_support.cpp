// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from turtle_brick_interfaces:msg/BrickDropped.idl
// generated code does not contain a copyright notice
#include "turtle_brick_interfaces/msg/detail/brick_dropped__rosidl_typesupport_fastrtps_cpp.hpp"
#include "turtle_brick_interfaces/msg/detail/brick_dropped__functions.h"
#include "turtle_brick_interfaces/msg/detail/brick_dropped__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace turtle_brick_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
cdr_serialize(
  const turtle_brick_interfaces::msg::BrickDropped & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: is_dropped
  cdr << (ros_message.is_dropped ? true : false);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  turtle_brick_interfaces::msg::BrickDropped & ros_message)
{
  // Member: is_dropped
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_dropped = tmp ? true : false;
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
get_serialized_size(
  const turtle_brick_interfaces::msg::BrickDropped & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: is_dropped
  {
    size_t item_size = sizeof(ros_message.is_dropped);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
max_serialized_size_BrickDropped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: is_dropped
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = turtle_brick_interfaces::msg::BrickDropped;
    is_plain =
      (
      offsetof(DataType, is_dropped) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
cdr_serialize_key(
  const turtle_brick_interfaces::msg::BrickDropped & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: is_dropped
  cdr << (ros_message.is_dropped ? true : false);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
get_serialized_size_key(
  const turtle_brick_interfaces::msg::BrickDropped & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: is_dropped
  {
    size_t item_size = sizeof(ros_message.is_dropped);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtle_brick_interfaces
max_serialized_size_key_BrickDropped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: is_dropped
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = turtle_brick_interfaces::msg::BrickDropped;
    is_plain =
      (
      offsetof(DataType, is_dropped) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _BrickDropped__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const turtle_brick_interfaces::msg::BrickDropped *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BrickDropped__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<turtle_brick_interfaces::msg::BrickDropped *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BrickDropped__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const turtle_brick_interfaces::msg::BrickDropped *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BrickDropped__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_BrickDropped(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _BrickDropped__callbacks = {
  "turtle_brick_interfaces::msg",
  "BrickDropped",
  _BrickDropped__cdr_serialize,
  _BrickDropped__cdr_deserialize,
  _BrickDropped__get_serialized_size,
  _BrickDropped__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _BrickDropped__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BrickDropped__callbacks,
  get_message_typesupport_handle_function,
  &turtle_brick_interfaces__msg__BrickDropped__get_type_hash,
  &turtle_brick_interfaces__msg__BrickDropped__get_type_description,
  &turtle_brick_interfaces__msg__BrickDropped__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace turtle_brick_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_turtle_brick_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<turtle_brick_interfaces::msg::BrickDropped>()
{
  return &turtle_brick_interfaces::msg::typesupport_fastrtps_cpp::_BrickDropped__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtle_brick_interfaces, msg, BrickDropped)() {
  return &turtle_brick_interfaces::msg::typesupport_fastrtps_cpp::_BrickDropped__handle;
}

#ifdef __cplusplus
}
#endif