#ifndef _ROS_morpheus_skates_skate_command_h
#define _ROS_morpheus_skates_skate_command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace morpheus_skates
{

  class skate_command : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _calibration_enable_type;
      _calibration_enable_type calibration_enable;
      typedef int32_t _command_target_type;
      _command_target_type command_target;

    skate_command():
      header(),
      calibration_enable(0),
      command_target(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_calibration_enable;
      u_calibration_enable.real = this->calibration_enable;
      *(outbuffer + offset + 0) = (u_calibration_enable.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_calibration_enable.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_calibration_enable.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_calibration_enable.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->calibration_enable);
      union {
        int32_t real;
        uint32_t base;
      } u_command_target;
      u_command_target.real = this->command_target;
      *(outbuffer + offset + 0) = (u_command_target.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_command_target.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_command_target.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_command_target.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->command_target);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_calibration_enable;
      u_calibration_enable.base = 0;
      u_calibration_enable.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_calibration_enable.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_calibration_enable.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_calibration_enable.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->calibration_enable = u_calibration_enable.real;
      offset += sizeof(this->calibration_enable);
      union {
        int32_t real;
        uint32_t base;
      } u_command_target;
      u_command_target.base = 0;
      u_command_target.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_command_target.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_command_target.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_command_target.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->command_target = u_command_target.real;
      offset += sizeof(this->command_target);
     return offset;
    }

    const char * getType(){ return "morpheus_skates/skate_command"; };
    const char * getMD5(){ return "eb77e7d8ddea947728653dde426e34c7"; };

  };

}
#endif