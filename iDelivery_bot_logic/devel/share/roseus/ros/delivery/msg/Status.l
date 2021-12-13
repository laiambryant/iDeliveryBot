;; Auto-generated. Do not edit!


(when (boundp 'delivery::Status)
  (if (not (find-package "DELIVERY"))
    (make-package "DELIVERY"))
  (shadow 'Status (find-package "DELIVERY")))
(unless (find-package "DELIVERY::STATUS")
  (make-package "DELIVERY::STATUS"))

(in-package "ROS")
;;//! \htmlinclude Status.msg.html


(defclass delivery::Status
  :super ros::object
  :slots ())

(defmethod delivery::Status
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

(setf (get delivery::Status :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get delivery::Status :datatype-) "delivery/Status")
(setf (get delivery::Status :definition-)
      "
")



(provide :delivery/Status "d41d8cd98f00b204e9800998ecf8427e")


