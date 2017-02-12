; Auto-generated. Do not edit!


(cl:in-package motor-msg)


;//! \htmlinclude skate_command.msg.html

(cl:defclass <skate_command> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (calibration_enable
    :reader calibration_enable
    :initarg :calibration_enable
    :type cl:integer
    :initform 0)
   (command_target
    :reader command_target
    :initarg :command_target
    :type cl:integer
    :initform 0))
)

(cl:defclass skate_command (<skate_command>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <skate_command>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'skate_command)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor-msg:<skate_command> is deprecated: use motor-msg:skate_command instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <skate_command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:header-val is deprecated.  Use motor-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'calibration_enable-val :lambda-list '(m))
(cl:defmethod calibration_enable-val ((m <skate_command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:calibration_enable-val is deprecated.  Use motor-msg:calibration_enable instead.")
  (calibration_enable m))

(cl:ensure-generic-function 'command_target-val :lambda-list '(m))
(cl:defmethod command_target-val ((m <skate_command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:command_target-val is deprecated.  Use motor-msg:command_target instead.")
  (command_target m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <skate_command>) ostream)
  "Serializes a message object of type '<skate_command>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'calibration_enable)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'command_target)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <skate_command>) istream)
  "Deserializes a message object of type '<skate_command>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'calibration_enable) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'command_target) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<skate_command>)))
  "Returns string type for a message object of type '<skate_command>"
  "motor/skate_command")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'skate_command)))
  "Returns string type for a message object of type 'skate_command"
  "motor/skate_command")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<skate_command>)))
  "Returns md5sum for a message object of type '<skate_command>"
  "eb77e7d8ddea947728653dde426e34c7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'skate_command)))
  "Returns md5sum for a message object of type 'skate_command"
  "eb77e7d8ddea947728653dde426e34c7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<skate_command>)))
  "Returns full string definition for message of type '<skate_command>"
  (cl:format cl:nil "Header header~%int32 calibration_enable~%int32 command_target~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'skate_command)))
  "Returns full string definition for message of type 'skate_command"
  (cl:format cl:nil "Header header~%int32 calibration_enable~%int32 command_target~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <skate_command>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <skate_command>))
  "Converts a ROS message object to a list"
  (cl:list 'skate_command
    (cl:cons ':header (header msg))
    (cl:cons ':calibration_enable (calibration_enable msg))
    (cl:cons ':command_target (command_target msg))
))
