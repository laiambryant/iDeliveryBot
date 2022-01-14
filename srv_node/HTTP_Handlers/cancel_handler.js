module.exports = function cancel_handler(socket, type, data, monitor_socket){
    console.log("Cancel Request incoming:")
    m_send_msg(data, type, monitor_socket)
}