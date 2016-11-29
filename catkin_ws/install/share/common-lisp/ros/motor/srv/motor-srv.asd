
(cl:in-package :asdf)

(defsystem "motor-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "yaml_values" :depends-on ("_package_yaml_values"))
    (:file "_package_yaml_values" :depends-on ("_package"))
    (:file "zero_point" :depends-on ("_package_zero_point"))
    (:file "_package_zero_point" :depends-on ("_package"))
  ))