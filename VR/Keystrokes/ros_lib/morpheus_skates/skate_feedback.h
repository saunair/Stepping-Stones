#ifndef _ROS_morpheus_skates_skate_feedback_h
#define _ROS_morpheus_skates_skate_feedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace morpheus_skates
{

  class skate_feedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _force_front_outer_type;
      _force_front_outer_type force_front_outer;
      typedef int16_t _force_front_inner_type;
      _force_front_inner_type force_front_inner;
      typedef int16_t _force_rear_type;
      _force_rear_type force_rear;
      typedef int16_t _imu_quat_x_type;
      _imu_quat_x_type imu_quat_x;
      typedef int16_t _imu_quat_y_type;
      _imu_quat_y_type imu_quat_y;
      typedef int16_t _imu_quat_z_type;
      _imu_quat_z_type imu_quat_z;
      typedef int16_t _imu_quat_w_type;
      _imu_quat_w_type imu_quat_w;
      typedef float _imu_accel_x_type;
      _imu_accel_x_type imu_accel_x;
      typedef float _imu_accel_y_type;
      _imu_accel_y_type imu_accel_y;
      typedef float _imu_accel_z_type;
      _imu_accel_z_type imu_accel_z;
      typedef float _imu_rate_x_type;
      _imu_rate_x_type imu_rate_x;
      typedef float _imu_rate_y_type;
      _imu_rate_y_type imu_rate_y;
      typedef float _imu_rate_z_type;
      _imu_rate_z_type imu_rate_z;
      typedef float _velocity_cmd_rear_type;
      _velocity_cmd_rear_type velocity_cmd_rear;
      typedef float _velocity_cmd_front_type;
      _velocity_cmd_front_type velocity_cmd_front;
      typedef uint8_t _skate_fault_type;
      _skate_fault_type skate_fault;
      typedef float _position_filt_rear_type;
      _position_filt_rear_type position_filt_rear;
      typedef float _position_filt_front_type;
      _position_filt_front_type position_filt_front;
      typedef float _velocity_filt_rear_type;
      _velocity_filt_rear_type velocity_filt_rear;
      typedef float _velocity_filt_front_type;
      _velocity_filt_front_type velocity_filt_front;
      typedef bool _dead_man_enable_type;
      _dead_man_enable_type dead_man_enable;
      typedef float _controller_target_rear_type;
      _controller_target_rear_type controller_target_rear;
      typedef float _controller_target_front_type;
      _controller_target_front_type controller_target_front;
      typedef int8_t _skate_mode_type;
      _skate_mode_type skate_mode;
      typedef int16_t _debug_int1_type;
      _debug_int1_type debug_int1;
      typedef int16_t _debug_int2_type;
      _debug_int2_type debug_int2;
      typedef int16_t _debug_int3_type;
      _debug_int3_type debug_int3;
      typedef int16_t _debug_int4_type;
      _debug_int4_type debug_int4;
      typedef float _debug_float1_type;
      _debug_float1_type debug_float1;
      typedef float _debug_float2_type;
      _debug_float2_type debug_float2;

    skate_feedback():
      header(),
      force_front_outer(0),
      force_front_inner(0),
      force_rear(0),
      imu_quat_x(0),
      imu_quat_y(0),
      imu_quat_z(0),
      imu_quat_w(0),
      imu_accel_x(0),
      imu_accel_y(0),
      imu_accel_z(0),
      imu_rate_x(0),
      imu_rate_y(0),
      imu_rate_z(0),
      velocity_cmd_rear(0),
      velocity_cmd_front(0),
      skate_fault(0),
      position_filt_rear(0),
      position_filt_front(0),
      velocity_filt_rear(0),
      velocity_filt_front(0),
      dead_man_enable(0),
      controller_target_rear(0),
      controller_target_front(0),
      skate_mode(0),
      debug_int1(0),
      debug_int2(0),
      debug_int3(0),
      debug_int4(0),
      debug_float1(0),
      debug_float2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_force_front_outer;
      u_force_front_outer.real = this->force_front_outer;
      *(outbuffer + offset + 0) = (u_force_front_outer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force_front_outer.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->force_front_outer);
      union {
        int16_t real;
        uint16_t base;
      } u_force_front_inner;
      u_force_front_inner.real = this->force_front_inner;
      *(outbuffer + offset + 0) = (u_force_front_inner.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force_front_inner.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->force_front_inner);
      union {
        int16_t real;
        uint16_t base;
      } u_force_rear;
      u_force_rear.real = this->force_rear;
      *(outbuffer + offset + 0) = (u_force_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force_rear.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->force_rear);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_quat_x;
      u_imu_quat_x.real = this->imu_quat_x;
      *(outbuffer + offset + 0) = (u_imu_quat_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_quat_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imu_quat_x);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_quat_y;
      u_imu_quat_y.real = this->imu_quat_y;
      *(outbuffer + offset + 0) = (u_imu_quat_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_quat_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imu_quat_y);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_quat_z;
      u_imu_quat_z.real = this->imu_quat_z;
      *(outbuffer + offset + 0) = (u_imu_quat_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_quat_z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imu_quat_z);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_quat_w;
      u_imu_quat_w.real = this->imu_quat_w;
      *(outbuffer + offset + 0) = (u_imu_quat_w.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_quat_w.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imu_quat_w);
      union {
        float real;
        uint32_t base;
      } u_imu_accel_x;
      u_imu_accel_x.real = this->imu_accel_x;
      *(outbuffer + offset + 0) = (u_imu_accel_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_accel_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imu_accel_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imu_accel_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu_accel_x);
      union {
        float real;
        uint32_t base;
      } u_imu_accel_y;
      u_imu_accel_y.real = this->imu_accel_y;
      *(outbuffer + offset + 0) = (u_imu_accel_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_accel_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imu_accel_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imu_accel_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu_accel_y);
      union {
        float real;
        uint32_t base;
      } u_imu_accel_z;
      u_imu_accel_z.real = this->imu_accel_z;
      *(outbuffer + offset + 0) = (u_imu_accel_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_accel_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imu_accel_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imu_accel_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu_accel_z);
      union {
        float real;
        uint32_t base;
      } u_imu_rate_x;
      u_imu_rate_x.real = this->imu_rate_x;
      *(outbuffer + offset + 0) = (u_imu_rate_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_rate_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imu_rate_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imu_rate_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu_rate_x);
      union {
        float real;
        uint32_t base;
      } u_imu_rate_y;
      u_imu_rate_y.real = this->imu_rate_y;
      *(outbuffer + offset + 0) = (u_imu_rate_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_rate_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imu_rate_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imu_rate_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu_rate_y);
      union {
        float real;
        uint32_t base;
      } u_imu_rate_z;
      u_imu_rate_z.real = this->imu_rate_z;
      *(outbuffer + offset + 0) = (u_imu_rate_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_rate_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imu_rate_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imu_rate_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu_rate_z);
      union {
        float real;
        uint32_t base;
      } u_velocity_cmd_rear;
      u_velocity_cmd_rear.real = this->velocity_cmd_rear;
      *(outbuffer + offset + 0) = (u_velocity_cmd_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_cmd_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_cmd_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_cmd_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_cmd_rear);
      union {
        float real;
        uint32_t base;
      } u_velocity_cmd_front;
      u_velocity_cmd_front.real = this->velocity_cmd_front;
      *(outbuffer + offset + 0) = (u_velocity_cmd_front.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_cmd_front.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_cmd_front.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_cmd_front.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_cmd_front);
      *(outbuffer + offset + 0) = (this->skate_fault >> (8 * 0)) & 0xFF;
      offset += sizeof(this->skate_fault);
      union {
        float real;
        uint32_t base;
      } u_position_filt_rear;
      u_position_filt_rear.real = this->position_filt_rear;
      *(outbuffer + offset + 0) = (u_position_filt_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_filt_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_filt_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_filt_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_filt_rear);
      union {
        float real;
        uint32_t base;
      } u_position_filt_front;
      u_position_filt_front.real = this->position_filt_front;
      *(outbuffer + offset + 0) = (u_position_filt_front.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_filt_front.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_filt_front.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_filt_front.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_filt_front);
      union {
        float real;
        uint32_t base;
      } u_velocity_filt_rear;
      u_velocity_filt_rear.real = this->velocity_filt_rear;
      *(outbuffer + offset + 0) = (u_velocity_filt_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_filt_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_filt_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_filt_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_filt_rear);
      union {
        float real;
        uint32_t base;
      } u_velocity_filt_front;
      u_velocity_filt_front.real = this->velocity_filt_front;
      *(outbuffer + offset + 0) = (u_velocity_filt_front.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_filt_front.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_filt_front.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_filt_front.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_filt_front);
      union {
        bool real;
        uint8_t base;
      } u_dead_man_enable;
      u_dead_man_enable.real = this->dead_man_enable;
      *(outbuffer + offset + 0) = (u_dead_man_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dead_man_enable);
      union {
        float real;
        uint32_t base;
      } u_controller_target_rear;
      u_controller_target_rear.real = this->controller_target_rear;
      *(outbuffer + offset + 0) = (u_controller_target_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_controller_target_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_controller_target_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_controller_target_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->controller_target_rear);
      union {
        float real;
        uint32_t base;
      } u_controller_target_front;
      u_controller_target_front.real = this->controller_target_front;
      *(outbuffer + offset + 0) = (u_controller_target_front.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_controller_target_front.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_controller_target_front.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_controller_target_front.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->controller_target_front);
      union {
        int8_t real;
        uint8_t base;
      } u_skate_mode;
      u_skate_mode.real = this->skate_mode;
      *(outbuffer + offset + 0) = (u_skate_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->skate_mode);
      union {
        int16_t real;
        uint16_t base;
      } u_debug_int1;
      u_debug_int1.real = this->debug_int1;
      *(outbuffer + offset + 0) = (u_debug_int1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_debug_int1.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->debug_int1);
      union {
        int16_t real;
        uint16_t base;
      } u_debug_int2;
      u_debug_int2.real = this->debug_int2;
      *(outbuffer + offset + 0) = (u_debug_int2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_debug_int2.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->debug_int2);
      union {
        int16_t real;
        uint16_t base;
      } u_debug_int3;
      u_debug_int3.real = this->debug_int3;
      *(outbuffer + offset + 0) = (u_debug_int3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_debug_int3.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->debug_int3);
      union {
        int16_t real;
        uint16_t base;
      } u_debug_int4;
      u_debug_int4.real = this->debug_int4;
      *(outbuffer + offset + 0) = (u_debug_int4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_debug_int4.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->debug_int4);
      union {
        float real;
        uint32_t base;
      } u_debug_float1;
      u_debug_float1.real = this->debug_float1;
      *(outbuffer + offset + 0) = (u_debug_float1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_debug_float1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_debug_float1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_debug_float1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->debug_float1);
      union {
        float real;
        uint32_t base;
      } u_debug_float2;
      u_debug_float2.real = this->debug_float2;
      *(outbuffer + offset + 0) = (u_debug_float2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_debug_float2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_debug_float2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_debug_float2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->debug_float2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_force_front_outer;
      u_force_front_outer.base = 0;
      u_force_front_outer.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force_front_outer.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->force_front_outer = u_force_front_outer.real;
      offset += sizeof(this->force_front_outer);
      union {
        int16_t real;
        uint16_t base;
      } u_force_front_inner;
      u_force_front_inner.base = 0;
      u_force_front_inner.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force_front_inner.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->force_front_inner = u_force_front_inner.real;
      offset += sizeof(this->force_front_inner);
      union {
        int16_t real;
        uint16_t base;
      } u_force_rear;
      u_force_rear.base = 0;
      u_force_rear.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force_rear.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->force_rear = u_force_rear.real;
      offset += sizeof(this->force_rear);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_quat_x;
      u_imu_quat_x.base = 0;
      u_imu_quat_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_quat_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imu_quat_x = u_imu_quat_x.real;
      offset += sizeof(this->imu_quat_x);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_quat_y;
      u_imu_quat_y.base = 0;
      u_imu_quat_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_quat_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imu_quat_y = u_imu_quat_y.real;
      offset += sizeof(this->imu_quat_y);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_quat_z;
      u_imu_quat_z.base = 0;
      u_imu_quat_z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_quat_z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imu_quat_z = u_imu_quat_z.real;
      offset += sizeof(this->imu_quat_z);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_quat_w;
      u_imu_quat_w.base = 0;
      u_imu_quat_w.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_quat_w.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imu_quat_w = u_imu_quat_w.real;
      offset += sizeof(this->imu_quat_w);
      union {
        float real;
        uint32_t base;
      } u_imu_accel_x;
      u_imu_accel_x.base = 0;
      u_imu_accel_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_accel_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imu_accel_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imu_accel_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imu_accel_x = u_imu_accel_x.real;
      offset += sizeof(this->imu_accel_x);
      union {
        float real;
        uint32_t base;
      } u_imu_accel_y;
      u_imu_accel_y.base = 0;
      u_imu_accel_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_accel_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imu_accel_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imu_accel_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imu_accel_y = u_imu_accel_y.real;
      offset += sizeof(this->imu_accel_y);
      union {
        float real;
        uint32_t base;
      } u_imu_accel_z;
      u_imu_accel_z.base = 0;
      u_imu_accel_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_accel_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imu_accel_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imu_accel_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imu_accel_z = u_imu_accel_z.real;
      offset += sizeof(this->imu_accel_z);
      union {
        float real;
        uint32_t base;
      } u_imu_rate_x;
      u_imu_rate_x.base = 0;
      u_imu_rate_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_rate_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imu_rate_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imu_rate_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imu_rate_x = u_imu_rate_x.real;
      offset += sizeof(this->imu_rate_x);
      union {
        float real;
        uint32_t base;
      } u_imu_rate_y;
      u_imu_rate_y.base = 0;
      u_imu_rate_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_rate_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imu_rate_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imu_rate_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imu_rate_y = u_imu_rate_y.real;
      offset += sizeof(this->imu_rate_y);
      union {
        float real;
        uint32_t base;
      } u_imu_rate_z;
      u_imu_rate_z.base = 0;
      u_imu_rate_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_rate_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imu_rate_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imu_rate_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imu_rate_z = u_imu_rate_z.real;
      offset += sizeof(this->imu_rate_z);
      union {
        float real;
        uint32_t base;
      } u_velocity_cmd_rear;
      u_velocity_cmd_rear.base = 0;
      u_velocity_cmd_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_cmd_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_cmd_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_cmd_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_cmd_rear = u_velocity_cmd_rear.real;
      offset += sizeof(this->velocity_cmd_rear);
      union {
        float real;
        uint32_t base;
      } u_velocity_cmd_front;
      u_velocity_cmd_front.base = 0;
      u_velocity_cmd_front.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_cmd_front.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_cmd_front.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_cmd_front.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_cmd_front = u_velocity_cmd_front.real;
      offset += sizeof(this->velocity_cmd_front);
      this->skate_fault =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->skate_fault);
      union {
        float real;
        uint32_t base;
      } u_position_filt_rear;
      u_position_filt_rear.base = 0;
      u_position_filt_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_filt_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_filt_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_filt_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position_filt_rear = u_position_filt_rear.real;
      offset += sizeof(this->position_filt_rear);
      union {
        float real;
        uint32_t base;
      } u_position_filt_front;
      u_position_filt_front.base = 0;
      u_position_filt_front.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_filt_front.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_filt_front.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_filt_front.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position_filt_front = u_position_filt_front.real;
      offset += sizeof(this->position_filt_front);
      union {
        float real;
        uint32_t base;
      } u_velocity_filt_rear;
      u_velocity_filt_rear.base = 0;
      u_velocity_filt_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_filt_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_filt_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_filt_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_filt_rear = u_velocity_filt_rear.real;
      offset += sizeof(this->velocity_filt_rear);
      union {
        float real;
        uint32_t base;
      } u_velocity_filt_front;
      u_velocity_filt_front.base = 0;
      u_velocity_filt_front.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_filt_front.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_filt_front.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_filt_front.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_filt_front = u_velocity_filt_front.real;
      offset += sizeof(this->velocity_filt_front);
      union {
        bool real;
        uint8_t base;
      } u_dead_man_enable;
      u_dead_man_enable.base = 0;
      u_dead_man_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->dead_man_enable = u_dead_man_enable.real;
      offset += sizeof(this->dead_man_enable);
      union {
        float real;
        uint32_t base;
      } u_controller_target_rear;
      u_controller_target_rear.base = 0;
      u_controller_target_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_controller_target_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_controller_target_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_controller_target_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->controller_target_rear = u_controller_target_rear.real;
      offset += sizeof(this->controller_target_rear);
      union {
        float real;
        uint32_t base;
      } u_controller_target_front;
      u_controller_target_front.base = 0;
      u_controller_target_front.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_controller_target_front.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_controller_target_front.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_controller_target_front.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->controller_target_front = u_controller_target_front.real;
      offset += sizeof(this->controller_target_front);
      union {
        int8_t real;
        uint8_t base;
      } u_skate_mode;
      u_skate_mode.base = 0;
      u_skate_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->skate_mode = u_skate_mode.real;
      offset += sizeof(this->skate_mode);
      union {
        int16_t real;
        uint16_t base;
      } u_debug_int1;
      u_debug_int1.base = 0;
      u_debug_int1.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_debug_int1.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->debug_int1 = u_debug_int1.real;
      offset += sizeof(this->debug_int1);
      union {
        int16_t real;
        uint16_t base;
      } u_debug_int2;
      u_debug_int2.base = 0;
      u_debug_int2.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_debug_int2.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->debug_int2 = u_debug_int2.real;
      offset += sizeof(this->debug_int2);
      union {
        int16_t real;
        uint16_t base;
      } u_debug_int3;
      u_debug_int3.base = 0;
      u_debug_int3.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_debug_int3.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->debug_int3 = u_debug_int3.real;
      offset += sizeof(this->debug_int3);
      union {
        int16_t real;
        uint16_t base;
      } u_debug_int4;
      u_debug_int4.base = 0;
      u_debug_int4.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_debug_int4.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->debug_int4 = u_debug_int4.real;
      offset += sizeof(this->debug_int4);
      union {
        float real;
        uint32_t base;
      } u_debug_float1;
      u_debug_float1.base = 0;
      u_debug_float1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_debug_float1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_debug_float1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_debug_float1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->debug_float1 = u_debug_float1.real;
      offset += sizeof(this->debug_float1);
      union {
        float real;
        uint32_t base;
      } u_debug_float2;
      u_debug_float2.base = 0;
      u_debug_float2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_debug_float2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_debug_float2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_debug_float2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->debug_float2 = u_debug_float2.real;
      offset += sizeof(this->debug_float2);
     return offset;
    }

    const char * getType(){ return "morpheus_skates/skate_feedback"; };
    const char * getMD5(){ return "eb441f3c96e0f976c3b78a494f1af1b1"; };

  };

}
#endif