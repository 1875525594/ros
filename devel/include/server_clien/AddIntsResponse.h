// Generated by gencpp from file server_clien/AddIntsResponse.msg
// DO NOT EDIT!


#ifndef SERVER_CLIEN_MESSAGE_ADDINTSRESPONSE_H
#define SERVER_CLIEN_MESSAGE_ADDINTSRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace server_clien
{
template <class ContainerAllocator>
struct AddIntsResponse_
{
  typedef AddIntsResponse_<ContainerAllocator> Type;

  AddIntsResponse_()
    : sum(0)  {
    }
  AddIntsResponse_(const ContainerAllocator& _alloc)
    : sum(0)  {
  (void)_alloc;
    }



   typedef int32_t _sum_type;
  _sum_type sum;





  typedef boost::shared_ptr< ::server_clien::AddIntsResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::server_clien::AddIntsResponse_<ContainerAllocator> const> ConstPtr;

}; // struct AddIntsResponse_

typedef ::server_clien::AddIntsResponse_<std::allocator<void> > AddIntsResponse;

typedef boost::shared_ptr< ::server_clien::AddIntsResponse > AddIntsResponsePtr;
typedef boost::shared_ptr< ::server_clien::AddIntsResponse const> AddIntsResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::server_clien::AddIntsResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::server_clien::AddIntsResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::server_clien::AddIntsResponse_<ContainerAllocator1> & lhs, const ::server_clien::AddIntsResponse_<ContainerAllocator2> & rhs)
{
  return lhs.sum == rhs.sum;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::server_clien::AddIntsResponse_<ContainerAllocator1> & lhs, const ::server_clien::AddIntsResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace server_clien

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::server_clien::AddIntsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::server_clien::AddIntsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::server_clien::AddIntsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::server_clien::AddIntsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::server_clien::AddIntsResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::server_clien::AddIntsResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::server_clien::AddIntsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0ba699c25c9418c0366f3595c0c8e8ec";
  }

  static const char* value(const ::server_clien::AddIntsResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0ba699c25c9418c0ULL;
  static const uint64_t static_value2 = 0x366f3595c0c8e8ecULL;
};

template<class ContainerAllocator>
struct DataType< ::server_clien::AddIntsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "server_clien/AddIntsResponse";
  }

  static const char* value(const ::server_clien::AddIntsResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::server_clien::AddIntsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# 服务器响应发送的数据\n"
"int32 sum\n"
"\n"
;
  }

  static const char* value(const ::server_clien::AddIntsResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::server_clien::AddIntsResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sum);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddIntsResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::server_clien::AddIntsResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::server_clien::AddIntsResponse_<ContainerAllocator>& v)
  {
    s << indent << "sum: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sum);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SERVER_CLIEN_MESSAGE_ADDINTSRESPONSE_H
