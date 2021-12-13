;; Auto-generated. Do not edit!


(when (boundp 'delivery::Cmd)
  (if (not (find-package "DELIVERY"))
    (make-package "DELIVERY"))
  (shadow 'Cmd (find-package "DELIVERY")))
(unless (find-package "DELIVERY::CMD")
  (make-package "DELIVERY::CMD"))

(in-package "ROS")
;;//! \htmlinclude Cmd.msg.html


(defclass delivery::Cmd
  :super ros::object
  :slots (_type _num _body ))

(defmethod delivery::Cmd
  (:init
   (&key
    ((:type __type) "")
    ((:num __num) 0)
    ((:body __body) "")
    )
   (send-super :init)
   (setq _type (string __type))
   (setq _num (round __num))
   (setq _body (string __body))
   self)
  (:type
   (&optional __type)
   (if __type (setq _type __type)) _type)
  (:num
   (&optional __num)
   (if __num (setq _num __num)) _num)
  (:body
   (&optional __body)
   (if __body (setq _body __body)) _body)
  (:serialization-length
   ()
   (+
    ;; string _type
    4 (length _type)
    ;; int32 _num
    4
    ;; string _body
    4 (length _body)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _type
       (write-long (length _type) s) (princ _type s)
     ;; int32 _num
       (write-long _num s)
     ;; string _body
       (write-long (length _body) s) (princ _body s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _num
     (setq _num (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _body
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _body (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get delivery::Cmd :md5sum-) "0ce1e7c244927ca76a4c6cf091b0e309")
(setf (get delivery::Cmd :datatype-) "delivery/Cmd")
(setf (get delivery::Cmd :definition-)
      "string type
int32 num
string body

")



(provide :delivery/Cmd "0ce1e7c244927ca76a4c6cf091b0e309")


