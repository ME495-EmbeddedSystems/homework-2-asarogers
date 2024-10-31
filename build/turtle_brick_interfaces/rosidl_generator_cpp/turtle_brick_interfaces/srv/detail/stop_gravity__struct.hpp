// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_brick_interfaces:srv/StopGravity.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/srv/stop_gravity.hpp"


#ifndef TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__STRUCT_HPP_
#define TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Request __attribute__((deprecated))
#else
# define DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Request __declspec(deprecated)
#endif

namespace turtle_brick_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StopGravity_Request_
{
  using Type = StopGravity_Request_<ContainerAllocator>;

  explicit StopGravity_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stopped = false;
    }
  }

  explicit StopGravity_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stopped = false;
    }
  }

  // field types and members
  using _stopped_type =
    bool;
  _stopped_type stopped;

  // setters for named parameter idiom
  Type & set__stopped(
    const bool & _arg)
  {
    this->stopped = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Request
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Request
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StopGravity_Request_ & other) const
  {
    if (this->stopped != other.stopped) {
      return false;
    }
    return true;
  }
  bool operator!=(const StopGravity_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StopGravity_Request_

// alias to use template instance with default allocator
using StopGravity_Request =
  turtle_brick_interfaces::srv::StopGravity_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_brick_interfaces


#ifndef _WIN32
# define DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Response __attribute__((deprecated))
#else
# define DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Response __declspec(deprecated)
#endif

namespace turtle_brick_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StopGravity_Response_
{
  using Type = StopGravity_Response_<ContainerAllocator>;

  explicit StopGravity_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit StopGravity_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Response
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Response
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StopGravity_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const StopGravity_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StopGravity_Response_

// alias to use template instance with default allocator
using StopGravity_Response =
  turtle_brick_interfaces::srv::StopGravity_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_brick_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Event __attribute__((deprecated))
#else
# define DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Event __declspec(deprecated)
#endif

namespace turtle_brick_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StopGravity_Event_
{
  using Type = StopGravity_Event_<ContainerAllocator>;

  explicit StopGravity_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit StopGravity_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<turtle_brick_interfaces::srv::StopGravity_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<turtle_brick_interfaces::srv::StopGravity_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Event
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_brick_interfaces__srv__StopGravity_Event
    std::shared_ptr<turtle_brick_interfaces::srv::StopGravity_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StopGravity_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const StopGravity_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StopGravity_Event_

// alias to use template instance with default allocator
using StopGravity_Event =
  turtle_brick_interfaces::srv::StopGravity_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_brick_interfaces

namespace turtle_brick_interfaces
{

namespace srv
{

struct StopGravity
{
  using Request = turtle_brick_interfaces::srv::StopGravity_Request;
  using Response = turtle_brick_interfaces::srv::StopGravity_Response;
  using Event = turtle_brick_interfaces::srv::StopGravity_Event;
};

}  // namespace srv

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__SRV__DETAIL__STOP_GRAVITY__STRUCT_HPP_