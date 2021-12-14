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
  :slots (_free ))

(defmethod delivery::Status
  (:init
   (&key
    ((:free __free) nil)
    )
   (send-super :init)
   (setq _free __free)
   self)
  (:free
   (&optional (__free :null))
   (if (not (eq __free :null)) (setq _free __free)) _free)
  (:serialization-length
   ()
   (+
    ;; bool _free
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _free
       (if _free (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _free
     (setq _free (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get delivery::Status :md5sum-) "662d0577555df77dcaee5a646dd74f27")
(setf (get delivery::Status :datatype-) "delivery/Status")
(setf (get delivery::Status :definition-)
      "bool free 
")



(provide :delivery/Status "662d0577555df77dcaee5a646dd74f27")


