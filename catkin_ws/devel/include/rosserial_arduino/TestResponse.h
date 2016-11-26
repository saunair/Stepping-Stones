// Generated by gencpp from file rosserial_arduino/TestResponse.msg
// DO NOT EDIT!


#ifndef ROSSERIAL_ARDUINO_MESSAGE_TESTRESPONSE_H
#define ROSSERIAL_ARDUINO_MESSAGE_TESTRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rosserial_arduino
{
template <class ContainerAllocator>
struct TestResponse_
{
  typedef TestResponse_<ContainerAllocator> Type;

  TestResponse_()
    : output()  {
    }
  TestResponse_(const ContainerAllocator& _alloc)
    : output(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _output_type;
  _output_type output;




  typedef boost::shared_ptr< ::rosserial_arduino::TestResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosserial_arduino::TestResponse_<ContainerAllocator> const> ConstPtr;

}; // struct TestResponse_

typedef ::rosserial_arduino::TestResponse_<std::allocator<void> > TestResponse;

typedef boost::shared_ptr< ::rosserial_arduino::TestResponse > TestResponsePtr;
typedef boost::shared_ptr< ::rosserial_arduino::TestResponse const> TestResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosserial_arduino::TestResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosserial_arduino::TestResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rosserial_arduino

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'rosserial_arduino': ['/home/saurabh/catkin_ws/src/rosserial/rosserial_arduino/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rosserial_arduino::TestResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosserial_arduino::TestResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosserial_arduino::TestResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosserial_arduino::TestResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosserial_arduino::TestResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosserial_arduino::TestResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosserial_arduino::TestResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0825d95fdfa2c8f4bbb4e9c74bccd3fd";
  }

  static const char* value(const ::rosserial_arduino::TestResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0825d95fdfa2c8f4ULL;
  static const uint64_t static_value2 = 0xbbb4e9c74bccd3fdULL;
};

template<class ContainerAllocator>
struct DataType< ::rosserial_arduino::TestResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosserial_arduino/TestResponse";
  }

  static const char* value(const ::rosserial_arduino::TestResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosserial_arduino::TestResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string output\n\
\n\
";
  }

  static const char* value(const ::rosserial_arduino::TestResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosserial_arduino::TestResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.output);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TestResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosserial_arduino::TestResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosserial_arduino::TestResponse_<ContainerAllocator>& v)
  {
    s << indent << "output: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.output);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSSERIAL_ARDUINO_MESSAGE_TESTRESPONSE_H
