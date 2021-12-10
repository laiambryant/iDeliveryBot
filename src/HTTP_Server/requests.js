const m_rcv_msg = require("../Monitor/m_rcv_msg");
const m_send_msg = require("../Monitor/m_send_msg");

function Connection_handler(socket, monitor_socket){
    console.log('[Server]:a user connected');
    socket.on('disconnect', onDisconnection);
    socket.onAny((type, data)=>{
        Request(socket, type, data, monitor_socket)  
        console.log("[Server]:"+ data)  
    })
}

function Request(socket, type, data, monitor_socket){
    console.log("[Server]:")
    switch (type) {
        case "LOGIN":
            console.log("Login Request incoming")
            m_send_msg(data, type, monitor_socket)
            break;
        case "CALL":
            break;
        case "PRIORITY_CALL":
            break;
        case "ARRIVED":
            break;
        case "OBJ_SENT":
            break;
        case "OBJ_RCV":
            break;
        case "CANCEL":
            break;
        case "TIMEOUT":
            break;
        default:
            console.log("Invalid Request");
            socket.emit("ERROR", "ERRSTRING: There was an error")
            break;
    }
}

function onDisconnection(){
    console.log('a user disconnected');
}

module.exports = Connection_handler