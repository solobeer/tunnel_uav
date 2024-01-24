// Generated by gencpp from file opticalflow/optical.msg
// DO NOT EDIT!


#ifndef OPTICALFLOW_MESSAGE_OPTICAL_H
#define OPTICALFLOW_MESSAGE_OPTICAL_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Quaternion.h>

namespace opticalflow
{
template <class ContainerAllocator>
struct optical_
{
  typedef optical_<ContainerAllocator> Type;

  optical_()
    : header()
    , frameClass(0)
    , mode(0)
    , vel_rate()
    , vel_rate_fix()
    , vel_rate_integ()
    , quality(0.0)
    , dir(0)
    , angle(0)
    , dis(0.0)
    , acc_rate()
    , gry_rate()
    , quat()  {
    }
  optical_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , frameClass(0)
    , mode(0)
    , vel_rate(_alloc)
    , vel_rate_fix(_alloc)
    , vel_rate_integ(_alloc)
    , quality(0.0)
    , dir(0)
    , angle(0)
    , dis(0.0)
    , acc_rate(_alloc)
    , gry_rate(_alloc)
    , quat(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int16_t _frameClass_type;
  _frameClass_type frameClass;

   typedef int16_t _mode_type;
  _mode_type mode;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _vel_rate_type;
  _vel_rate_type vel_rate;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _vel_rate_fix_type;
  _vel_rate_fix_type vel_rate_fix;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _vel_rate_integ_type;
  _vel_rate_integ_type vel_rate_integ;

   typedef float _quality_type;
  _quality_type quality;

   typedef uint8_t _dir_type;
  _dir_type dir;

   typedef uint16_t _angle_type;
  _angle_type angle;

   typedef float _dis_type;
  _dis_type dis;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _acc_rate_type;
  _acc_rate_type acc_rate;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _gry_rate_type;
  _gry_rate_type gry_rate;

   typedef  ::geometry_msgs::Quaternion_<ContainerAllocator>  _quat_type;
  _quat_type quat;





  typedef boost::shared_ptr< ::opticalflow::optical_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::opticalflow::optical_<ContainerAllocator> const> ConstPtr;

}; // struct optical_

typedef ::opticalflow::optical_<std::allocator<void> > optical;

typedef boost::shared_ptr< ::opticalflow::optical > opticalPtr;
typedef boost::shared_ptr< ::opticalflow::optical const> opticalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::opticalflow::optical_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::opticalflow::optical_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::opticalflow::optical_<ContainerAllocator1> & lhs, const ::opticalflow::optical_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.frameClass == rhs.frameClass &&
    lhs.mode == rhs.mode &&
    lhs.vel_rate == rhs.vel_rate &&
    lhs.vel_rate_fix == rhs.vel_rate_fix &&
    lhs.vel_rate_integ == rhs.vel_rate_integ &&
    lhs.quality == rhs.quality &&
    lhs.dir == rhs.dir &&
    lhs.angle == rhs.angle &&
    lhs.dis == rhs.dis &&
    lhs.acc_rate == rhs.acc_rate &&
    lhs.gry_rate == rhs.gry_rate &&
    lhs.quat == rhs.quat;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::opticalflow::optical_<ContainerAllocator1> & lhs, const ::opticalflow::optical_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace opticalflow

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::opticalflow::optical_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::opticalflow::optical_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::opticalflow::optical_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::opticalflow::optical_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::opticalflow::optical_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::opticalflow::optical_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::opticalflow::optical_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8d8fc678561657c551426004e594a041";
  }

  static const char* value(const ::opticalflow::optical_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8d8fc678561657c5ULL;
  static const uint64_t static_value2 = 0x51426004e594a041ULL;
};

template<class ContainerAllocator>
struct DataType< ::opticalflow::optical_<ContainerAllocator> >
{
  static const char* value()
  {
    return "opticalflow/optical";
  }

  static const char* value(const ::opticalflow::optical_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::opticalflow::optical_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"int16 frameClass\n"
"\n"
"int16 mode\n"
"geometry_msgs/Vector3 vel_rate\n"
"geometry_msgs/Vector3 vel_rate_fix\n"
"geometry_msgs/Vector3 vel_rate_integ\n"
"float32 quality\n"
"\n"
"uint8 dir\n"
"uint16 angle\n"
"float32 dis\n"
"\n"
"geometry_msgs/Vector3 acc_rate\n"
"geometry_msgs/Vector3 gry_rate\n"
"\n"
"geometry_msgs/Quaternion quat\n"
"\n"
"\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::opticalflow::optical_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::opticalflow::optical_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.frameClass);
      stream.next(m.mode);
      stream.next(m.vel_rate);
      stream.next(m.vel_rate_fix);
      stream.next(m.vel_rate_integ);
      stream.next(m.quality);
      stream.next(m.dir);
      stream.next(m.angle);
      stream.next(m.dis);
      stream.next(m.acc_rate);
      stream.next(m.gry_rate);
      stream.next(m.quat);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct optical_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::opticalflow::optical_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::opticalflow::optical_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "frameClass: ";
    Printer<int16_t>::stream(s, indent + "  ", v.frameClass);
    s << indent << "mode: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mode);
    s << indent << "vel_rate: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.vel_rate);
    s << indent << "vel_rate_fix: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.vel_rate_fix);
    s << indent << "vel_rate_integ: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.vel_rate_integ);
    s << indent << "quality: ";
    Printer<float>::stream(s, indent + "  ", v.quality);
    s << indent << "dir: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.dir);
    s << indent << "angle: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.angle);
    s << indent << "dis: ";
    Printer<float>::stream(s, indent + "  ", v.dis);
    s << indent << "acc_rate: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.acc_rate);
    s << indent << "gry_rate: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.gry_rate);
    s << indent << "quat: ";
    s << std::endl;
    Printer< ::geometry_msgs::Quaternion_<ContainerAllocator> >::stream(s, indent + "  ", v.quat);
  }
};

} // namespace message_operations
} // namespace ros

#endif // OPTICALFLOW_MESSAGE_OPTICAL_H