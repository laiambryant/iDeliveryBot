
(cl:in-package :asdf)

(defsystem "delivery-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Call" :depends-on ("_package_Call"))
    (:file "_package_Call" :depends-on ("_package"))
    (:file "Map" :depends-on ("_package_Map"))
    (:file "_package_Map" :depends-on ("_package"))
  ))