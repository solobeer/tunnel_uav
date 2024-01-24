; Auto-generated. Do not edit!


(cl:in-package opticalflow-msg)


;//! \htmlinclude optical.msg.html

(cl:defclass <optical> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (frameClass
    :reader frameClass
    :initarg :frameClass
    :type cl:fixnum
    :initform 0)
   (mode
    :reader mode
    :initarg :mode
    :type cl:fixnum
    :initform 0)
   (vel_rate
    :reader vel_rate
    :initarg :vel_rate
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (vel_rate_fix
    :reader vel_rate_fix
    :initarg :vel_rate_fix
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (vel_rate_integ
    :reader vel_rate_integ
    :initarg :vel_rate_integ
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (quality
    :reader quality
    :initarg :quality
    :type cl:float
    :initform 0.0)
   (dir
    :reader dir
    :initarg :dir
    :type cl:fixnum
    :initform 0)
   (angle
    :reader angle
    :initarg :angle
    :type cl:fixnum
    :initform 0)
   (dis
    :reader dis
    :initarg :dis
    :type cl:float
    :initform 0.0)
   (acc_rate
    :reader acc_rate
    :initarg :acc_rate
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (gry_rate
    :reader gry_rate
    :initarg :gry_rate
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (quat
    :reader quat
    :initarg :quat
    :type geometry_msgs-msg:Quaternion
    :initform (cl:make-instance 'geometry_msgs-msg:Quaternion)))
)

(cl:defclass optical (<optical>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <optical>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'optical)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name opticalflow-msg:<optical> is deprecated: use opticalflow-msg:optical instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:header-val is deprecated.  Use opticalflow-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'frameClass-val :lambda-list '(m))
(cl:defmethod frameClass-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:frameClass-val is deprecated.  Use opticalflow-msg:frameClass instead.")
  (frameClass m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:mode-val is deprecated.  Use opticalflow-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'vel_rate-val :lambda-list '(m))
(cl:defmethod vel_rate-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:vel_rate-val is deprecated.  Use opticalflow-msg:vel_rate instead.")
  (vel_rate m))

(cl:ensure-generic-function 'vel_rate_fix-val :lambda-list '(m))
(cl:defmethod vel_rate_fix-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:vel_rate_fix-val is deprecated.  Use opticalflow-msg:vel_rate_fix instead.")
  (vel_rate_fix m))

(cl:ensure-generic-function 'vel_rate_integ-val :lambda-list '(m))
(cl:defmethod vel_rate_integ-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:vel_rate_integ-val is deprecated.  Use opticalflow-msg:vel_rate_integ instead.")
  (vel_rate_integ m))

(cl:ensure-generic-function 'quality-val :lambda-list '(m))
(cl:defmethod quality-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:quality-val is deprecated.  Use opticalflow-msg:quality instead.")
  (quality m))

(cl:ensure-generic-function 'dir-val :lambda-list '(m))
(cl:defmethod dir-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:dir-val is deprecated.  Use opticalflow-msg:dir instead.")
  (dir m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:angle-val is deprecated.  Use opticalflow-msg:angle instead.")
  (angle m))

(cl:ensure-generic-function 'dis-val :lambda-list '(m))
(cl:defmethod dis-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:dis-val is deprecated.  Use opticalflow-msg:dis instead.")
  (dis m))

(cl:ensure-generic-function 'acc_rate-val :lambda-list '(m))
(cl:defmethod acc_rate-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:acc_rate-val is deprecated.  Use opticalflow-msg:acc_rate instead.")
  (acc_rate m))

(cl:ensure-generic-function 'gry_rate-val :lambda-list '(m))
(cl:defmethod gry_rate-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:gry_rate-val is deprecated.  Use opticalflow-msg:gry_rate instead.")
  (gry_rate m))

(cl:ensure-generic-function 'quat-val :lambda-list '(m))
(cl:defmethod quat-val ((m <optical>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opticalflow-msg:quat-val is deprecated.  Use opticalflow-msg:quat instead.")
  (quat m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <optical>) ostream)
  "Serializes a message object of type '<optical>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'frameClass)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vel_rate) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vel_rate_fix) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vel_rate_integ) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'quality))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dir)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'angle)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'angle)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'dis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'acc_rate) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'gry_rate) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'quat) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <optical>) istream)
  "Deserializes a message object of type '<optical>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'frameClass) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vel_rate) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vel_rate_fix) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vel_rate_integ) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'quality) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dir)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'angle)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'angle)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dis) (roslisp-utils:decode-single-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'acc_rate) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'gry_rate) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'quat) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<optical>)))
  "Returns string type for a message object of type '<optical>"
  "opticalflow/optical")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'optical)))
  "Returns string type for a message object of type 'optical"
  "opticalflow/optical")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<optical>)))
  "Returns md5sum for a message object of type '<optical>"
  "8d8fc678561657c551426004e594a041")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'optical)))
  "Returns md5sum for a message object of type 'optical"
  "8d8fc678561657c551426004e594a041")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<optical>)))
  "Returns full string definition for message of type '<optical>"
  (cl:format cl:nil "std_msgs/Header header~%int16 frameClass~%~%int16 mode~%geometry_msgs/Vector3 vel_rate~%geometry_msgs/Vector3 vel_rate_fix~%geometry_msgs/Vector3 vel_rate_integ~%float32 quality~%~%uint8 dir~%uint16 angle~%float32 dis~%~%geometry_msgs/Vector3 acc_rate~%geometry_msgs/Vector3 gry_rate~%~%geometry_msgs/Quaternion quat~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'optical)))
  "Returns full string definition for message of type 'optical"
  (cl:format cl:nil "std_msgs/Header header~%int16 frameClass~%~%int16 mode~%geometry_msgs/Vector3 vel_rate~%geometry_msgs/Vector3 vel_rate_fix~%geometry_msgs/Vector3 vel_rate_integ~%float32 quality~%~%uint8 dir~%uint16 angle~%float32 dis~%~%geometry_msgs/Vector3 acc_rate~%geometry_msgs/Vector3 gry_rate~%~%geometry_msgs/Quaternion quat~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <optical>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vel_rate))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vel_rate_fix))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vel_rate_integ))
     4
     1
     2
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'acc_rate))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'gry_rate))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'quat))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <optical>))
  "Converts a ROS message object to a list"
  (cl:list 'optical
    (cl:cons ':header (header msg))
    (cl:cons ':frameClass (frameClass msg))
    (cl:cons ':mode (mode msg))
    (cl:cons ':vel_rate (vel_rate msg))
    (cl:cons ':vel_rate_fix (vel_rate_fix msg))
    (cl:cons ':vel_rate_integ (vel_rate_integ msg))
    (cl:cons ':quality (quality msg))
    (cl:cons ':dir (dir msg))
    (cl:cons ':angle (angle msg))
    (cl:cons ':dis (dis msg))
    (cl:cons ':acc_rate (acc_rate msg))
    (cl:cons ':gry_rate (gry_rate msg))
    (cl:cons ':quat (quat msg))
))
