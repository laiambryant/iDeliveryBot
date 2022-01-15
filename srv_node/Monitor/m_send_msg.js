var msg_counter = 0

module.exports = function m_send_msg(msg, type, socket, callback){
    ret = "[" + msg_counter + "," + type + "]:" + msg
    try {      
        socket.write(ret)
    } catch (error) {
        console.log('\x1b[31m%s\x1b[0m',error)
    }
    msg_counter+=1
}
