module.exports = function arrived_handler(socket, type, data, monitor_socket){
    console.log("Arrived Request incoming:")
    m_send_msg(data, type, monitor_socket)
}