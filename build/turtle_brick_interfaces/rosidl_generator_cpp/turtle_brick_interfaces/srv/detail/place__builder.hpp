// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_brick_interfaces:srv/Place.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/srv/place.hpp"


#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__PLACE__BUILDER_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__PLACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_brick_interfaces/srv/detail/place__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_Place_Request_z
{
public:
  explicit Init_Place_Request_z(::turtle_brick_interfaces::srv::Place_Request & msg)
  : msg_(msg)
  {}
  ::turtle_brick_interfaces::srv::Place_Request z(::turtle_brick_interfaces::srv::Place_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Request msg_;
};

class Init_Place_Request_y
{
public:
  explicit Init_Place_Request_y(::turtle_brick_interfaces::srv::Place_Request & msg)
  : msg_(msg)
  {}
  Init_Place_Request_z y(::turtle_brick_interfaces::srv::Place_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Place_Request_z(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Request msg_;
};

class Init_Place_Request_x
{
public:
  Init_Place_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Place_Request_y x(::turtle_brick_interfaces::srv::Place_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Place_Request_y(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::Place_Request>()
{
  return turtle_brick_interfaces::srv::builder::Init_Place_Request_x();
}

}  // namespace turtle_brick_interfaces


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_Place_Response_message
{
public:
  explicit Init_Place_Response_message(::turtle_brick_interfaces::srv::Place_Response & msg)
  : msg_(msg)
  {}
  ::turtle_brick_interfaces::srv::Place_Response message(::turtle_brick_interfaces::srv::Place_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Response msg_;
};

class Init_Place_Response_success
{
public:
  Init_Place_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Place_Response_message success(::turtle_brick_interfaces::srv::Place_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Place_Response_message(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::Place_Response>()
{
  return turtle_brick_interfaces::srv::builder::Init_Place_Response_success();
}

}  // namespace turtle_brick_interfaces


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_Place_Event_response
{
public:
  explicit Init_Place_Event_response(::turtle_brick_interfaces::srv::Place_Event & msg)
  : msg_(msg)
  {}
  ::turtle_brick_interfaces::srv::Place_Event response(::turtle_brick_interfaces::srv::Place_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Event msg_;
};

class Init_Place_Event_request
{
public:
  explicit Init_Place_Event_request(::turtle_brick_interfaces::srv::Place_Event & msg)
  : msg_(msg)
  {}
  Init_Place_Event_response request(::turtle_brick_interfaces::srv::Place_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Place_Event_response(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Event msg_;
};

class Init_Place_Event_info
{
public:
  Init_Place_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Place_Event_request info(::turtle_brick_interfaces::srv::Place_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Place_Event_request(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::Place_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::Place_Event>()
{
  return turtle_brick_interfaces::srv::builder::Init_Place_Event_info();
}

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__PLACE__BUILDER_HPP_
