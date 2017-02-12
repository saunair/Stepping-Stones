
(cl:in-package :asdf)

(defsystem "motor-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "calib" :depends-on ("_package_calib"))
    (:file "_package_calib" :depends-on ("_package"))
    (:file "skate_feedback" :depends-on ("_package_skate_feedback"))
    (:file "_package_skate_feedback" :depends-on ("_package"))
    (:file "skate_command" :depends-on ("_package_skate_command"))
    (:file "_package_skate_command" :depends-on ("_package"))
  ))