#ifndef _ROS_SERVICE_zero_point_h
#define _ROS_SERVICE_zero_point_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace motor
{

static const char ZERO_POINT[] = "motor/zero_point";

  class zero_pointRequest : public ros::Msg
  {
    public:

    zero_pointRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return ZERO_POINT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class zero_pointResponse : public ros::Msg
  {
    public:
      typedef float _zero_x_type;
      _zero_x_type zero_x;
      typedef float _zero_y_type;
      _zero_y_type zero_y;
      typedef float _zero_z_type;
      _zero_z_type zero_z;

    zero_pointResponse():
      zero_x(0),
      zero_y(0),
      zero_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->zero_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->zero_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->zero_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->zero_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->zero_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->zero_z));
     return offset;
    }

    const char * getType(){ return ZERO_POINT; };
    const char * getMD5(){ return "c0900cb104c9c04a5c3b1edc43765f2a"; };

  };

  class zero_point {
    public:
    typedef zero_pointRequest Request;
    typedef zero_pointResponse Response;
  };

}
#endif
