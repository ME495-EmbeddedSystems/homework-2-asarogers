// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_brick_interfaces:srv/StopGravity.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/srv/stop_gravity.hpp"


#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__BUILDER_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_brick_interfaces/srv/detail/stop_gravity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_StopGravity_Request_stopped
{
public:
  Init_StopGravity_Request_stopped()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_brick_interfaces::srv::StopGravity_Request stopped(::turtle_brick_interfaces::srv::StopGravity_Request::_stopped_type arg)
  {
    msg_.stopped = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::StopGravity_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::StopGravity_Request>()
{
  return turtle_brick_interfaces::srv::builder::Init_StopGravity_Request_stopped();
}

}  // namespace turtle_brick_interfaces


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_StopGravity_Response_success
{
public:
  Init_StopGravity_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_brick_interfaces::srv::StopGravity_Response success(::turtle_brick_interfaces::srv::StopGravity_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::StopGravity_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::StopGravity_Response>()
{
  return turtle_brick_interfaces::srv::builder::Init_StopGravity_Response_success();
}

}  // namespace turtle_brick_interfaces


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_StopGravity_Event_response
{
public:
  explicit Init_StopGravity_Event_response(::turtle_brick_interfaces::srv::StopGravity_Event & msg)
  : msg_(msg)
  {}
  ::turtle_brick_interfaces::srv::StopGravity_Event response(::turtle_brick_interfaces::srv::StopGravity_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::StopGravity_Event msg_;
};

class Init_StopGravity_Event_request
{
public:
  explicit Init_StopGravity_Event_request(::turtle_brick_interfaces::srv::StopGravity_Event & msg)
  : msg_(msg)
  {}
  Init_StopGravity_Event_response request(::turtle_brick_interfaces::srv::StopGravity_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_StopGravity_Event_response(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::StopGravity_Event msg_;
};

class Init_StopGravity_Event_info
{
public:
  Init_StopGravity_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StopGravity_Event_request info(::turtle_brick_interfaces::srv::StopGravity_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_StopGravity_Event_request(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::StopGravity_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::StopGravity_Event>()
{
  return turtle_brick_interfaces::srv::builder::Init_StopGravity_Event_info();
}

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__BUILDER_HPP_
