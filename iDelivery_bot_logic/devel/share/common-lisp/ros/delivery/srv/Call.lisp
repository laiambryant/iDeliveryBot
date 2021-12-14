; Auto-generated. Do not edit!


(cl:in-package delivery-srv)


;//! \htmlinclude Call-request.msg.html

(cl:defclass <Call-request> (roslisp-msg-protocol:ros-message)
  ((ok
    :reader ok
    :initarg :ok
    :type cl:boolean
    :initform cl:nil)
   (pos_x
    :reader pos_x
    :initarg :pos_x
    :type cl:float
    :initform 0.0)
   (pos_y
    :reader pos_y
    :initarg :pos_y
    :type cl:float
    :initform 0.0)
   (pos_z
    :reader pos_z
    :initarg :pos_z
    :type cl:float
    :initform 0.0))
)

(cl:defclass Call-request (<Call-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Call-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Call-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name delivery-srv:<Call-request> is deprecated: use delivery-srv:Call-request instead.")))

(cl:ensure-generic-function 'ok-val :lambda-list '(m))
(cl:defmethod ok-val ((m <Call-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader delivery-srv:ok-val is deprecated.  Use delivery-srv:ok instead.")
  (ok m))

(cl:ensure-generic-function 'pos_x-val :lambda-list '(m))
(cl:defmethod pos_x-val ((m <Call-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader delivery-srv:pos_x-val is deprecated.  Use delivery-srv:pos_x instead.")
  (pos_x m))

(cl:ensure-generic-function 'pos_y-val :lambda-list '(m))
(cl:defmethod pos_y-val ((m <Call-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader delivery-srv:pos_y-val is deprecated.  Use delivery-srv:pos_y instead.")
  (pos_y m))

(cl:ensure-generic-function 'pos_z-val :lambda-list '(m))
(cl:defmethod pos_z-val ((m <Call-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader delivery-srv:pos_z-val is deprecated.  Use delivery-srv:pos_z instead.")
  (pos_z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Call-request>) ostream)
  "Serializes a message object of type '<Call-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'ok) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pos_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pos_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pos_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Call-request>) istream)
  "Deserializes a message object of type '<Call-request>"
    (cl:setf (cl:slot-value msg 'ok) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pos_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pos_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pos_z) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Call-request>)))
  "Returns string type for a service object of type '<Call-request>"
  "delivery/CallRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Call-request)))
  "Returns string type for a service object of type 'Call-request"
  "delivery/CallRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Call-request>)))
  "Returns md5sum for a message object of type '<Call-request>"
  "bd3e0142db41a8872e933337357dd05d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Call-request)))
  "Returns md5sum for a message object of type 'Call-request"
  "bd3e0142db41a8872e933337357dd05d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Call-request>)))
  "Returns full string definition for message of type '<Call-request>"
  (cl:format cl:nil "bool ok~%float32 pos_x~%float32 pos_y~%float32 pos_z~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Call-request)))
  "Returns full string definition for message of type 'Call-request"
  (cl:format cl:nil "bool ok~%float32 pos_x~%float32 pos_y~%float32 pos_z~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Call-request>))
  (cl:+ 0
     1
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Call-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Call-request
    (cl:cons ':ok (ok msg))
    (cl:cons ':pos_x (pos_x msg))
    (cl:cons ':pos_y (pos_y msg))
    (cl:cons ':pos_z (pos_z msg))
))
;//! \htmlinclude Call-response.msg.html

(cl:defclass <Call-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Call-response (<Call-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Call-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Call-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name delivery-srv:<Call-response> is deprecated: use delivery-srv:Call-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Call-response>) ostream)
  "Serializes a message object of type '<Call-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Call-response>) istream)
  "Deserializes a message object of type '<Call-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Call-response>)))
  "Returns string type for a service object of type '<Call-response>"
  "delivery/CallResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Call-response)))
  "Returns string type for a service object of type 'Call-response"
  "delivery/CallResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Call-response>)))
  "Returns md5sum for a message object of type '<Call-response>"
  "bd3e0142db41a8872e933337357dd05d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Call-response)))
  "Returns md5sum for a message object of type 'Call-response"
  "bd3e0142db41a8872e933337357dd05d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Call-response>)))
  "Returns full string definition for message of type '<Call-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Call-response)))
  "Returns full string definition for message of type 'Call-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Call-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Call-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Call-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Call)))
  'Call-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Call)))
  'Call-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Call)))
  "Returns string type for a service object of type '<Call>"
  "delivery/Call")