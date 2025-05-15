// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trajectory_tools:srv/SaveTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_TOOLS__SRV__DETAIL__SAVE_TRAJECTORY__STRUCT_H_
#define TRAJECTORY_TOOLS__SRV__DETAIL__SAVE_TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'filename'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SaveTrajectory in the package trajectory_tools.
typedef struct trajectory_tools__srv__SaveTrajectory_Request
{
  rosidl_runtime_c__String filename;
  double duration_sec;
} trajectory_tools__srv__SaveTrajectory_Request;

// Struct for a sequence of trajectory_tools__srv__SaveTrajectory_Request.
typedef struct trajectory_tools__srv__SaveTrajectory_Request__Sequence
{
  trajectory_tools__srv__SaveTrajectory_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_tools__srv__SaveTrajectory_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SaveTrajectory in the package trajectory_tools.
typedef struct trajectory_tools__srv__SaveTrajectory_Response
{
  bool success;
  rosidl_runtime_c__String message;
} trajectory_tools__srv__SaveTrajectory_Response;

// Struct for a sequence of trajectory_tools__srv__SaveTrajectory_Response.
typedef struct trajectory_tools__srv__SaveTrajectory_Response__Sequence
{
  trajectory_tools__srv__SaveTrajectory_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_tools__srv__SaveTrajectory_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRAJECTORY_TOOLS__SRV__DETAIL__SAVE_TRAJECTORY__STRUCT_H_
