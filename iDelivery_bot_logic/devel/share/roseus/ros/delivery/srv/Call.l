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
  :slots (_ok _pos_x _pos_y _pos_z ))

(defmethod delivery::CallRequest
  (:init
   (&key
    ((:ok __ok) nil)
    ((:pos_x __pos_x) 0.0)
    ((:pos_y __pos_y) 0.0)
    ((:pos_z __pos_z) 0.0)
    )
   (send-super :init)
   (setq _ok __ok)
   (setq _pos_x (float __pos_x))
   (setq _pos_y (float __pos_y))
   (setq _pos_z (float __pos_z))
   self)
  (:ok
   (&optional (__ok :null))
   (if (not (eq __ok :null)) (setq _ok __ok)) _ok)
  (:pos_x
   (&optional __pos_x)
   (if __pos_x (setq _pos_x __pos_x)) _pos_x)
  (:pos_y
   (&optional __pos_y)
   (if __pos_y (setq _pos_y __pos_y)) _pos_y)
  (:pos_z
   (&optional __pos_z)
   (if __pos_z (setq _pos_z __pos_z)) _pos_z)
  (:serialization-length
   ()
   (+
    ;; bool _ok
    1
    ;; float32 _pos_x
    4
    ;; float32 _pos_y
    4
    ;; float32 _pos_z
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _ok
       (if _ok (write-byte -1 s) (write-byte 0 s))
     ;; float32 _pos_x
       (sys::poke _pos_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pos_y
       (sys::poke _pos_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pos_z
       (sys::poke _pos_z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _ok
     (setq _ok (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _pos_x
     (setq _pos_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pos_y
     (setq _pos_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pos_z
     (setq _pos_z (sys::peek buf ptr- :float)) (incf ptr- 4)
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

(setf (get delivery::Call :md5sum-) "bd3e0142db41a8872e933337357dd05d")
(setf (get delivery::Call :datatype-) "delivery/Call")
(setf (get delivery::Call :request) delivery::CallRequest)
(setf (get delivery::Call :response) delivery::CallResponse)

(defmethod delivery::CallRequest
  (:response () (instance delivery::CallResponse :init)))

(setf (get delivery::CallRequest :md5sum-) "bd3e0142db41a8872e933337357dd05d")
(setf (get delivery::CallRequest :datatype-) "delivery/CallRequest")
(setf (get delivery::CallRequest :definition-)
      "bool ok
float32 pos_x
float32 pos_y
float32 pos_z

---
")

(setf (get delivery::CallResponse :md5sum-) "bd3e0142db41a8872e933337357dd05d")
(setf (get delivery::CallResponse :datatype-) "delivery/CallResponse")
(setf (get delivery::CallResponse :definition-)
      "bool ok
float32 pos_x
float32 pos_y
float32 pos_z

---
")



(provide :delivery/Call "bd3e0142db41a8872e933337357dd05d")


