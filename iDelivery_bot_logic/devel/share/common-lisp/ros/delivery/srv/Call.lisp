; Auto-generated. Do not edit!


(cl:in-package delivery-srv)


;//! \htmlinclude Call-request.msg.html

(cl:defclass <Call-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Call-request (<Call-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Call-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Call-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name delivery-srv:<Call-request> is deprecated: use delivery-srv:Call-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Call-request>) ostream)
  "Serializes a message object of type '<Call-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Call-request>) istream)
  "Deserializes a message object of type '<Call-request>"
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
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Call-request)))
  "Returns md5sum for a message object of type 'Call-request"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Call-request>)))
  "Returns full string definition for message of type '<Call-request>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Call-request)))
  "Returns full string definition for message of type 'Call-request"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Call-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Call-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Call-request
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
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Call-response)))
  "Returns md5sum for a message object of type 'Call-response"
  "d41d8cd98f00b204e9800998ecf8427e")
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