#ifndef _ROS_SERVICE_sensors_normalized_h
#define _ROS_SERVICE_sensors_normalized_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace morpheus_skates
{

static const char SENSORS_NORMALIZED[] = "morpheus_skates/sensors_normalized";

  class sensors_normalizedRequest : public ros::Msg
  {
    public:

    sensors_normalizedRequest()
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

    const char * getType(){ return SENSORS_NORMALIZED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class sensors_normalizedResponse : public ros::Msg
  {
    public:
      typedef double _total_weight_type;
      _total_weight_type total_weight;

    sensors_normalizedResponse():
      total_weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_total_weight;
      u_total_weight.real = this->total_weight;
      *(outbuffer + offset + 0) = (u_total_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_weight.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_total_weight.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_total_weight.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_total_weight.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_total_weight.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->total_weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_total_weight;
      u_total_weight.base = 0;
      u_total_weight.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_weight.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_weight.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_weight.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_total_weight.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_total_weight.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_total_weight.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_total_weight.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->total_weight = u_total_weight.real;
      offset += sizeof(this->total_weight);
     return offset;
    }

    const char * getType(){ return SENSORS_NORMALIZED; };
    const char * getMD5(){ return "2c7f736e68cd1dfd5a0c565161446ceb"; };

  };

  class sensors_normalized {
    public:
    typedef sensors_normalizedRequest Request;
    typedef sensors_normalizedResponse Response;
  };

}
#endif
