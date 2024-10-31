// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_brick_interfaces:msg/BrickDropped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_brick_interfaces/msg/brick_dropped.hpp"


#ifndef TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_DROPPED__STRUCT_HPP_
#define TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_DROPPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtle_brick_interfaces__msg__BrickDropped __attribute__((deprecated))
#else
# define DEPRECATED__turtle_brick_interfaces__msg__BrickDropped __declspec(deprecated)
#endif

namespace turtle_brick_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BrickDropped_
{
  using Type = BrickDropped_<ContainerAllocator>;

  explicit BrickDropped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_dropped = false;
    }
  }

  explicit BrickDropped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_dropped = false;
    }
  }

  // field types and members
  using _is_dropped_type =
    bool;
  _is_dropped_type is_dropped;

  // setters for named parameter idiom
  Type & set__is_dropped(
    const bool & _arg)
  {
    this->is_dropped = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_brick_interfaces__msg__BrickDropped
    std::shared_ptr<turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_brick_interfaces__msg__BrickDropped
    std::shared_ptr<turtle_brick_interfaces::msg::BrickDropped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BrickDropped_ & other) const
  {
    if (this->is_dropped != other.is_dropped) {
      return false;
    }
    return true;
  }
  bool operator!=(const BrickDropped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BrickDropped_

// alias to use template instance with default allocator
using BrickDropped =
  turtle_brick_interfaces::msg::BrickDropped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtle_brick_interfaces

#endif  // TURTLE_BRICK_INTERFACES__MSG__DETAIL__BRICK_DROPPED__STRUCT_HPP_
