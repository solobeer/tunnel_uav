;; Auto-generated. Do not edit!


(when (boundp 'opticalflow::optical)
  (if (not (find-package "OPTICALFLOW"))
    (make-package "OPTICALFLOW"))
  (shadow 'optical (find-package "OPTICALFLOW")))
(unless (find-package "OPTICALFLOW::OPTICAL")
  (make-package "OPTICALFLOW::OPTICAL"))

(in-package "ROS")
;;//! \htmlinclude optical.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass opticalflow::optical
  :super ros::object
  :slots (_header _frameClass _mode _vel_rate _vel_rate_fix _vel_rate_integ _quality _dir _angle _dis _acc_rate _gry_rate _quat ))

(defmethod opticalflow::optical
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:frameClass __frameClass) 0)
    ((:mode __mode) 0)
    ((:vel_rate __vel_rate) (instance geometry_msgs::Vector3 :init))
    ((:vel_rate_fix __vel_rate_fix) (instance geometry_msgs::Vector3 :init))
    ((:vel_rate_integ __vel_rate_integ) (instance geometry_msgs::Vector3 :init))
    ((:quality __quality) 0.0)
    ((:dir __dir) 0)
    ((:angle __angle) 0)
    ((:dis __dis) 0.0)
    ((:acc_rate __acc_rate) (instance geometry_msgs::Vector3 :init))
    ((:gry_rate __gry_rate) (instance geometry_msgs::Vector3 :init))
    ((:quat __quat) (instance geometry_msgs::Quaternion :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _frameClass (round __frameClass))
   (setq _mode (round __mode))
   (setq _vel_rate __vel_rate)
   (setq _vel_rate_fix __vel_rate_fix)
   (setq _vel_rate_integ __vel_rate_integ)
   (setq _quality (float __quality))
   (setq _dir (round __dir))
   (setq _angle (round __angle))
   (setq _dis (float __dis))
   (setq _acc_rate __acc_rate)
   (setq _gry_rate __gry_rate)
   (setq _quat __quat)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:frameClass
   (&optional __frameClass)
   (if __frameClass (setq _frameClass __frameClass)) _frameClass)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:vel_rate
   (&rest __vel_rate)
   (if (keywordp (car __vel_rate))
       (send* _vel_rate __vel_rate)
     (progn
       (if __vel_rate (setq _vel_rate (car __vel_rate)))
       _vel_rate)))
  (:vel_rate_fix
   (&rest __vel_rate_fix)
   (if (keywordp (car __vel_rate_fix))
       (send* _vel_rate_fix __vel_rate_fix)
     (progn
       (if __vel_rate_fix (setq _vel_rate_fix (car __vel_rate_fix)))
       _vel_rate_fix)))
  (:vel_rate_integ
   (&rest __vel_rate_integ)
   (if (keywordp (car __vel_rate_integ))
       (send* _vel_rate_integ __vel_rate_integ)
     (progn
       (if __vel_rate_integ (setq _vel_rate_integ (car __vel_rate_integ)))
       _vel_rate_integ)))
  (:quality
   (&optional __quality)
   (if __quality (setq _quality __quality)) _quality)
  (:dir
   (&optional __dir)
   (if __dir (setq _dir __dir)) _dir)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:dis
   (&optional __dis)
   (if __dis (setq _dis __dis)) _dis)
  (:acc_rate
   (&rest __acc_rate)
   (if (keywordp (car __acc_rate))
       (send* _acc_rate __acc_rate)
     (progn
       (if __acc_rate (setq _acc_rate (car __acc_rate)))
       _acc_rate)))
  (:gry_rate
   (&rest __gry_rate)
   (if (keywordp (car __gry_rate))
       (send* _gry_rate __gry_rate)
     (progn
       (if __gry_rate (setq _gry_rate (car __gry_rate)))
       _gry_rate)))
  (:quat
   (&rest __quat)
   (if (keywordp (car __quat))
       (send* _quat __quat)
     (progn
       (if __quat (setq _quat (car __quat)))
       _quat)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int16 _frameClass
    2
    ;; int16 _mode
    2
    ;; geometry_msgs/Vector3 _vel_rate
    (send _vel_rate :serialization-length)
    ;; geometry_msgs/Vector3 _vel_rate_fix
    (send _vel_rate_fix :serialization-length)
    ;; geometry_msgs/Vector3 _vel_rate_integ
    (send _vel_rate_integ :serialization-length)
    ;; float32 _quality
    4
    ;; uint8 _dir
    1
    ;; uint16 _angle
    2
    ;; float32 _dis
    4
    ;; geometry_msgs/Vector3 _acc_rate
    (send _acc_rate :serialization-length)
    ;; geometry_msgs/Vector3 _gry_rate
    (send _gry_rate :serialization-length)
    ;; geometry_msgs/Quaternion _quat
    (send _quat :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int16 _frameClass
       (write-word _frameClass s)
     ;; int16 _mode
       (write-word _mode s)
     ;; geometry_msgs/Vector3 _vel_rate
       (send _vel_rate :serialize s)
     ;; geometry_msgs/Vector3 _vel_rate_fix
       (send _vel_rate_fix :serialize s)
     ;; geometry_msgs/Vector3 _vel_rate_integ
       (send _vel_rate_integ :serialize s)
     ;; float32 _quality
       (sys::poke _quality (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _dir
       (write-byte _dir s)
     ;; uint16 _angle
       (write-word _angle s)
     ;; float32 _dis
       (sys::poke _dis (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; geometry_msgs/Vector3 _acc_rate
       (send _acc_rate :serialize s)
     ;; geometry_msgs/Vector3 _gry_rate
       (send _gry_rate :serialize s)
     ;; geometry_msgs/Quaternion _quat
       (send _quat :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int16 _frameClass
     (setq _frameClass (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _mode
     (setq _mode (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; geometry_msgs/Vector3 _vel_rate
     (send _vel_rate :deserialize buf ptr-) (incf ptr- (send _vel_rate :serialization-length))
   ;; geometry_msgs/Vector3 _vel_rate_fix
     (send _vel_rate_fix :deserialize buf ptr-) (incf ptr- (send _vel_rate_fix :serialization-length))
   ;; geometry_msgs/Vector3 _vel_rate_integ
     (send _vel_rate_integ :deserialize buf ptr-) (incf ptr- (send _vel_rate_integ :serialization-length))
   ;; float32 _quality
     (setq _quality (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _dir
     (setq _dir (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint16 _angle
     (setq _angle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float32 _dis
     (setq _dis (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; geometry_msgs/Vector3 _acc_rate
     (send _acc_rate :deserialize buf ptr-) (incf ptr- (send _acc_rate :serialization-length))
   ;; geometry_msgs/Vector3 _gry_rate
     (send _gry_rate :deserialize buf ptr-) (incf ptr- (send _gry_rate :serialization-length))
   ;; geometry_msgs/Quaternion _quat
     (send _quat :deserialize buf ptr-) (incf ptr- (send _quat :serialization-length))
   ;;
   self)
  )

(setf (get opticalflow::optical :md5sum-) "8d8fc678561657c551426004e594a041")
(setf (get opticalflow::optical :datatype-) "opticalflow/optical")
(setf (get opticalflow::optical :definition-)
      "std_msgs/Header header
int16 frameClass

int16 mode
geometry_msgs/Vector3 vel_rate
geometry_msgs/Vector3 vel_rate_fix
geometry_msgs/Vector3 vel_rate_integ
float32 quality

uint8 dir
uint16 angle
float32 dis

geometry_msgs/Vector3 acc_rate
geometry_msgs/Vector3 gry_rate

geometry_msgs/Quaternion quat



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
string frame_id

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :opticalflow/optical "8d8fc678561657c551426004e594a041")


