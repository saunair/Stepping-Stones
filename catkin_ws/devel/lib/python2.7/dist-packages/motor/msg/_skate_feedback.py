# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from motor/skate_feedback.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class skate_feedback(genpy.Message):
  _md5sum = "4fcef49017325db1881c7de732fff139"
  _type = "motor/skate_feedback"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """Header header
int16 force_front_outer
int16 force_front_inner
int16 force_rear
float32 imu_quat_x
float32 imu_quat_y
float32 imu_quat_z
float32 imu_quat_w
float32 imu_accel_x
float32 imu_accel_y
float32 imu_accel_z
float32 imu_rate_x
float32 imu_rate_y 
float32 imu_rate_z
float32 velocity_cmd_rear
float32 velocity_cmd_front
uint8 skate_fault
float32 position_filt_rear
float32 position_filt_front
float32 velocity_filt_rear
float32 velocity_filt_front
bool dead_man_enable
float32 controller_target
byte skate_mode

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
"""
  __slots__ = ['header','force_front_outer','force_front_inner','force_rear','imu_quat_x','imu_quat_y','imu_quat_z','imu_quat_w','imu_accel_x','imu_accel_y','imu_accel_z','imu_rate_x','imu_rate_y','imu_rate_z','velocity_cmd_rear','velocity_cmd_front','skate_fault','position_filt_rear','position_filt_front','velocity_filt_rear','velocity_filt_front','dead_man_enable','controller_target','skate_mode']
  _slot_types = ['std_msgs/Header','int16','int16','int16','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','uint8','float32','float32','float32','float32','bool','float32','byte']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,force_front_outer,force_front_inner,force_rear,imu_quat_x,imu_quat_y,imu_quat_z,imu_quat_w,imu_accel_x,imu_accel_y,imu_accel_z,imu_rate_x,imu_rate_y,imu_rate_z,velocity_cmd_rear,velocity_cmd_front,skate_fault,position_filt_rear,position_filt_front,velocity_filt_rear,velocity_filt_front,dead_man_enable,controller_target,skate_mode

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(skate_feedback, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.force_front_outer is None:
        self.force_front_outer = 0
      if self.force_front_inner is None:
        self.force_front_inner = 0
      if self.force_rear is None:
        self.force_rear = 0
      if self.imu_quat_x is None:
        self.imu_quat_x = 0.
      if self.imu_quat_y is None:
        self.imu_quat_y = 0.
      if self.imu_quat_z is None:
        self.imu_quat_z = 0.
      if self.imu_quat_w is None:
        self.imu_quat_w = 0.
      if self.imu_accel_x is None:
        self.imu_accel_x = 0.
      if self.imu_accel_y is None:
        self.imu_accel_y = 0.
      if self.imu_accel_z is None:
        self.imu_accel_z = 0.
      if self.imu_rate_x is None:
        self.imu_rate_x = 0.
      if self.imu_rate_y is None:
        self.imu_rate_y = 0.
      if self.imu_rate_z is None:
        self.imu_rate_z = 0.
      if self.velocity_cmd_rear is None:
        self.velocity_cmd_rear = 0.
      if self.velocity_cmd_front is None:
        self.velocity_cmd_front = 0.
      if self.skate_fault is None:
        self.skate_fault = 0
      if self.position_filt_rear is None:
        self.position_filt_rear = 0.
      if self.position_filt_front is None:
        self.position_filt_front = 0.
      if self.velocity_filt_rear is None:
        self.velocity_filt_rear = 0.
      if self.velocity_filt_front is None:
        self.velocity_filt_front = 0.
      if self.dead_man_enable is None:
        self.dead_man_enable = False
      if self.controller_target is None:
        self.controller_target = 0.
      if self.skate_mode is None:
        self.skate_mode = 0
    else:
      self.header = std_msgs.msg.Header()
      self.force_front_outer = 0
      self.force_front_inner = 0
      self.force_rear = 0
      self.imu_quat_x = 0.
      self.imu_quat_y = 0.
      self.imu_quat_z = 0.
      self.imu_quat_w = 0.
      self.imu_accel_x = 0.
      self.imu_accel_y = 0.
      self.imu_accel_z = 0.
      self.imu_rate_x = 0.
      self.imu_rate_y = 0.
      self.imu_rate_z = 0.
      self.velocity_cmd_rear = 0.
      self.velocity_cmd_front = 0.
      self.skate_fault = 0
      self.position_filt_rear = 0.
      self.position_filt_front = 0.
      self.velocity_filt_rear = 0.
      self.velocity_filt_front = 0.
      self.dead_man_enable = False
      self.controller_target = 0.
      self.skate_mode = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_3h12fB4fBfb.pack(_x.force_front_outer, _x.force_front_inner, _x.force_rear, _x.imu_quat_x, _x.imu_quat_y, _x.imu_quat_z, _x.imu_quat_w, _x.imu_accel_x, _x.imu_accel_y, _x.imu_accel_z, _x.imu_rate_x, _x.imu_rate_y, _x.imu_rate_z, _x.velocity_cmd_rear, _x.velocity_cmd_front, _x.skate_fault, _x.position_filt_rear, _x.position_filt_front, _x.velocity_filt_rear, _x.velocity_filt_front, _x.dead_man_enable, _x.controller_target, _x.skate_mode))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 77
      (_x.force_front_outer, _x.force_front_inner, _x.force_rear, _x.imu_quat_x, _x.imu_quat_y, _x.imu_quat_z, _x.imu_quat_w, _x.imu_accel_x, _x.imu_accel_y, _x.imu_accel_z, _x.imu_rate_x, _x.imu_rate_y, _x.imu_rate_z, _x.velocity_cmd_rear, _x.velocity_cmd_front, _x.skate_fault, _x.position_filt_rear, _x.position_filt_front, _x.velocity_filt_rear, _x.velocity_filt_front, _x.dead_man_enable, _x.controller_target, _x.skate_mode,) = _struct_3h12fB4fBfb.unpack(str[start:end])
      self.dead_man_enable = bool(self.dead_man_enable)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_3h12fB4fBfb.pack(_x.force_front_outer, _x.force_front_inner, _x.force_rear, _x.imu_quat_x, _x.imu_quat_y, _x.imu_quat_z, _x.imu_quat_w, _x.imu_accel_x, _x.imu_accel_y, _x.imu_accel_z, _x.imu_rate_x, _x.imu_rate_y, _x.imu_rate_z, _x.velocity_cmd_rear, _x.velocity_cmd_front, _x.skate_fault, _x.position_filt_rear, _x.position_filt_front, _x.velocity_filt_rear, _x.velocity_filt_front, _x.dead_man_enable, _x.controller_target, _x.skate_mode))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 77
      (_x.force_front_outer, _x.force_front_inner, _x.force_rear, _x.imu_quat_x, _x.imu_quat_y, _x.imu_quat_z, _x.imu_quat_w, _x.imu_accel_x, _x.imu_accel_y, _x.imu_accel_z, _x.imu_rate_x, _x.imu_rate_y, _x.imu_rate_z, _x.velocity_cmd_rear, _x.velocity_cmd_front, _x.skate_fault, _x.position_filt_rear, _x.position_filt_front, _x.velocity_filt_rear, _x.velocity_filt_front, _x.dead_man_enable, _x.controller_target, _x.skate_mode,) = _struct_3h12fB4fBfb.unpack(str[start:end])
      self.dead_man_enable = bool(self.dead_man_enable)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_3I = struct.Struct("<3I")
_struct_3h12fB4fBfb = struct.Struct("<3h12fB4fBfb")
