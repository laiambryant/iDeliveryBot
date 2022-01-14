const m_send_msg = require("../Monitor/m_send_msg")
module.exports = function timeout_handler(socket, type, data, monitor_socket){
    console.log("Timeout ßRequest incoming:")
    m_send_msg(data, type, monitor_socket)
}