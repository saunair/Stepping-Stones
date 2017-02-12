; Auto-generated. Do not edit!


(cl:in-package motor-srv)


;//! \htmlinclude yaml_values-request.msg.html

(cl:defclass <yaml_values-request> (roslisp-msg-protocol:ros-message)
  ((num
    :reader num
    :initarg :num
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass yaml_values-request (<yaml_values-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <yaml_values-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'yaml_values-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor-srv:<yaml_values-request> is deprecated: use motor-srv:yaml_values-request instead.")))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <yaml_values-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:num-val is deprecated.  Use motor-srv:num instead.")
  (num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <yaml_values-request>) ostream)
  "Serializes a message object of type '<yaml_values-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'num) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <yaml_values-request>) istream)
  "Deserializes a message object of type '<yaml_values-request>"
    (cl:setf (cl:slot-value msg 'num) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<yaml_values-request>)))
  "Returns string type for a service object of type '<yaml_values-request>"
  "motor/yaml_valuesRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'yaml_values-request)))
  "Returns string type for a service object of type 'yaml_values-request"
  "motor/yaml_valuesRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<yaml_values-request>)))
  "Returns md5sum for a message object of type '<yaml_values-request>"
  "b0738748015b35d4efcebe36d64e715c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'yaml_values-request)))
  "Returns md5sum for a message object of type 'yaml_values-request"
  "b0738748015b35d4efcebe36d64e715c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<yaml_values-request>)))
  "Returns full string definition for message of type '<yaml_values-request>"
  (cl:format cl:nil "bool num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'yaml_values-request)))
  "Returns full string definition for message of type 'yaml_values-request"
  (cl:format cl:nil "bool num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <yaml_values-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <yaml_values-request>))
  "Converts a ROS message object to a list"
  (cl:list 'yaml_values-request
    (cl:cons ':num (num msg))
))
;//! \htmlinclude yaml_values-response.msg.html

(cl:defclass <yaml_values-response> (roslisp-msg-protocol:ros-message)
  ((left_bias_f1
    :reader left_bias_f1
    :initarg :left_bias_f1
    :type cl:float
    :initform 0.0)
   (left_bias_f2
    :reader left_bias_f2
    :initarg :left_bias_f2
    :type cl:float
    :initform 0.0)
   (left_bias_f3
    :reader left_bias_f3
    :initarg :left_bias_f3
    :type cl:float
    :initform 0.0)
   (left_gain_f1
    :reader left_gain_f1
    :initarg :left_gain_f1
    :type cl:float
    :initform 0.0)
   (left_gain_f2
    :reader left_gain_f2
    :initarg :left_gain_f2
    :type cl:float
    :initform 0.0)
   (left_gain_f3
    :reader left_gain_f3
    :initarg :left_gain_f3
    :type cl:float
    :initform 0.0)
   (right_bias_f1
    :reader right_bias_f1
    :initarg :right_bias_f1
    :type cl:float
    :initform 0.0)
   (right_bias_f2
    :reader right_bias_f2
    :initarg :right_bias_f2
    :type cl:float
    :initform 0.0)
   (right_bias_f3
    :reader right_bias_f3
    :initarg :right_bias_f3
    :type cl:float
    :initform 0.0)
   (right_gain_f1
    :reader right_gain_f1
    :initarg :right_gain_f1
    :type cl:float
    :initform 0.0)
   (right_gain_f2
    :reader right_gain_f2
    :initarg :right_gain_f2
    :type cl:float
    :initform 0.0)
   (right_gain_f3
    :reader right_gain_f3
    :initarg :right_gain_f3
    :type cl:float
    :initform 0.0))
)

(cl:defclass yaml_values-response (<yaml_values-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <yaml_values-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'yaml_values-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor-srv:<yaml_values-response> is deprecated: use motor-srv:yaml_values-response instead.")))

(cl:ensure-generic-function 'left_bias_f1-val :lambda-list '(m))
(cl:defmethod left_bias_f1-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:left_bias_f1-val is deprecated.  Use motor-srv:left_bias_f1 instead.")
  (left_bias_f1 m))

(cl:ensure-generic-function 'left_bias_f2-val :lambda-list '(m))
(cl:defmethod left_bias_f2-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:left_bias_f2-val is deprecated.  Use motor-srv:left_bias_f2 instead.")
  (left_bias_f2 m))

(cl:ensure-generic-function 'left_bias_f3-val :lambda-list '(m))
(cl:defmethod left_bias_f3-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:left_bias_f3-val is deprecated.  Use motor-srv:left_bias_f3 instead.")
  (left_bias_f3 m))

(cl:ensure-generic-function 'left_gain_f1-val :lambda-list '(m))
(cl:defmethod left_gain_f1-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:left_gain_f1-val is deprecated.  Use motor-srv:left_gain_f1 instead.")
  (left_gain_f1 m))

(cl:ensure-generic-function 'left_gain_f2-val :lambda-list '(m))
(cl:defmethod left_gain_f2-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:left_gain_f2-val is deprecated.  Use motor-srv:left_gain_f2 instead.")
  (left_gain_f2 m))

(cl:ensure-generic-function 'left_gain_f3-val :lambda-list '(m))
(cl:defmethod left_gain_f3-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:left_gain_f3-val is deprecated.  Use motor-srv:left_gain_f3 instead.")
  (left_gain_f3 m))

(cl:ensure-generic-function 'right_bias_f1-val :lambda-list '(m))
(cl:defmethod right_bias_f1-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:right_bias_f1-val is deprecated.  Use motor-srv:right_bias_f1 instead.")
  (right_bias_f1 m))

(cl:ensure-generic-function 'right_bias_f2-val :lambda-list '(m))
(cl:defmethod right_bias_f2-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:right_bias_f2-val is deprecated.  Use motor-srv:right_bias_f2 instead.")
  (right_bias_f2 m))

(cl:ensure-generic-function 'right_bias_f3-val :lambda-list '(m))
(cl:defmethod right_bias_f3-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:right_bias_f3-val is deprecated.  Use motor-srv:right_bias_f3 instead.")
  (right_bias_f3 m))

(cl:ensure-generic-function 'right_gain_f1-val :lambda-list '(m))
(cl:defmethod right_gain_f1-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:right_gain_f1-val is deprecated.  Use motor-srv:right_gain_f1 instead.")
  (right_gain_f1 m))

(cl:ensure-generic-function 'right_gain_f2-val :lambda-list '(m))
(cl:defmethod right_gain_f2-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:right_gain_f2-val is deprecated.  Use motor-srv:right_gain_f2 instead.")
  (right_gain_f2 m))

(cl:ensure-generic-function 'right_gain_f3-val :lambda-list '(m))
(cl:defmethod right_gain_f3-val ((m <yaml_values-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-srv:right_gain_f3-val is deprecated.  Use motor-srv:right_gain_f3 instead.")
  (right_gain_f3 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <yaml_values-response>) ostream)
  "Serializes a message object of type '<yaml_values-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_bias_f1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_bias_f2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_bias_f3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_gain_f1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_gain_f2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_gain_f3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_bias_f1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_bias_f2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_bias_f3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_gain_f1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_gain_f2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_gain_f3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <yaml_values-response>) istream)
  "Deserializes a message object of type '<yaml_values-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_bias_f1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_bias_f2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_bias_f3) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_gain_f1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_gain_f2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_gain_f3) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_bias_f1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_bias_f2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_bias_f3) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_gain_f1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_gain_f2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_gain_f3) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<yaml_values-response>)))
  "Returns string type for a service object of type '<yaml_values-response>"
  "motor/yaml_valuesResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'yaml_values-response)))
  "Returns string type for a service object of type 'yaml_values-response"
  "motor/yaml_valuesResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<yaml_values-response>)))
  "Returns md5sum for a message object of type '<yaml_values-response>"
  "b0738748015b35d4efcebe36d64e715c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'yaml_values-response)))
  "Returns md5sum for a message object of type 'yaml_values-response"
  "b0738748015b35d4efcebe36d64e715c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<yaml_values-response>)))
  "Returns full string definition for message of type '<yaml_values-response>"
  (cl:format cl:nil "float64 left_bias_f1~%float64 left_bias_f2~%float64 left_bias_f3~%float64 left_gain_f1~%float64 left_gain_f2~%float64 left_gain_f3~%float64 right_bias_f1~%float64 right_bias_f2~%float64 right_bias_f3~%float64 right_gain_f1~%float64 right_gain_f2~%float64 right_gain_f3~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'yaml_values-response)))
  "Returns full string definition for message of type 'yaml_values-response"
  (cl:format cl:nil "float64 left_bias_f1~%float64 left_bias_f2~%float64 left_bias_f3~%float64 left_gain_f1~%float64 left_gain_f2~%float64 left_gain_f3~%float64 right_bias_f1~%float64 right_bias_f2~%float64 right_bias_f3~%float64 right_gain_f1~%float64 right_gain_f2~%float64 right_gain_f3~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <yaml_values-response>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <yaml_values-response>))
  "Converts a ROS message object to a list"
  (cl:list 'yaml_values-response
    (cl:cons ':left_bias_f1 (left_bias_f1 msg))
    (cl:cons ':left_bias_f2 (left_bias_f2 msg))
    (cl:cons ':left_bias_f3 (left_bias_f3 msg))
    (cl:cons ':left_gain_f1 (left_gain_f1 msg))
    (cl:cons ':left_gain_f2 (left_gain_f2 msg))
    (cl:cons ':left_gain_f3 (left_gain_f3 msg))
    (cl:cons ':right_bias_f1 (right_bias_f1 msg))
    (cl:cons ':right_bias_f2 (right_bias_f2 msg))
    (cl:cons ':right_bias_f3 (right_bias_f3 msg))
    (cl:cons ':right_gain_f1 (right_gain_f1 msg))
    (cl:cons ':right_gain_f2 (right_gain_f2 msg))
    (cl:cons ':right_gain_f3 (right_gain_f3 msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'yaml_values)))
  'yaml_values-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'yaml_values)))
  'yaml_values-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'yaml_values)))
  "Returns string type for a service object of type '<yaml_values>"
  "motor/yaml_values")