;; Auto-generated. Do not edit!


(when (boundp 'delivery::Call)
  (if (not (find-package "DELIVERY"))
    (make-package "DELIVERY"))
  (shadow 'Call (find-package "DELIVERY")))
(unless (find-package "DELIVERY::CALL")
  (make-package "DELIVERY::CALL"))
(unless (find-package "DELIVERY::CALLREQUEST")
  (make-package "DELIVERY::CALLREQUEST"))
(unless (find-package "DELIVERY::CALLRESPONSE")
  (make-package "DELIVERY::CALLRESPONSE"))

(in-package "ROS")





(defclass delivery::CallRequest
  :super ros::object
  :slots ())

(defmethod delivery::CallRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass delivery::CallResponse
  :super ros::object
  :slots ())

(defmethod delivery::CallResponse
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass delivery::Call
  :super ros::object
  :slots ())

(setf (get delivery::Call :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get delivery::Call :datatype-) "delivery/Call")
(setf (get delivery::Call :request) delivery::CallRequest)
(setf (get delivery::Call :response) delivery::CallResponse)

(defmethod delivery::CallRequest
  (:response () (instance delivery::CallResponse :init)))

(setf (get delivery::CallRequest :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get delivery::CallRequest :datatype-) "delivery/CallRequest")
(setf (get delivery::CallRequest :definition-)
      "
---
")

(setf (get delivery::CallResponse :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get delivery::CallResponse :datatype-) "delivery/CallResponse")
(setf (get delivery::CallResponse :definition-)
      "
---
")



(provide :delivery/Call "d41d8cd98f00b204e9800998ecf8427e")


