#ifndef _ROS_SERVICE_yaml_values_h
#define _ROS_SERVICE_yaml_values_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace morpheus_skates
{

static const char YAML_VALUES[] = "morpheus_skates/yaml_values";

  class yaml_valuesRequest : public ros::Msg
  {
    public:
      typedef bool _num_type;
      _num_type num;

    yaml_valuesRequest():
      num(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_num;
      u_num.real = this->num;
      *(outbuffer + offset + 0) = (u_num.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_num;
      u_num.base = 0;
      u_num.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->num = u_num.real;
      offset += sizeof(this->num);
     return offset;
    }

    const char * getType(){ return YAML_VALUES; };
    const char * getMD5(){ return "3c4b983bdbcc51dc7ef8a75dea21c0f0"; };

  };

  class yaml_valuesResponse : public ros::Msg
  {
    public:
      typedef double _left_bias_f1_type;
      _left_bias_f1_type left_bias_f1;
      typedef double _left_bias_f2_type;
      _left_bias_f2_type left_bias_f2;
      typedef double _left_bias_f3_type;
      _left_bias_f3_type left_bias_f3;
      typedef double _left_gain_f1_type;
      _left_gain_f1_type left_gain_f1;
      typedef double _left_gain_f2_type;
      _left_gain_f2_type left_gain_f2;
      typedef double _left_gain_f3_type;
      _left_gain_f3_type left_gain_f3;
      typedef double _right_bias_f1_type;
      _right_bias_f1_type right_bias_f1;
      typedef double _right_bias_f2_type;
      _right_bias_f2_type right_bias_f2;
      typedef double _right_bias_f3_type;
      _right_bias_f3_type right_bias_f3;
      typedef double _right_gain_f1_type;
      _right_gain_f1_type right_gain_f1;
      typedef double _right_gain_f2_type;
      _right_gain_f2_type right_gain_f2;
      typedef double _right_gain_f3_type;
      _right_gain_f3_type right_gain_f3;

    yaml_valuesResponse():
      left_bias_f1(0),
      left_bias_f2(0),
      left_bias_f3(0),
      left_gain_f1(0),
      left_gain_f2(0),
      left_gain_f3(0),
      right_bias_f1(0),
      right_bias_f2(0),
      right_bias_f3(0),
      right_gain_f1(0),
      right_gain_f2(0),
      right_gain_f3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_left_bias_f1;
      u_left_bias_f1.real = this->left_bias_f1;
      *(outbuffer + offset + 0) = (u_left_bias_f1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_bias_f1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_bias_f1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_bias_f1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_bias_f1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_bias_f1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_bias_f1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_bias_f1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_bias_f1);
      union {
        double real;
        uint64_t base;
      } u_left_bias_f2;
      u_left_bias_f2.real = this->left_bias_f2;
      *(outbuffer + offset + 0) = (u_left_bias_f2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_bias_f2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_bias_f2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_bias_f2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_bias_f2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_bias_f2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_bias_f2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_bias_f2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_bias_f2);
      union {
        double real;
        uint64_t base;
      } u_left_bias_f3;
      u_left_bias_f3.real = this->left_bias_f3;
      *(outbuffer + offset + 0) = (u_left_bias_f3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_bias_f3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_bias_f3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_bias_f3.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_bias_f3.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_bias_f3.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_bias_f3.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_bias_f3.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_bias_f3);
      union {
        double real;
        uint64_t base;
      } u_left_gain_f1;
      u_left_gain_f1.real = this->left_gain_f1;
      *(outbuffer + offset + 0) = (u_left_gain_f1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_gain_f1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_gain_f1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_gain_f1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_gain_f1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_gain_f1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_gain_f1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_gain_f1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_gain_f1);
      union {
        double real;
        uint64_t base;
      } u_left_gain_f2;
      u_left_gain_f2.real = this->left_gain_f2;
      *(outbuffer + offset + 0) = (u_left_gain_f2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_gain_f2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_gain_f2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_gain_f2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_gain_f2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_gain_f2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_gain_f2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_gain_f2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_gain_f2);
      union {
        double real;
        uint64_t base;
      } u_left_gain_f3;
      u_left_gain_f3.real = this->left_gain_f3;
      *(outbuffer + offset + 0) = (u_left_gain_f3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_gain_f3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_gain_f3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_gain_f3.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_gain_f3.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_gain_f3.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_gain_f3.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_gain_f3.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_gain_f3);
      union {
        double real;
        uint64_t base;
      } u_right_bias_f1;
      u_right_bias_f1.real = this->right_bias_f1;
      *(outbuffer + offset + 0) = (u_right_bias_f1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_bias_f1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_bias_f1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_bias_f1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_bias_f1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_bias_f1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_bias_f1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_bias_f1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_bias_f1);
      union {
        double real;
        uint64_t base;
      } u_right_bias_f2;
      u_right_bias_f2.real = this->right_bias_f2;
      *(outbuffer + offset + 0) = (u_right_bias_f2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_bias_f2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_bias_f2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_bias_f2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_bias_f2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_bias_f2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_bias_f2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_bias_f2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_bias_f2);
      union {
        double real;
        uint64_t base;
      } u_right_bias_f3;
      u_right_bias_f3.real = this->right_bias_f3;
      *(outbuffer + offset + 0) = (u_right_bias_f3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_bias_f3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_bias_f3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_bias_f3.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_bias_f3.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_bias_f3.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_bias_f3.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_bias_f3.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_bias_f3);
      union {
        double real;
        uint64_t base;
      } u_right_gain_f1;
      u_right_gain_f1.real = this->right_gain_f1;
      *(outbuffer + offset + 0) = (u_right_gain_f1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_gain_f1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_gain_f1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_gain_f1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_gain_f1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_gain_f1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_gain_f1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_gain_f1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_gain_f1);
      union {
        double real;
        uint64_t base;
      } u_right_gain_f2;
      u_right_gain_f2.real = this->right_gain_f2;
      *(outbuffer + offset + 0) = (u_right_gain_f2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_gain_f2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_gain_f2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_gain_f2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_gain_f2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_gain_f2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_gain_f2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_gain_f2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_gain_f2);
      union {
        double real;
        uint64_t base;
      } u_right_gain_f3;
      u_right_gain_f3.real = this->right_gain_f3;
      *(outbuffer + offset + 0) = (u_right_gain_f3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_gain_f3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_gain_f3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_gain_f3.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_gain_f3.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_gain_f3.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_gain_f3.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_gain_f3.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_gain_f3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_left_bias_f1;
      u_left_bias_f1.base = 0;
      u_left_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_bias_f1 = u_left_bias_f1.real;
      offset += sizeof(this->left_bias_f1);
      union {
        double real;
        uint64_t base;
      } u_left_bias_f2;
      u_left_bias_f2.base = 0;
      u_left_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_bias_f2 = u_left_bias_f2.real;
      offset += sizeof(this->left_bias_f2);
      union {
        double real;
        uint64_t base;
      } u_left_bias_f3;
      u_left_bias_f3.base = 0;
      u_left_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_bias_f3 = u_left_bias_f3.real;
      offset += sizeof(this->left_bias_f3);
      union {
        double real;
        uint64_t base;
      } u_left_gain_f1;
      u_left_gain_f1.base = 0;
      u_left_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_gain_f1 = u_left_gain_f1.real;
      offset += sizeof(this->left_gain_f1);
      union {
        double real;
        uint64_t base;
      } u_left_gain_f2;
      u_left_gain_f2.base = 0;
      u_left_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_gain_f2 = u_left_gain_f2.real;
      offset += sizeof(this->left_gain_f2);
      union {
        double real;
        uint64_t base;
      } u_left_gain_f3;
      u_left_gain_f3.base = 0;
      u_left_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_gain_f3 = u_left_gain_f3.real;
      offset += sizeof(this->left_gain_f3);
      union {
        double real;
        uint64_t base;
      } u_right_bias_f1;
      u_right_bias_f1.base = 0;
      u_right_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_bias_f1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_bias_f1 = u_right_bias_f1.real;
      offset += sizeof(this->right_bias_f1);
      union {
        double real;
        uint64_t base;
      } u_right_bias_f2;
      u_right_bias_f2.base = 0;
      u_right_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_bias_f2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_bias_f2 = u_right_bias_f2.real;
      offset += sizeof(this->right_bias_f2);
      union {
        double real;
        uint64_t base;
      } u_right_bias_f3;
      u_right_bias_f3.base = 0;
      u_right_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_bias_f3.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_bias_f3 = u_right_bias_f3.real;
      offset += sizeof(this->right_bias_f3);
      union {
        double real;
        uint64_t base;
      } u_right_gain_f1;
      u_right_gain_f1.base = 0;
      u_right_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_gain_f1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_gain_f1 = u_right_gain_f1.real;
      offset += sizeof(this->right_gain_f1);
      union {
        double real;
        uint64_t base;
      } u_right_gain_f2;
      u_right_gain_f2.base = 0;
      u_right_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_gain_f2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_gain_f2 = u_right_gain_f2.real;
      offset += sizeof(this->right_gain_f2);
      union {
        double real;
        uint64_t base;
      } u_right_gain_f3;
      u_right_gain_f3.base = 0;
      u_right_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_gain_f3.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_gain_f3 = u_right_gain_f3.real;
      offset += sizeof(this->right_gain_f3);
     return offset;
    }

    const char * getType(){ return YAML_VALUES; };
    const char * getMD5(){ return "599f443ae0f39cd3fc016639ad207690"; };

  };

  class yaml_values {
    public:
    typedef yaml_valuesRequest Request;
    typedef yaml_valuesResponse Response;
  };

}
#endif
