// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtle_brick_interfaces:msg/BrickDropped.idl
// generated code does not contain a copyright notice
#include "turtle_brick_interfaces/msg/detail/brick_dropped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
turtle_brick_interfaces__msg__BrickDropped__init(turtle_brick_interfaces__msg__BrickDropped * msg)
{
  if (!msg) {
    return false;
  }
  // is_dropped
  return true;
}

void
turtle_brick_interfaces__msg__BrickDropped__fini(turtle_brick_interfaces__msg__BrickDropped * msg)
{
  if (!msg) {
    return;
  }
  // is_dropped
}

bool
turtle_brick_interfaces__msg__BrickDropped__are_equal(const turtle_brick_interfaces__msg__BrickDropped * lhs, const turtle_brick_interfaces__msg__BrickDropped * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_dropped
  if (lhs->is_dropped != rhs->is_dropped) {
    return false;
  }
  return true;
}

bool
turtle_brick_interfaces__msg__BrickDropped__copy(
  const turtle_brick_interfaces__msg__BrickDropped * input,
  turtle_brick_interfaces__msg__BrickDropped * output)
{
  if (!input || !output) {
    return false;
  }
  // is_dropped
  output->is_dropped = input->is_dropped;
  return true;
}

turtle_brick_interfaces__msg__BrickDropped *
turtle_brick_interfaces__msg__BrickDropped__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__msg__BrickDropped * msg = (turtle_brick_interfaces__msg__BrickDropped *)allocator.allocate(sizeof(turtle_brick_interfaces__msg__BrickDropped), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_brick_interfaces__msg__BrickDropped));
  bool success = turtle_brick_interfaces__msg__BrickDropped__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_brick_interfaces__msg__BrickDropped__destroy(turtle_brick_interfaces__msg__BrickDropped * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_brick_interfaces__msg__BrickDropped__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_brick_interfaces__msg__BrickDropped__Sequence__init(turtle_brick_interfaces__msg__BrickDropped__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__msg__BrickDropped * data = NULL;

  if (size) {
    data = (turtle_brick_interfaces__msg__BrickDropped *)allocator.zero_allocate(size, sizeof(turtle_brick_interfaces__msg__BrickDropped), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_brick_interfaces__msg__BrickDropped__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_brick_interfaces__msg__BrickDropped__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_brick_interfaces__msg__BrickDropped__Sequence__fini(turtle_brick_interfaces__msg__BrickDropped__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_brick_interfaces__msg__BrickDropped__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_brick_interfaces__msg__BrickDropped__Sequence *
turtle_brick_interfaces__msg__BrickDropped__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_brick_interfaces__msg__BrickDropped__Sequence * array = (turtle_brick_interfaces__msg__BrickDropped__Sequence *)allocator.allocate(sizeof(turtle_brick_interfaces__msg__BrickDropped__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_brick_interfaces__msg__BrickDropped__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_brick_interfaces__msg__BrickDropped__Sequence__destroy(turtle_brick_interfaces__msg__BrickDropped__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_brick_interfaces__msg__BrickDropped__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_brick_interfaces__msg__BrickDropped__Sequence__are_equal(const turtle_brick_interfaces__msg__BrickDropped__Sequence * lhs, const turtle_brick_interfaces__msg__BrickDropped__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_brick_interfaces__msg__BrickDropped__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_brick_interfaces__msg__BrickDropped__Sequence__copy(
  const turtle_brick_interfaces__msg__BrickDropped__Sequence * input,
  turtle_brick_interfaces__msg__BrickDropped__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_brick_interfaces__msg__BrickDropped);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_brick_interfaces__msg__BrickDropped * data =
      (turtle_brick_interfaces__msg__BrickDropped *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_brick_interfaces__msg__BrickDropped__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_brick_interfaces__msg__BrickDropped__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_brick_interfaces__msg__BrickDropped__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
