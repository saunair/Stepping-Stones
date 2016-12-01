#ifndef _ROS_motor_states_h
#define _ROS_motor_states_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace motor
{

  class states : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _state_type;
      _state_type state;
      typedef int32_t _set_point_type;
      _set_point_type set_point;

    states():
      header(),
      state(0),
      set_point(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state);
      union {
        int32_t real;
        uint32_t base;
      } u_set_point;
      u_set_point.real = this->set_point;
      *(outbuffer + offset + 0) = (u_set_point.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_set_point.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_set_point.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_set_point.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->set_point);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state = u_state.real;
      offset += sizeof(this->state);
      union {
        int32_t real;
        uint32_t base;
      } u_set_point;
      u_set_point.base = 0;
      u_set_point.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_set_point.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_set_point.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_set_point.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->set_point = u_set_point.real;
      offset += sizeof(this->set_point);
     return offset;
    }

    const char * getType(){ return "motor/states"; };
    const char * getMD5(){ return "7c54f357503453db8f84f3b13454e6f8"; };

  };

}
#endif