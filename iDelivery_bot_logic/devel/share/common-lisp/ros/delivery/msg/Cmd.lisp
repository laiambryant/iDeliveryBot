; Auto-generated. Do not edit!


(cl:in-package delivery-msg)


;//! \htmlinclude Cmd.msg.html

(cl:defclass <Cmd> (roslisp-msg-protocol:ros-message)
  ((type
    :reader type
    :initarg :type
    :type cl:string
    :initform "")
   (num
    :reader num
    :initarg :num
    :type cl:integer
    :initform 0)
   (body
    :reader body
    :initarg :body
    :type cl:string
    :initform ""))
)

(cl:defclass Cmd (<Cmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Cmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Cmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name delivery-msg:<Cmd> is deprecated: use delivery-msg:Cmd instead.")))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <Cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader delivery-msg:type-val is deprecated.  Use delivery-msg:type instead.")
  (type m))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <Cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader delivery-msg:num-val is deprecated.  Use delivery-msg:num instead.")
  (num m))

(cl:ensure-generic-function 'body-val :lambda-list '(m))
(cl:defmethod body-val ((m <Cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader delivery-msg:body-val is deprecated.  Use delivery-msg:body instead.")
  (body m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Cmd>) ostream)
  "Serializes a message object of type '<Cmd>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'type))
  (cl:let* ((signed (cl:slot-value msg 'num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'body))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'body))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Cmd>) istream)
  "Deserializes a message object of type '<Cmd>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'body) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'body) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Cmd>)))
  "Returns string type for a message object of type '<Cmd>"
  "delivery/Cmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Cmd)))
  "Returns string type for a message object of type 'Cmd"
  "delivery/Cmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Cmd>)))
  "Returns md5sum for a message object of type '<Cmd>"
  "0ce1e7c244927ca76a4c6cf091b0e309")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Cmd)))
  "Returns md5sum for a message object of type 'Cmd"
  "0ce1e7c244927ca76a4c6cf091b0e309")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Cmd>)))
  "Returns full string definition for message of type '<Cmd>"
  (cl:format cl:nil "string type~%int32 num~%string body~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Cmd)))
  "Returns full string definition for message of type 'Cmd"
  (cl:format cl:nil "string type~%int32 num~%string body~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Cmd>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'type))
     4
     4 (cl:length (cl:slot-value msg 'body))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Cmd>))
  "Converts a ROS message object to a list"
  (cl:list 'Cmd
    (cl:cons ':type (type msg))
    (cl:cons ':num (num msg))
    (cl:cons ':body (body msg))
))
