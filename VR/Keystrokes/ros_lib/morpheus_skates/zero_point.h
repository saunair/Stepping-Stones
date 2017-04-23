#ifndef _ROS_SERVICE_zero_point_h
#define _ROS_SERVICE_zero_point_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace morpheus_skates
{

static const char ZERO_POINT[] = "morpheus_skates/zero_point";

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
      typedef double _zero_x_type;
      _zero_x_type zero_x;
      typedef double _zero_y_type;
      _zero_y_type zero_y;
      typedef double _zero_z_type;
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
      union {
        double real;
        uint64_t base;
      } u_zero_x;
      u_zero_x.real = this->zero_x;
      *(outbuffer + offset + 0) = (u_zero_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zero_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zero_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zero_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_zero_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_zero_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_zero_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_zero_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->zero_x);
      union {
        double real;
        uint64_t base;
      } u_zero_y;
      u_zero_y.real = this->zero_y;
      *(outbuffer + offset + 0) = (u_zero_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zero_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zero_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zero_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_zero_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_zero_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_zero_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_zero_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->zero_y);
      union {
        double real;
        uint64_t base;
      } u_zero_z;
      u_zero_z.real = this->zero_z;
      *(outbuffer + offset + 0) = (u_zero_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zero_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zero_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zero_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_zero_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_zero_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_zero_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_zero_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->zero_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_zero_x;
      u_zero_x.base = 0;
      u_zero_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zero_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zero_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zero_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_zero_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_zero_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_zero_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_zero_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->zero_x = u_zero_x.real;
      offset += sizeof(this->zero_x);
      union {
        double real;
        uint64_t base;
      } u_zero_y;
      u_zero_y.base = 0;
      u_zero_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zero_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zero_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zero_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_zero_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_zero_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_zero_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_zero_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->zero_y = u_zero_y.real;
      offset += sizeof(this->zero_y);
      union {
        double real;
        uint64_t base;
      } u_zero_z;
      u_zero_z.base = 0;
      u_zero_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zero_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zero_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zero_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_zero_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_zero_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_zero_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_zero_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->zero_z = u_zero_z.real;
      offset += sizeof(this->zero_z);
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
