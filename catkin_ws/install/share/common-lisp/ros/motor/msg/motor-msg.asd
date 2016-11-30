
(cl:in-package :asdf)

(defsystem "motor-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Num" :depends-on ("_package_Num"))
    (:file "_package_Num" :depends-on ("_package"))
    (:file "states" :depends-on ("_package_states"))
    (:file "_package_states" :depends-on ("_package"))
    (:file "calib" :depends-on ("_package_calib"))
    (:file "_package_calib" :depends-on ("_package"))
  ))