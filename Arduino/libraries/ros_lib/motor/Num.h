#ifndef _ROS_motor_Num_h
#define _ROS_motor_Num_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace motor
{

  class Num : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _f1_type;
      _f1_type f1;
      typedef int32_t _f2_type;
      _f2_type f2;
      typedef int32_t _f3_type;
      _f3_type f3;
      typedef float _qx_type;
      _qx_type qx;
      typedef float _qy_type;
      _qy_type qy;
      typedef float _qz_type;
      _qz_type qz;
      typedef float _qw_type;
      _qw_type qw;
      typedef float _ax_type;
      _ax_type ax;
      typedef float _ay_type;
      _ay_type ay;
      typedef float _az_type;
      _az_type az;
      typedef float _rp_type;
      _rp_type rp;
      typedef float _ry_type;
      _ry_type ry;
      typedef float _rr_type;
      _rr_type rr;

    Num():
      header(),
      f1(0),
      f2(0),
      f3(0),
      qx(0),
      qy(0),
      qz(0),
      qw(0),
      ax(0),
      ay(0),
      az(0),
      rp(0),
      ry(0),
      rr(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_f1;
      u_f1.real = this->f1;
      *(outbuffer + offset + 0) = (u_f1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_f1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_f1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->f1);
      union {
        int32_t real;
        uint32_t base;
      } u_f2;
      u_f2.real = this->f2;
      *(outbuffer + offset + 0) = (u_f2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_f2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_f2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->f2);
      union {
        int32_t real;
        uint32_t base;
      } u_f3;
      u_f3.real = this->f3;
      *(outbuffer + offset + 0) = (u_f3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_f3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_f3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->f3);
      offset += serializeAvrFloat64(outbuffer + offset, this->qx);
      offset += serializeAvrFloat64(outbuffer + offset, this->qy);
      offset += serializeAvrFloat64(outbuffer + offset, this->qz);
      offset += serializeAvrFloat64(outbuffer + offset, this->qw);
      offset += serializeAvrFloat64(outbuffer + offset, this->ax);
      offset += serializeAvrFloat64(outbuffer + offset, this->ay);
      offset += serializeAvrFloat64(outbuffer + offset, this->az);
      offset += serializeAvrFloat64(outbuffer + offset, this->rp);
      offset += serializeAvrFloat64(outbuffer + offset, this->ry);
      offset += serializeAvrFloat64(outbuffer + offset, this->rr);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_f1;
      u_f1.base = 0;
      u_f1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_f1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_f1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->f1 = u_f1.real;
      offset += sizeof(this->f1);
      union {
        int32_t real;
        uint32_t base;
      } u_f2;
      u_f2.base = 0;
      u_f2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_f2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_f2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->f2 = u_f2.real;
      offset += sizeof(this->f2);
      union {
        int32_t real;
        uint32_t base;
      } u_f3;
      u_f3.base = 0;
      u_f3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_f3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_f3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->f3 = u_f3.real;
      offset += sizeof(this->f3);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qz));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ax));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ay));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->az));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ry));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rr));
     return offset;
    }

    const char * getType(){ return "motor/Num"; };
    const char * getMD5(){ return "3c819e3d7118a7e8382129f8ffeccd87"; };

  };

}
#endif