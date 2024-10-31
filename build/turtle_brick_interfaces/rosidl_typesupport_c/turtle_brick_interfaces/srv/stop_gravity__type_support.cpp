// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from turtle_brick_interfaces:srv/StopGravity.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "turtle_brick_interfaces/srv/detail/stop_gravity__struct.h"
#include "turtle_brick_interfaces/srv/detail/stop_gravity__type_support.h"
#include "turtle_brick_interfaces/srv/detail/stop_gravity__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace turtle_brick_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _StopGravity_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StopGravity_Request_type_support_ids_t;

static const _StopGravity_Request_type_support_ids_t _StopGravity_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StopGravity_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StopGravity_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StopGravity_Request_type_support_symbol_names_t _StopGravity_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, srv, StopGravity_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_brick_interfaces, srv, StopGravity_Request)),
  }
};

typedef struct _StopGravity_Request_type_support_data_t
{
  void * data[2];
} _StopGravity_Request_type_support_data_t;

static _StopGravity_Request_type_support_data_t _StopGravity_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StopGravity_Request_message_typesupport_map = {
  2,
  "turtle_brick_interfaces",
  &_StopGravity_Request_message_typesupport_ids.typesupport_identifier[0],
  &_StopGravity_Request_message_typesupport_symbol_names.symbol_name[0],
  &_StopGravity_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StopGravity_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StopGravity_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &turtle_brick_interfaces__srv__StopGravity_Request__get_type_hash,
  &turtle_brick_interfaces__srv__StopGravity_Request__get_type_description,
  &turtle_brick_interfaces__srv__StopGravity_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace turtle_brick_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, turtle_brick_interfaces, srv, StopGravity_Request)() {
  return &::turtle_brick_interfaces::srv::rosidl_typesupport_c::StopGravity_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/stop_gravity__struct.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/stop_gravity__type_support.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/stop_gravity__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace turtle_brick_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _StopGravity_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StopGravity_Response_type_support_ids_t;

static const _StopGravity_Response_type_support_ids_t _StopGravity_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StopGravity_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StopGravity_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StopGravity_Response_type_support_symbol_names_t _StopGravity_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, srv, StopGravity_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_brick_interfaces, srv, StopGravity_Response)),
  }
};

typedef struct _StopGravity_Response_type_support_data_t
{
  void * data[2];
} _StopGravity_Response_type_support_data_t;

static _StopGravity_Response_type_support_data_t _StopGravity_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StopGravity_Response_message_typesupport_map = {
  2,
  "turtle_brick_interfaces",
  &_StopGravity_Response_message_typesupport_ids.typesupport_identifier[0],
  &_StopGravity_Response_message_typesupport_symbol_names.symbol_name[0],
  &_StopGravity_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StopGravity_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StopGravity_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &turtle_brick_interfaces__srv__StopGravity_Response__get_type_hash,
  &turtle_brick_interfaces__srv__StopGravity_Response__get_type_description,
  &turtle_brick_interfaces__srv__StopGravity_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace turtle_brick_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, turtle_brick_interfaces, srv, StopGravity_Response)() {
  return &::turtle_brick_interfaces::srv::rosidl_typesupport_c::StopGravity_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/stop_gravity__struct.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/stop_gravity__type_support.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/stop_gravity__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace turtle_brick_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _StopGravity_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StopGravity_Event_type_support_ids_t;

static const _StopGravity_Event_type_support_ids_t _StopGravity_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StopGravity_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StopGravity_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StopGravity_Event_type_support_symbol_names_t _StopGravity_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, srv, StopGravity_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_brick_interfaces, srv, StopGravity_Event)),
  }
};

typedef struct _StopGravity_Event_type_support_data_t
{
  void * data[2];
} _StopGravity_Event_type_support_data_t;

static _StopGravity_Event_type_support_data_t _StopGravity_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StopGravity_Event_message_typesupport_map = {
  2,
  "turtle_brick_interfaces",
  &_StopGravity_Event_message_typesupport_ids.typesupport_identifier[0],
  &_StopGravity_Event_message_typesupport_symbol_names.symbol_name[0],
  &_StopGravity_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StopGravity_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StopGravity_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &turtle_brick_interfaces__srv__StopGravity_Event__get_type_hash,
  &turtle_brick_interfaces__srv__StopGravity_Event__get_type_description,
  &turtle_brick_interfaces__srv__StopGravity_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace turtle_brick_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, turtle_brick_interfaces, srv, StopGravity_Event)() {
  return &::turtle_brick_interfaces::srv::rosidl_typesupport_c::StopGravity_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "turtle_brick_interfaces/srv/detail/stop_gravity__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace turtle_brick_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _StopGravity_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StopGravity_type_support_ids_t;

static const _StopGravity_type_support_ids_t _StopGravity_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StopGravity_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StopGravity_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StopGravity_type_support_symbol_names_t _StopGravity_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtle_brick_interfaces, srv, StopGravity)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_brick_interfaces, srv, StopGravity)),
  }
};

typedef struct _StopGravity_type_support_data_t
{
  void * data[2];
} _StopGravity_type_support_data_t;

static _StopGravity_type_support_data_t _StopGravity_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StopGravity_service_typesupport_map = {
  2,
  "turtle_brick_interfaces",
  &_StopGravity_service_typesupport_ids.typesupport_identifier[0],
  &_StopGravity_service_typesupport_symbol_names.symbol_name[0],
  &_StopGravity_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t StopGravity_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StopGravity_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &StopGravity_Request_message_type_support_handle,
  &StopGravity_Response_message_type_support_handle,
  &StopGravity_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    turtle_brick_interfaces,
    srv,
    StopGravity
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    turtle_brick_interfaces,
    srv,
    StopGravity
  ),
  &turtle_brick_interfaces__srv__StopGravity__get_type_hash,
  &turtle_brick_interfaces__srv__StopGravity__get_type_description,
  &turtle_brick_interfaces__srv__StopGravity__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace turtle_brick_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, turtle_brick_interfaces, srv, StopGravity)() {
  return &::turtle_brick_interfaces::srv::rosidl_typesupport_c::StopGravity_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
