// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_brick_interfaces:srv/ProvideGoalPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/srv/provide_goal_pose.hpp"


#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__PROVIDE_GOAL_POSE__BUILDER_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__PROVIDE_GOAL_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_brick_interfaces/srv/detail/provide_goal_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_ProvideGoalPose_Request_goal_pose
{
public:
  Init_ProvideGoalPose_Request_goal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_brick_interfaces::srv::ProvideGoalPose_Request goal_pose(::turtle_brick_interfaces::srv::ProvideGoalPose_Request::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::ProvideGoalPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::ProvideGoalPose_Request>()
{
  return turtle_brick_interfaces::srv::builder::Init_ProvideGoalPose_Request_goal_pose();
}

}  // namespace turtle_brick_interfaces


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_ProvideGoalPose_Response_success
{
public:
  Init_ProvideGoalPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_brick_interfaces::srv::ProvideGoalPose_Response success(::turtle_brick_interfaces::srv::ProvideGoalPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::ProvideGoalPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::ProvideGoalPose_Response>()
{
  return turtle_brick_interfaces::srv::builder::Init_ProvideGoalPose_Response_success();
}

}  // namespace turtle_brick_interfaces


namespace turtle_brick_interfaces
{

namespace srv
{

namespace builder
{

class Init_ProvideGoalPose_Event_response
{
public:
  explicit Init_ProvideGoalPose_Event_response(::turtle_brick_interfaces::srv::ProvideGoalPose_Event & msg)
  : msg_(msg)
  {}
  ::turtle_brick_interfaces::srv::ProvideGoalPose_Event response(::turtle_brick_interfaces::srv::ProvideGoalPose_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::ProvideGoalPose_Event msg_;
};

class Init_ProvideGoalPose_Event_request
{
public:
  explicit Init_ProvideGoalPose_Event_request(::turtle_brick_interfaces::srv::ProvideGoalPose_Event & msg)
  : msg_(msg)
  {}
  Init_ProvideGoalPose_Event_response request(::turtle_brick_interfaces::srv::ProvideGoalPose_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ProvideGoalPose_Event_response(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::ProvideGoalPose_Event msg_;
};

class Init_ProvideGoalPose_Event_info
{
public:
  Init_ProvideGoalPose_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProvideGoalPose_Event_request info(::turtle_brick_interfaces::srv::ProvideGoalPose_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ProvideGoalPose_Event_request(msg_);
  }

private:
  ::turtle_brick_interfaces::srv::ProvideGoalPose_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_brick_interfaces::srv::ProvideGoalPose_Event>()
{
  return turtle_brick_interfaces::srv::builder::Init_ProvideGoalPose_Event_info();
}

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__PROVIDE_GOAL_POSE__BUILDER_HPP_
