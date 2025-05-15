// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trajectory_tools:srv/SaveTrajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_TOOLS__SRV__DETAIL__SAVE_TRAJECTORY__TRAITS_HPP_
#define TRAJECTORY_TOOLS__SRV__DETAIL__SAVE_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "trajectory_tools/srv/detail/save_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace trajectory_tools
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveTrajectory_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: filename
  {
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << ", ";
  }

  // member: duration_sec
  {
    out << "duration_sec: ";
    rosidl_generator_traits::value_to_yaml(msg.duration_sec, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << "\n";
  }

  // member: duration_sec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration_sec: ";
    rosidl_generator_traits::value_to_yaml(msg.duration_sec, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveTrajectory_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace trajectory_tools

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_tools::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_tools::srv::SaveTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_tools::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_tools::srv::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_tools::srv::SaveTrajectory_Request & msg)
{
  return trajectory_tools::srv::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_tools::srv::SaveTrajectory_Request>()
{
  return "trajectory_tools::srv::SaveTrajectory_Request";
}

template<>
inline const char * name<trajectory_tools::srv::SaveTrajectory_Request>()
{
  return "trajectory_tools/srv/SaveTrajectory_Request";
}

template<>
struct has_fixed_size<trajectory_tools::srv::SaveTrajectory_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trajectory_tools::srv::SaveTrajectory_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trajectory_tools::srv::SaveTrajectory_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace trajectory_tools
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveTrajectory_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveTrajectory_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace trajectory_tools

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_tools::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_tools::srv::SaveTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_tools::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_tools::srv::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_tools::srv::SaveTrajectory_Response & msg)
{
  return trajectory_tools::srv::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_tools::srv::SaveTrajectory_Response>()
{
  return "trajectory_tools::srv::SaveTrajectory_Response";
}

template<>
inline const char * name<trajectory_tools::srv::SaveTrajectory_Response>()
{
  return "trajectory_tools/srv/SaveTrajectory_Response";
}

template<>
struct has_fixed_size<trajectory_tools::srv::SaveTrajectory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trajectory_tools::srv::SaveTrajectory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trajectory_tools::srv::SaveTrajectory_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trajectory_tools::srv::SaveTrajectory>()
{
  return "trajectory_tools::srv::SaveTrajectory";
}

template<>
inline const char * name<trajectory_tools::srv::SaveTrajectory>()
{
  return "trajectory_tools/srv/SaveTrajectory";
}

template<>
struct has_fixed_size<trajectory_tools::srv::SaveTrajectory>
  : std::integral_constant<
    bool,
    has_fixed_size<trajectory_tools::srv::SaveTrajectory_Request>::value &&
    has_fixed_size<trajectory_tools::srv::SaveTrajectory_Response>::value
  >
{
};

template<>
struct has_bounded_size<trajectory_tools::srv::SaveTrajectory>
  : std::integral_constant<
    bool,
    has_bounded_size<trajectory_tools::srv::SaveTrajectory_Request>::value &&
    has_bounded_size<trajectory_tools::srv::SaveTrajectory_Response>::value
  >
{
};

template<>
struct is_service<trajectory_tools::srv::SaveTrajectory>
  : std::true_type
{
};

template<>
struct is_service_request<trajectory_tools::srv::SaveTrajectory_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trajectory_tools::srv::SaveTrajectory_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TRAJECTORY_TOOLS__SRV__DETAIL__SAVE_TRAJECTORY__TRAITS_HPP_
