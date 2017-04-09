#ifndef _ROS_morpheus_skates_pounds_display_h
#define _ROS_morpheus_skates_pounds_display_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace morpheus_skates
{

  class pounds_display : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _left_force_front_outer_type;
      _left_force_front_outer_type left_force_front_outer;
      typedef float _left_force_front_inner_type;
      _left_force_front_inner_type left_force_front_inner;
      typedef float _left_force_rear_type;
      _left_force_rear_type left_force_rear;
      typedef float _right_force_front_outer_type;
      _right_force_front_outer_type right_force_front_outer;
      typedef float _right_force_front_inner_type;
      _right_force_front_inner_type right_force_front_inner;
      typedef float _right_force_rear_type;
      _right_force_rear_type right_force_rear;
      typedef float _right_total_type;
      _right_total_type right_total;
      typedef float _left_total_type;
      _left_total_type left_total;
      typedef float _total_type;
      _total_type total;

    pounds_display():
      header(),
      left_force_front_outer(0),
      left_force_front_inner(0),
      left_force_rear(0),
      right_force_front_outer(0),
      right_force_front_inner(0),
      right_force_rear(0),
      right_total(0),
      left_total(0),
      total(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_left_force_front_outer;
      u_left_force_front_outer.real = this->left_force_front_outer;
      *(outbuffer + offset + 0) = (u_left_force_front_outer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_force_front_outer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_force_front_outer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_force_front_outer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_force_front_outer);
      union {
        float real;
        uint32_t base;
      } u_left_force_front_inner;
      u_left_force_front_inner.real = this->left_force_front_inner;
      *(outbuffer + offset + 0) = (u_left_force_front_inner.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_force_front_inner.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_force_front_inner.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_force_front_inner.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_force_front_inner);
      union {
        float real;
        uint32_t base;
      } u_left_force_rear;
      u_left_force_rear.real = this->left_force_rear;
      *(outbuffer + offset + 0) = (u_left_force_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_force_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_force_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_force_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_force_rear);
      union {
        float real;
        uint32_t base;
      } u_right_force_front_outer;
      u_right_force_front_outer.real = this->right_force_front_outer;
      *(outbuffer + offset + 0) = (u_right_force_front_outer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_force_front_outer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_force_front_outer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_force_front_outer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_force_front_outer);
      union {
        float real;
        uint32_t base;
      } u_right_force_front_inner;
      u_right_force_front_inner.real = this->right_force_front_inner;
      *(outbuffer + offset + 0) = (u_right_force_front_inner.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_force_front_inner.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_force_front_inner.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_force_front_inner.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_force_front_inner);
      union {
        float real;
        uint32_t base;
      } u_right_force_rear;
      u_right_force_rear.real = this->right_force_rear;
      *(outbuffer + offset + 0) = (u_right_force_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_force_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_force_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_force_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_force_rear);
      union {
        float real;
        uint32_t base;
      } u_right_total;
      u_right_total.real = this->right_total;
      *(outbuffer + offset + 0) = (u_right_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_total.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_total);
      union {
        float real;
        uint32_t base;
      } u_left_total;
      u_left_total.real = this->left_total;
      *(outbuffer + offset + 0) = (u_left_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_total.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_total);
      union {
        float real;
        uint32_t base;
      } u_total;
      u_total.real = this->total;
      *(outbuffer + offset + 0) = (u_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_left_force_front_outer;
      u_left_force_front_outer.base = 0;
      u_left_force_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_force_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_force_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_force_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_force_front_outer = u_left_force_front_outer.real;
      offset += sizeof(this->left_force_front_outer);
      union {
        float real;
        uint32_t base;
      } u_left_force_front_inner;
      u_left_force_front_inner.base = 0;
      u_left_force_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_force_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_force_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_force_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_force_front_inner = u_left_force_front_inner.real;
      offset += sizeof(this->left_force_front_inner);
      union {
        float real;
        uint32_t base;
      } u_left_force_rear;
      u_left_force_rear.base = 0;
      u_left_force_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_force_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_force_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_force_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_force_rear = u_left_force_rear.real;
      offset += sizeof(this->left_force_rear);
      union {
        float real;
        uint32_t base;
      } u_right_force_front_outer;
      u_right_force_front_outer.base = 0;
      u_right_force_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_force_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_force_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_force_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_force_front_outer = u_right_force_front_outer.real;
      offset += sizeof(this->right_force_front_outer);
      union {
        float real;
        uint32_t base;
      } u_right_force_front_inner;
      u_right_force_front_inner.base = 0;
      u_right_force_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_force_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_force_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_force_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_force_front_inner = u_right_force_front_inner.real;
      offset += sizeof(this->right_force_front_inner);
      union {
        float real;
        uint32_t base;
      } u_right_force_rear;
      u_right_force_rear.base = 0;
      u_right_force_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_force_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_force_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_force_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_force_rear = u_right_force_rear.real;
      offset += sizeof(this->right_force_rear);
      union {
        float real;
        uint32_t base;
      } u_right_total;
      u_right_total.base = 0;
      u_right_total.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_total.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_total.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_total.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_total = u_right_total.real;
      offset += sizeof(this->right_total);
      union {
        float real;
        uint32_t base;
      } u_left_total;
      u_left_total.base = 0;
      u_left_total.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_total.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_total.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_total.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_total = u_left_total.real;
      offset += sizeof(this->left_total);
      union {
        float real;
        uint32_t base;
      } u_total;
      u_total.base = 0;
      u_total.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total = u_total.real;
      offset += sizeof(this->total);
     return offset;
    }

    const char * getType(){ return "morpheus_skates/pounds_display"; };
    const char * getMD5(){ return "0b0dc79b21c682dc91490e0c57eacf86"; };

  };

}
#endif