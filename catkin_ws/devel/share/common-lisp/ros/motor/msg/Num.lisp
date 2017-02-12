; Auto-generated. Do not edit!


(cl:in-package motor-msg)


;//! \htmlinclude Num.msg.html

(cl:defclass <Num> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (force_front_outer
    :reader force_front_outer
    :initarg :force_front_outer
    :type cl:fixnum
    :initform 0)
   (force_front_inner
    :reader force_front_inner
    :initarg :force_front_inner
    :type cl:fixnum
    :initform 0)
   (force_rear
    :reader force_rear
    :initarg :force_rear
    :type cl:fixnum
    :initform 0)
   (imu_quat_x
    :reader imu_quat_x
    :initarg :imu_quat_x
    :type cl:float
    :initform 0.0)
   (imu_quat_y
    :reader imu_quat_y
    :initarg :imu_quat_y
    :type cl:float
    :initform 0.0)
   (imu_quat_z
    :reader imu_quat_z
    :initarg :imu_quat_z
    :type cl:float
    :initform 0.0)
   (imu_quat_w
    :reader imu_quat_w
    :initarg :imu_quat_w
    :type cl:float
    :initform 0.0)
   (imu_accel_x
    :reader imu_accel_x
    :initarg :imu_accel_x
    :type cl:float
    :initform 0.0)
   (imu_accel_y
    :reader imu_accel_y
    :initarg :imu_accel_y
    :type cl:float
    :initform 0.0)
   (imu_accel_z
    :reader imu_accel_z
    :initarg :imu_accel_z
    :type cl:float
    :initform 0.0)
   (imu_rate_x
    :reader imu_rate_x
    :initarg :imu_rate_x
    :type cl:float
    :initform 0.0)
   (imu_rate_y
    :reader imu_rate_y
    :initarg :imu_rate_y
    :type cl:float
    :initform 0.0)
   (imu_rate_z
    :reader imu_rate_z
    :initarg :imu_rate_z
    :type cl:float
    :initform 0.0)
   (velocity_cmd_rear
    :reader velocity_cmd_rear
    :initarg :velocity_cmd_rear
    :type cl:float
    :initform 0.0)
   (velocity_cmd_front
    :reader velocity_cmd_front
    :initarg :velocity_cmd_front
    :type cl:float
    :initform 0.0)
   (skate_fault
    :reader skate_fault
    :initarg :skate_fault
    :type cl:fixnum
    :initform 0)
   (position_filt_rear
    :reader position_filt_rear
    :initarg :position_filt_rear
    :type cl:float
    :initform 0.0)
   (position_filt_front
    :reader position_filt_front
    :initarg :position_filt_front
    :type cl:float
    :initform 0.0)
   (velocity_filt_rear
    :reader velocity_filt_rear
    :initarg :velocity_filt_rear
    :type cl:float
    :initform 0.0)
   (velocity_filt_front
    :reader velocity_filt_front
    :initarg :velocity_filt_front
    :type cl:float
    :initform 0.0)
   (dead_man_enable
    :reader dead_man_enable
    :initarg :dead_man_enable
    :type cl:boolean
    :initform cl:nil)
   (controller_target
    :reader controller_target
    :initarg :controller_target
    :type cl:float
    :initform 0.0)
   (skate_mode
    :reader skate_mode
    :initarg :skate_mode
    :type cl:integer
    :initform 0))
)

(cl:defclass Num (<Num>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Num>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Num)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor-msg:<Num> is deprecated: use motor-msg:Num instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:header-val is deprecated.  Use motor-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'force_front_outer-val :lambda-list '(m))
(cl:defmethod force_front_outer-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:force_front_outer-val is deprecated.  Use motor-msg:force_front_outer instead.")
  (force_front_outer m))

(cl:ensure-generic-function 'force_front_inner-val :lambda-list '(m))
(cl:defmethod force_front_inner-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:force_front_inner-val is deprecated.  Use motor-msg:force_front_inner instead.")
  (force_front_inner m))

(cl:ensure-generic-function 'force_rear-val :lambda-list '(m))
(cl:defmethod force_rear-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:force_rear-val is deprecated.  Use motor-msg:force_rear instead.")
  (force_rear m))

(cl:ensure-generic-function 'imu_quat_x-val :lambda-list '(m))
(cl:defmethod imu_quat_x-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_quat_x-val is deprecated.  Use motor-msg:imu_quat_x instead.")
  (imu_quat_x m))

(cl:ensure-generic-function 'imu_quat_y-val :lambda-list '(m))
(cl:defmethod imu_quat_y-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_quat_y-val is deprecated.  Use motor-msg:imu_quat_y instead.")
  (imu_quat_y m))

(cl:ensure-generic-function 'imu_quat_z-val :lambda-list '(m))
(cl:defmethod imu_quat_z-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_quat_z-val is deprecated.  Use motor-msg:imu_quat_z instead.")
  (imu_quat_z m))

(cl:ensure-generic-function 'imu_quat_w-val :lambda-list '(m))
(cl:defmethod imu_quat_w-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_quat_w-val is deprecated.  Use motor-msg:imu_quat_w instead.")
  (imu_quat_w m))

(cl:ensure-generic-function 'imu_accel_x-val :lambda-list '(m))
(cl:defmethod imu_accel_x-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_accel_x-val is deprecated.  Use motor-msg:imu_accel_x instead.")
  (imu_accel_x m))

(cl:ensure-generic-function 'imu_accel_y-val :lambda-list '(m))
(cl:defmethod imu_accel_y-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_accel_y-val is deprecated.  Use motor-msg:imu_accel_y instead.")
  (imu_accel_y m))

(cl:ensure-generic-function 'imu_accel_z-val :lambda-list '(m))
(cl:defmethod imu_accel_z-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_accel_z-val is deprecated.  Use motor-msg:imu_accel_z instead.")
  (imu_accel_z m))

(cl:ensure-generic-function 'imu_rate_x-val :lambda-list '(m))
(cl:defmethod imu_rate_x-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_rate_x-val is deprecated.  Use motor-msg:imu_rate_x instead.")
  (imu_rate_x m))

(cl:ensure-generic-function 'imu_rate_y-val :lambda-list '(m))
(cl:defmethod imu_rate_y-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_rate_y-val is deprecated.  Use motor-msg:imu_rate_y instead.")
  (imu_rate_y m))

(cl:ensure-generic-function 'imu_rate_z-val :lambda-list '(m))
(cl:defmethod imu_rate_z-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:imu_rate_z-val is deprecated.  Use motor-msg:imu_rate_z instead.")
  (imu_rate_z m))

(cl:ensure-generic-function 'velocity_cmd_rear-val :lambda-list '(m))
(cl:defmethod velocity_cmd_rear-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:velocity_cmd_rear-val is deprecated.  Use motor-msg:velocity_cmd_rear instead.")
  (velocity_cmd_rear m))

(cl:ensure-generic-function 'velocity_cmd_front-val :lambda-list '(m))
(cl:defmethod velocity_cmd_front-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:velocity_cmd_front-val is deprecated.  Use motor-msg:velocity_cmd_front instead.")
  (velocity_cmd_front m))

(cl:ensure-generic-function 'skate_fault-val :lambda-list '(m))
(cl:defmethod skate_fault-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:skate_fault-val is deprecated.  Use motor-msg:skate_fault instead.")
  (skate_fault m))

(cl:ensure-generic-function 'position_filt_rear-val :lambda-list '(m))
(cl:defmethod position_filt_rear-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:position_filt_rear-val is deprecated.  Use motor-msg:position_filt_rear instead.")
  (position_filt_rear m))

(cl:ensure-generic-function 'position_filt_front-val :lambda-list '(m))
(cl:defmethod position_filt_front-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:position_filt_front-val is deprecated.  Use motor-msg:position_filt_front instead.")
  (position_filt_front m))

(cl:ensure-generic-function 'velocity_filt_rear-val :lambda-list '(m))
(cl:defmethod velocity_filt_rear-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:velocity_filt_rear-val is deprecated.  Use motor-msg:velocity_filt_rear instead.")
  (velocity_filt_rear m))

(cl:ensure-generic-function 'velocity_filt_front-val :lambda-list '(m))
(cl:defmethod velocity_filt_front-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:velocity_filt_front-val is deprecated.  Use motor-msg:velocity_filt_front instead.")
  (velocity_filt_front m))

(cl:ensure-generic-function 'dead_man_enable-val :lambda-list '(m))
(cl:defmethod dead_man_enable-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:dead_man_enable-val is deprecated.  Use motor-msg:dead_man_enable instead.")
  (dead_man_enable m))

(cl:ensure-generic-function 'controller_target-val :lambda-list '(m))
(cl:defmethod controller_target-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:controller_target-val is deprecated.  Use motor-msg:controller_target instead.")
  (controller_target m))

(cl:ensure-generic-function 'skate_mode-val :lambda-list '(m))
(cl:defmethod skate_mode-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor-msg:skate_mode-val is deprecated.  Use motor-msg:skate_mode instead.")
  (skate_mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Num>) ostream)
  "Serializes a message object of type '<Num>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'force_front_outer)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'force_front_inner)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'force_rear)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_quat_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_quat_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_quat_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_quat_w))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_accel_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_accel_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_accel_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_rate_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_rate_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'imu_rate_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity_cmd_rear))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity_cmd_front))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'skate_fault)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'position_filt_rear))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'position_filt_front))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity_filt_rear))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity_filt_front))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'dead_man_enable) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'controller_target))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'skate_mode)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Num>) istream)
  "Deserializes a message object of type '<Num>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'force_front_outer) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'force_front_inner) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'force_rear) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_quat_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_quat_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_quat_z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_quat_w) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_accel_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_accel_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_accel_z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_rate_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_rate_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'imu_rate_z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity_cmd_rear) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity_cmd_front) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'skate_fault)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position_filt_rear) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position_filt_front) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity_filt_rear) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity_filt_front) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'dead_man_enable) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'controller_target) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'skate_mode)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Num>)))
  "Returns string type for a message object of type '<Num>"
  "motor/Num")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Num)))
  "Returns string type for a message object of type 'Num"
  "motor/Num")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Num>)))
  "Returns md5sum for a message object of type '<Num>"
  "4fcef49017325db1881c7de732fff139")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Num)))
  "Returns md5sum for a message object of type 'Num"
  "4fcef49017325db1881c7de732fff139")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Num>)))
  "Returns full string definition for message of type '<Num>"
  (cl:format cl:nil "Header header~%int16 force_front_outer~%int16 force_front_inner~%int16 force_rear~%float32 imu_quat_x~%float32 imu_quat_y~%float32 imu_quat_z~%float32 imu_quat_w~%float32 imu_accel_x~%float32 imu_accel_y~%float32 imu_accel_z~%float32 imu_rate_x~%float32 imu_rate_y ~%float32 imu_rate_z~%float32 velocity_cmd_rear~%float32 velocity_cmd_front~%uint8 skate_fault~%float32 position_filt_rear~%float32 position_filt_front~%float32 velocity_filt_rear~%float32 velocity_filt_front~%bool dead_man_enable~%float32 controller_target~%byte skate_mode~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Num)))
  "Returns full string definition for message of type 'Num"
  (cl:format cl:nil "Header header~%int16 force_front_outer~%int16 force_front_inner~%int16 force_rear~%float32 imu_quat_x~%float32 imu_quat_y~%float32 imu_quat_z~%float32 imu_quat_w~%float32 imu_accel_x~%float32 imu_accel_y~%float32 imu_accel_z~%float32 imu_rate_x~%float32 imu_rate_y ~%float32 imu_rate_z~%float32 velocity_cmd_rear~%float32 velocity_cmd_front~%uint8 skate_fault~%float32 position_filt_rear~%float32 position_filt_front~%float32 velocity_filt_rear~%float32 velocity_filt_front~%bool dead_man_enable~%float32 controller_target~%byte skate_mode~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Num>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     2
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     1
     4
     4
     4
     4
     1
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Num>))
  "Converts a ROS message object to a list"
  (cl:list 'Num
    (cl:cons ':header (header msg))
    (cl:cons ':force_front_outer (force_front_outer msg))
    (cl:cons ':force_front_inner (force_front_inner msg))
    (cl:cons ':force_rear (force_rear msg))
    (cl:cons ':imu_quat_x (imu_quat_x msg))
    (cl:cons ':imu_quat_y (imu_quat_y msg))
    (cl:cons ':imu_quat_z (imu_quat_z msg))
    (cl:cons ':imu_quat_w (imu_quat_w msg))
    (cl:cons ':imu_accel_x (imu_accel_x msg))
    (cl:cons ':imu_accel_y (imu_accel_y msg))
    (cl:cons ':imu_accel_z (imu_accel_z msg))
    (cl:cons ':imu_rate_x (imu_rate_x msg))
    (cl:cons ':imu_rate_y (imu_rate_y msg))
    (cl:cons ':imu_rate_z (imu_rate_z msg))
    (cl:cons ':velocity_cmd_rear (velocity_cmd_rear msg))
    (cl:cons ':velocity_cmd_front (velocity_cmd_front msg))
    (cl:cons ':skate_fault (skate_fault msg))
    (cl:cons ':position_filt_rear (position_filt_rear msg))
    (cl:cons ':position_filt_front (position_filt_front msg))
    (cl:cons ':velocity_filt_rear (velocity_filt_rear msg))
    (cl:cons ':velocity_filt_front (velocity_filt_front msg))
    (cl:cons ':dead_man_enable (dead_man_enable msg))
    (cl:cons ':controller_target (controller_target msg))
    (cl:cons ':skate_mode (skate_mode msg))
))
