
(cl:in-package :asdf)

(defsystem "opticalflow-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "optical" :depends-on ("_package_optical"))
    (:file "_package_optical" :depends-on ("_package"))
  ))