#ifndef _ROS_morpheus_skates_user_force_normalized_h
#define _ROS_morpheus_skates_user_force_normalized_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace morpheus_skates
{

  class user_force_normalized : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _left_normal_front_outer_type;
      _left_normal_front_outer_type left_normal_front_outer;
      typedef float _left_normal_front_inner_type;
      _left_normal_front_inner_type left_normal_front_inner;
      typedef float _left_normal_rear_type;
      _left_normal_rear_type left_normal_rear;
      typedef float _right_normal_front_outer_type;
      _right_normal_front_outer_type right_normal_front_outer;
      typedef float _right_normal_front_inner_type;
      _right_normal_front_inner_type right_normal_front_inner;
      typedef float _right_normal_rear_type;
      _right_normal_rear_type right_normal_rear;
      typedef float _right_normal_total_type;
      _right_normal_total_type right_normal_total;
      typedef float _left_normal_total_type;
      _left_normal_total_type left_normal_total;
      typedef float _normal_total_type;
      _normal_total_type normal_total;

    user_force_normalized():
      header(),
      left_normal_front_outer(0),
      left_normal_front_inner(0),
      left_normal_rear(0),
      right_normal_front_outer(0),
      right_normal_front_inner(0),
      right_normal_rear(0),
      right_normal_total(0),
      left_normal_total(0),
      normal_total(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_left_normal_front_outer;
      u_left_normal_front_outer.real = this->left_normal_front_outer;
      *(outbuffer + offset + 0) = (u_left_normal_front_outer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_normal_front_outer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_normal_front_outer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_normal_front_outer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_normal_front_outer);
      union {
        float real;
        uint32_t base;
      } u_left_normal_front_inner;
      u_left_normal_front_inner.real = this->left_normal_front_inner;
      *(outbuffer + offset + 0) = (u_left_normal_front_inner.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_normal_front_inner.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_normal_front_inner.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_normal_front_inner.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_normal_front_inner);
      union {
        float real;
        uint32_t base;
      } u_left_normal_rear;
      u_left_normal_rear.real = this->left_normal_rear;
      *(outbuffer + offset + 0) = (u_left_normal_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_normal_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_normal_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_normal_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_normal_rear);
      union {
        float real;
        uint32_t base;
      } u_right_normal_front_outer;
      u_right_normal_front_outer.real = this->right_normal_front_outer;
      *(outbuffer + offset + 0) = (u_right_normal_front_outer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_normal_front_outer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_normal_front_outer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_normal_front_outer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_normal_front_outer);
      union {
        float real;
        uint32_t base;
      } u_right_normal_front_inner;
      u_right_normal_front_inner.real = this->right_normal_front_inner;
      *(outbuffer + offset + 0) = (u_right_normal_front_inner.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_normal_front_inner.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_normal_front_inner.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_normal_front_inner.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_normal_front_inner);
      union {
        float real;
        uint32_t base;
      } u_right_normal_rear;
      u_right_normal_rear.real = this->right_normal_rear;
      *(outbuffer + offset + 0) = (u_right_normal_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_normal_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_normal_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_normal_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_normal_rear);
      union {
        float real;
        uint32_t base;
      } u_right_normal_total;
      u_right_normal_total.real = this->right_normal_total;
      *(outbuffer + offset + 0) = (u_right_normal_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_normal_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_normal_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_normal_total.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_normal_total);
      union {
        float real;
        uint32_t base;
      } u_left_normal_total;
      u_left_normal_total.real = this->left_normal_total;
      *(outbuffer + offset + 0) = (u_left_normal_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_normal_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_normal_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_normal_total.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_normal_total);
      union {
        float real;
        uint32_t base;
      } u_normal_total;
      u_normal_total.real = this->normal_total;
      *(outbuffer + offset + 0) = (u_normal_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_normal_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_normal_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_normal_total.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->normal_total);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_left_normal_front_outer;
      u_left_normal_front_outer.base = 0;
      u_left_normal_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_normal_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_normal_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_normal_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_normal_front_outer = u_left_normal_front_outer.real;
      offset += sizeof(this->left_normal_front_outer);
      union {
        float real;
        uint32_t base;
      } u_left_normal_front_inner;
      u_left_normal_front_inner.base = 0;
      u_left_normal_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_normal_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_normal_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_normal_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_normal_front_inner = u_left_normal_front_inner.real;
      offset += sizeof(this->left_normal_front_inner);
      union {
        float real;
        uint32_t base;
      } u_left_normal_rear;
      u_left_normal_rear.base = 0;
      u_left_normal_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_normal_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_normal_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_normal_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_normal_rear = u_left_normal_rear.real;
      offset += sizeof(this->left_normal_rear);
      union {
        float real;
        uint32_t base;
      } u_right_normal_front_outer;
      u_right_normal_front_outer.base = 0;
      u_right_normal_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_normal_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_normal_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_normal_front_outer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_normal_front_outer = u_right_normal_front_outer.real;
      offset += sizeof(this->right_normal_front_outer);
      union {
        float real;
        uint32_t base;
      } u_right_normal_front_inner;
      u_right_normal_front_inner.base = 0;
      u_right_normal_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_normal_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_normal_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_normal_front_inner.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_normal_front_inner = u_right_normal_front_inner.real;
      offset += sizeof(this->right_normal_front_inner);
      union {
        float real;
        uint32_t base;
      } u_right_normal_rear;
      u_right_normal_rear.base = 0;
      u_right_normal_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_normal_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_normal_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_normal_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_normal_rear = u_right_normal_rear.real;
      offset += sizeof(this->right_normal_rear);
      union {
        float real;
        uint32_t base;
      } u_right_normal_total;
      u_right_normal_total.base = 0;
      u_right_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_normal_total = u_right_normal_total.real;
      offset += sizeof(this->right_normal_total);
      union {
        float real;
        uint32_t base;
      } u_left_normal_total;
      u_left_normal_total.base = 0;
      u_left_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_normal_total = u_left_normal_total.real;
      offset += sizeof(this->left_normal_total);
      union {
        float real;
        uint32_t base;
      } u_normal_total;
      u_normal_total.base = 0;
      u_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_normal_total.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->normal_total = u_normal_total.real;
      offset += sizeof(this->normal_total);
     return offset;
    }

    const char * getType(){ return "morpheus_skates/user_force_normalized"; };
    const char * getMD5(){ return "aed377f4f2b3a09b9b9779a3f8aebb24"; };

  };

}
#endif