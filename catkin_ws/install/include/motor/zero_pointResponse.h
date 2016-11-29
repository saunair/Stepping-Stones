// Generated by gencpp from file motor/zero_pointResponse.msg
// DO NOT EDIT!


#ifndef MOTOR_MESSAGE_ZERO_POINTRESPONSE_H
#define MOTOR_MESSAGE_ZERO_POINTRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace motor
{
template <class ContainerAllocator>
struct zero_pointResponse_
{
  typedef zero_pointResponse_<ContainerAllocator> Type;

  zero_pointResponse_()
    : zero_x(0)
    , zero_y(0)
    , zero_z(0)  {
    }
  zero_pointResponse_(const ContainerAllocator& _alloc)
    : zero_x(0)
    , zero_y(0)
    , zero_z(0)  {
  (void)_alloc;
    }



   typedef int64_t _zero_x_type;
  _zero_x_type zero_x;

   typedef int64_t _zero_y_type;
  _zero_y_type zero_y;

   typedef int64_t _zero_z_type;
  _zero_z_type zero_z;




  typedef boost::shared_ptr< ::motor::zero_pointResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::motor::zero_pointResponse_<ContainerAllocator> const> ConstPtr;

}; // struct zero_pointResponse_

typedef ::motor::zero_pointResponse_<std::allocator<void> > zero_pointResponse;

typedef boost::shared_ptr< ::motor::zero_pointResponse > zero_pointResponsePtr;
typedef boost::shared_ptr< ::motor::zero_pointResponse const> zero_pointResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::motor::zero_pointResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::motor::zero_pointResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace motor

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'motor': ['/home/saurabh/catkin_ws/src/motor/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::motor::zero_pointResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::motor::zero_pointResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::motor::zero_pointResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::motor::zero_pointResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motor::zero_pointResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motor::zero_pointResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::motor::zero_pointResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b79b5e1328dced0b3e91f2dda110ce0e";
  }

  static const char* value(const ::motor::zero_pointResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb79b5e1328dced0bULL;
  static const uint64_t static_value2 = 0x3e91f2dda110ce0eULL;
};

template<class ContainerAllocator>
struct DataType< ::motor::zero_pointResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "motor/zero_pointResponse";
  }

  static const char* value(const ::motor::zero_pointResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::motor::zero_pointResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 zero_x\n\
int64 zero_y\n\
int64 zero_z\n\
\n\
";
  }

  static const char* value(const ::motor::zero_pointResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::motor::zero_pointResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.zero_x);
      stream.next(m.zero_y);
      stream.next(m.zero_z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct zero_pointResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::motor::zero_pointResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::motor::zero_pointResponse_<ContainerAllocator>& v)
  {
    s << indent << "zero_x: ";
    Printer<int64_t>::stream(s, indent + "  ", v.zero_x);
    s << indent << "zero_y: ";
    Printer<int64_t>::stream(s, indent + "  ", v.zero_y);
    s << indent << "zero_z: ";
    Printer<int64_t>::stream(s, indent + "  ", v.zero_z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOTOR_MESSAGE_ZERO_POINTRESPONSE_H
