// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_brick_interfaces:msg/TurtleLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/turtle_location.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__STRUCT_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtle_brick_interfaces__msg__TurtleLocation __attribute__((deprecated))
#else
# define DEPRECATED__turtle_brick_interfaces__msg__TurtleLocation __declspec(deprecated)
#endif

namespace turtle_brick_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TurtleLocation_
{
  using Type = TurtleLocation_<ContainerAllocator>;

  explicit TurtleLocation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
    }
  }

  explicit TurtleLocation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _theta_type =
    double;
  _theta_type theta;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const double & _arg)
  {
    this->theta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_brick_interfaces__msg__TurtleLocation
    std::shared_ptr<turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_brick_interfaces__msg__TurtleLocation
    std::shared_ptr<turtle_brick_interfaces::msg::TurtleLocation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurtleLocation_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurtleLocation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurtleLocation_

// alias to use template instance with default allocator
using TurtleLocation =
  turtle_brick_interfaces::msg::TurtleLocation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__TURTLE_LOCATION__STRUCT_HPP_