; Auto-generated. Do not edit!


(cl:in-package motor-srv)


;//! \htmlinclude zero_point-request.msg.html

(cl:defclass <zero_point-request> (roslisp-msg-protocol:ros-message)
  ((num
    :reader num
    :initarg :num
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass zero_point-request (<zero_point-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <zero_point-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'zero_point-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor-srv:<zero_point-request> is deprecated: use motor-srv:zero_point-request instead.")))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <zero_point-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:num-val is deprecated.  Use motor-srv:num instead.")
  (num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <zero_point-request>) ostream)
  "Serializes a message object of type '<zero_point-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'num) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <zero_point-request>) istream)
  "Deserializes a message object of type '<zero_point-request>"
    (cl:setf (cl:slot-value msg 'num) (cl:not (cl:zerop (cl:read-byte istream))))
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
  "c332db600bdaaaed12be73a022ed8ae1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'zero_point-request)))
  "Returns md5sum for a message object of type 'zero_point-request"
  "c332db600bdaaaed12be73a022ed8ae1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<zero_point-request>)))
  "Returns full string definition for message of type '<zero_point-request>"
  (cl:format cl:nil "bool num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'zero_point-request)))
  "Returns full string definition for message of type 'zero_point-request"
  (cl:format cl:nil "bool num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <zero_point-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <zero_point-request>))
  "Converts a ROS message object to a list"
  (cl:list 'zero_point-request
    (cl:cons ':num (num msg))
))
;//! \htmlinclude zero_point-response.msg.html

(cl:defclass <zero_point-response> (roslisp-msg-protocol:ros-message)
  ((zero_x
    :reader zero_x
    :initarg :zero_x
    :type cl:integer
    :initform 0)
   (zero_y
    :reader zero_y
    :initarg :zero_y
    :type cl:integer
    :initform 0)
   (zero_z
    :reader zero_z
    :initarg :zero_z
    :type cl:integer
    :initform 0))
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
  (cl:let* ((signed (cl:slot-value msg 'zero_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'zero_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'zero_z)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <zero_point-response>) istream)
  "Deserializes a message object of type '<zero_point-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'zero_x) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'zero_y) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'zero_z) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
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
  "c332db600bdaaaed12be73a022ed8ae1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'zero_point-response)))
  "Returns md5sum for a message object of type 'zero_point-response"
  "c332db600bdaaaed12be73a022ed8ae1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<zero_point-response>)))
  "Returns full string definition for message of type '<zero_point-response>"
  (cl:format cl:nil "int64 zero_x~%int64 zero_y~%int64 zero_z~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'zero_point-response)))
  "Returns full string definition for message of type 'zero_point-response"
  (cl:format cl:nil "int64 zero_x~%int64 zero_y~%int64 zero_z~%~%~%~%"))
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