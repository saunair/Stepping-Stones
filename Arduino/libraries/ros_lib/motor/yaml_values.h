#ifndef _ROS_SERVICE_yaml_values_h
#define _ROS_SERVICE_yaml_values_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace motor
{

static const char YAML_VALUES[] = "motor/yaml_values";

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
      typedef float _left_bias_f1_type;
      _left_bias_f1_type left_bias_f1;
      typedef float _left_bias_f2_type;
      _left_bias_f2_type left_bias_f2;
      typedef float _left_bias_f3_type;
      _left_bias_f3_type left_bias_f3;
      typedef float _left_gain_f1_type;
      _left_gain_f1_type left_gain_f1;
      typedef float _left_gain_f2_type;
      _left_gain_f2_type left_gain_f2;
      typedef float _left_gain_f3_type;
      _left_gain_f3_type left_gain_f3;
      typedef float _right_bias_f1_type;
      _right_bias_f1_type right_bias_f1;
      typedef float _right_bias_f2_type;
      _right_bias_f2_type right_bias_f2;
      typedef float _right_bias_f3_type;
      _right_bias_f3_type right_bias_f3;
      typedef float _right_gain_f1_type;
      _right_gain_f1_type right_gain_f1;
      typedef float _right_gain_f2_type;
      _right_gain_f2_type right_gain_f2;
      typedef float _right_gain_f3_type;
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
      offset += serializeAvrFloat64(outbuffer + offset, this->left_bias_f1);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_bias_f2);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_bias_f3);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_gain_f1);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_gain_f2);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_gain_f3);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_bias_f1);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_bias_f2);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_bias_f3);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_gain_f1);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_gain_f2);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_gain_f3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_bias_f1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_bias_f2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_bias_f3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_gain_f1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_gain_f2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_gain_f3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_bias_f1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_bias_f2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_bias_f3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_gain_f1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_gain_f2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_gain_f3));
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
