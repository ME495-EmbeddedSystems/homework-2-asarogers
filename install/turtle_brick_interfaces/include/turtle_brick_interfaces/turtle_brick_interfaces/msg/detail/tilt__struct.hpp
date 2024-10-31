// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_brick_interfaces:msg/Tilt.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/tilt.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__STRUCT_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtle_brick_interfaces__msg__Tilt __attribute__((deprecated))
#else
# define DEPRECATED__turtle_brick_interfaces__msg__Tilt __declspec(deprecated)
#endif

namespace turtle_brick_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Tilt_
{
  using Type = Tilt_<ContainerAllocator>;

  explicit Tilt_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tilt = 0.0;
    }
  }

  explicit Tilt_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tilt = 0.0;
    }
  }

  // field types and members
  using _tilt_type =
    double;
  _tilt_type tilt;

  // setters for named parameter idiom
  Type & set__tilt(
    const double & _arg)
  {
    this->tilt = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_brick_interfaces::msg::Tilt_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_brick_interfaces::msg::Tilt_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_brick_interfaces::msg::Tilt_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_brick_interfaces::msg::Tilt_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::msg::Tilt_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::msg::Tilt_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::msg::Tilt_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::msg::Tilt_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_brick_interfaces::msg::Tilt_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_brick_interfaces::msg::Tilt_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_brick_interfaces__msg__Tilt
    std::shared_ptr<turtle_brick_interfaces::msg::Tilt_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_brick_interfaces__msg__Tilt
    std::shared_ptr<turtle_brick_interfaces::msg::Tilt_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Tilt_ & other) const
  {
    if (this->tilt != other.tilt) {
      return false;
    }
    return true;
  }
  bool operator!=(const Tilt_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Tilt_

// alias to use template instance with default allocator
using Tilt =
  turtle_brick_interfaces::msg::Tilt_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TILT__STRUCT_HPP_
