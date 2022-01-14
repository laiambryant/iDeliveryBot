const m_send_msg = require("../Monitor/m_send_msg")
module.exports = function call_handler(socket, type, data, monitor_socket){
    console.log("Call Request incoming:")
    m_send_msg(data, type, monitor_socket)
}