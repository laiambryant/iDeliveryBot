;; Auto-generated. Do not edit!


(when (boundp 'delivery::Map)
  (if (not (find-package "DELIVERY"))
    (make-package "DELIVERY"))
  (shadow 'Map (find-package "DELIVERY")))
(unless (find-package "DELIVERY::MAP")
  (make-package "DELIVERY::MAP"))
(unless (find-package "DELIVERY::MAPREQUEST")
  (make-package "DELIVERY::MAPREQUEST"))
(unless (find-package "DELIVERY::MAPRESPONSE")
  (make-package "DELIVERY::MAPRESPONSE"))

(in-package "ROS")





(defclass delivery::MapRequest
  :super ros::object
  :slots ())

(defmethod delivery::MapRequest
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

(defclass delivery::MapResponse
  :super ros::object
  :slots ())

(defmethod delivery::MapResponse
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

(defclass delivery::Map
  :super ros::object
  :slots ())

(setf (get delivery::Map :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get delivery::Map :datatype-) "delivery/Map")
(setf (get delivery::Map :request) delivery::MapRequest)
(setf (get delivery::Map :response) delivery::MapResponse)

(defmethod delivery::MapRequest
  (:response () (instance delivery::MapResponse :init)))

(setf (get delivery::MapRequest :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get delivery::MapRequest :datatype-) "delivery/MapRequest")
(setf (get delivery::MapRequest :definition-)
      "
---
")

(setf (get delivery::MapResponse :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get delivery::MapResponse :datatype-) "delivery/MapResponse")
(setf (get delivery::MapResponse :definition-)
      "
---
")



(provide :delivery/Map "d41d8cd98f00b204e9800998ecf8427e")


