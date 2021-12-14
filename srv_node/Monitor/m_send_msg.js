var msg_counter = 0

module.exports = function m_send_msg(msg, type, socket, callback){
    ret = "[" + msg_counter + "," + type + "]:" + msg
    try {      
        socket.write(ret)
    } catch (error) {
        console.log(error)
    }
    msg_counter+=1
}
