const m_send_msg = require("../Monitor/m_send_msg");
module.exports = function send_handler(socket, type, data, monitor_socket){
    console.log('\x1b[36m%s\x1b[0m',"Send Request incoming:");
    m_send_msg(data, type, monitor_socket);
};