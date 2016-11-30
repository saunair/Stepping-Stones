; Auto-generated. Do not edit!


(cl:in-package motor-msg)


;//! \htmlinclude states.msg.html

(cl:defclass <states> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (state
    :reader state
    :initarg :state
    :type cl:integer
    :initform 0)
   (set_point
    :reader set_point
    :initarg :set_point
    :type cl:integer
    :initform 0))
)

(cl:defclass states (<states>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <states>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'states)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor-msg:<states> is deprecated: use motor-msg:states instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <states>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:header-val is deprecated.  Use motor-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <states>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:state-val is deprecated.  Use motor-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'set_point-val :lambda-list '(m))
(cl:defmethod set_point-val ((m <states>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:set_point-val is deprecated.  Use motor-msg:set_point instead.")
  (set_point m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <states>) ostream)
  "Serializes a message object of type '<states>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'state)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'set_point)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <states>) istream)
  "Deserializes a message object of type '<states>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'state) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'set_point) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<states>)))
  "Returns string type for a message object of type '<states>"
  "motor/states")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'states)))
  "Returns string type for a message object of type 'states"
  "motor/states")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<states>)))
  "Returns md5sum for a message object of type '<states>"
  "7c54f357503453db8f84f3b13454e6f8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'states)))
  "Returns md5sum for a message object of type 'states"
  "7c54f357503453db8f84f3b13454e6f8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<states>)))
  "Returns full string definition for message of type '<states>"
  (cl:format cl:nil "Header header~%int32 state~%int32 set_point~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'states)))
  "Returns full string definition for message of type 'states"
  (cl:format cl:nil "Header header~%int32 state~%int32 set_point~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <states>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <states>))
  "Converts a ROS message object to a list"
  (cl:list 'states
    (cl:cons ':header (header msg))
    (cl:cons ':state (state msg))
    (cl:cons ':set_point (set_point msg))
))
