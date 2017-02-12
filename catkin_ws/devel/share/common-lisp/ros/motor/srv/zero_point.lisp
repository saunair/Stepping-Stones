; Auto-generated. Do not edit!


(cl:in-package motor-srv)


;//! \htmlinclude zero_point-request.msg.html

(cl:defclass <zero_point-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass zero_point-request (<zero_point-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <zero_point-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'zero_point-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor-srv:<zero_point-request> is deprecated: use motor-srv:zero_point-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <zero_point-request>) ostream)
  "Serializes a message object of type '<zero_point-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <zero_point-request>) istream)
  "Deserializes a message object of type '<zero_point-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<zero_point-request>)))
  "Returns string type for a service object of type '<zero_point-request>"
  "motor/zero_pointRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'zero_point-request)))
  "Returns string type for a service object of type 'zero_point-request"
  "motor/zero_pointRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<zero_point-request>)))
  "Returns md5sum for a message object of type '<zero_point-request>"
  "c0900cb104c9c04a5c3b1edc43765f2a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'zero_point-request)))
  "Returns md5sum for a message object of type 'zero_point-request"
  "c0900cb104c9c04a5c3b1edc43765f2a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<zero_point-request>)))
  "Returns full string definition for message of type '<zero_point-request>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'zero_point-request)))
  "Returns full string definition for message of type 'zero_point-request"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <zero_point-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <zero_point-request>))
  "Converts a ROS message object to a list"
  (cl:list 'zero_point-request
))
;//! \htmlinclude zero_point-response.msg.html

(cl:defclass <zero_point-response> (roslisp-msg-protocol:ros-message)
  ((zero_x
    :reader zero_x
    :initarg :zero_x
    :type cl:float
    :initform 0.0)
   (zero_y
    :reader zero_y
    :initarg :zero_y
    :type cl:float
    :initform 0.0)
   (zero_z
    :reader zero_z
    :initarg :zero_z
    :type cl:float
    :initform 0.0))
)

(cl:defclass zero_point-response (<zero_point-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <zero_point-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'zero_point-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor-srv:<zero_point-response> is deprecated: use motor-srv:zero_point-response instead.")))

(cl:ensure-generic-function 'zero_x-val :lambda-list '(m))
(cl:defmethod zero_x-val ((m <zero_point-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:zero_x-val is deprecated.  Use motor-srv:zero_x instead.")
  (zero_x m))

(cl:ensure-generic-function 'zero_y-val :lambda-list '(m))
(cl:defmethod zero_y-val ((m <zero_point-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:zero_y-val is deprecated.  Use motor-srv:zero_y instead.")
  (zero_y m))

(cl:ensure-generic-function 'zero_z-val :lambda-list '(m))
(cl:defmethod zero_z-val ((m <zero_point-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:zero_z-val is deprecated.  Use motor-srv:zero_z instead.")
  (zero_z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <zero_point-response>) ostream)
  "Serializes a message object of type '<zero_point-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'zero_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'zero_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'zero_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <zero_point-response>) istream)
  "Deserializes a message object of type '<zero_point-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zero_x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zero_y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zero_z) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<zero_point-response>)))
  "Returns string type for a service object of type '<zero_point-response>"
  "motor/zero_pointResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'zero_point-response)))
  "Returns string type for a service object of type 'zero_point-response"
  "motor/zero_pointResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<zero_point-response>)))
  "Returns md5sum for a message object of type '<zero_point-response>"
  "c0900cb104c9c04a5c3b1edc43765f2a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'zero_point-response)))
  "Returns md5sum for a message object of type 'zero_point-response"
  "c0900cb104c9c04a5c3b1edc43765f2a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<zero_point-response>)))
  "Returns full string definition for message of type '<zero_point-response>"
  (cl:format cl:nil "float64 zero_x~%float64 zero_y~%float64 zero_z~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'zero_point-response)))
  "Returns full string definition for message of type 'zero_point-response"
  (cl:format cl:nil "float64 zero_x~%float64 zero_y~%float64 zero_z~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <zero_point-response>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <zero_point-response>))
  "Converts a ROS message object to a list"
  (cl:list 'zero_point-response
    (cl:cons ':zero_x (zero_x msg))
    (cl:cons ':zero_y (zero_y msg))
    (cl:cons ':zero_z (zero_z msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'zero_point)))
  'zero_point-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'zero_point)))
  'zero_point-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'zero_point)))
  "Returns string type for a service object of type '<zero_point>"
  "motor/zero_point")