; Auto-generated. Do not edit!


(cl:in-package delivery-srv)


;//! \htmlinclude Map-request.msg.html

(cl:defclass <Map-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Map-request (<Map-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Map-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Map-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name delivery-srv:<Map-request> is deprecated: use delivery-srv:Map-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Map-request>) ostream)
  "Serializes a message object of type '<Map-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Map-request>) istream)
  "Deserializes a message object of type '<Map-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Map-request>)))
  "Returns string type for a service object of type '<Map-request>"
  "delivery/MapRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Map-request)))
  "Returns string type for a service object of type 'Map-request"
  "delivery/MapRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Map-request>)))
  "Returns md5sum for a message object of type '<Map-request>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Map-request)))
  "Returns md5sum for a message object of type 'Map-request"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Map-request>)))
  "Returns full string definition for message of type '<Map-request>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Map-request)))
  "Returns full string definition for message of type 'Map-request"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Map-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Map-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Map-request
))
;//! \htmlinclude Map-response.msg.html

(cl:defclass <Map-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Map-response (<Map-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Map-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Map-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name delivery-srv:<Map-response> is deprecated: use delivery-srv:Map-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Map-response>) ostream)
  "Serializes a message object of type '<Map-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Map-response>) istream)
  "Deserializes a message object of type '<Map-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Map-response>)))
  "Returns string type for a service object of type '<Map-response>"
  "delivery/MapResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Map-response)))
  "Returns string type for a service object of type 'Map-response"
  "delivery/MapResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Map-response>)))
  "Returns md5sum for a message object of type '<Map-response>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Map-response)))
  "Returns md5sum for a message object of type 'Map-response"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Map-response>)))
  "Returns full string definition for message of type '<Map-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Map-response)))
  "Returns full string definition for message of type 'Map-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Map-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Map-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Map-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Map)))
  'Map-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Map)))
  'Map-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Map)))
  "Returns string type for a service object of type '<Map>"
  "delivery/Map")