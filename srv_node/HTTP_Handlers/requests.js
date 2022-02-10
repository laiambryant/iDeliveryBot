const login_handler = require("./login_handler")
const arrived_handler = require("./arrived_handler")
const call_handler = require("./call_handler")
const cancel_handler  = require("./cancel_handler")
const obj_rcv_handler  = require("./obj_rcv_handler")
const obj_send_handler  = require("./obj_send_handler")
const timeout_handler  = require("./timeout_handler")

function Connection_handler(socket, monitor_socket){
    console.log('\x1b[36m%s\x1b[0m','[Server]:a user connected');
    socket.on('disconnect', onDisconnection);
    socket.onAny((type, data)=>{
        Request(socket, type, data, monitor_socket)  
        console.log('\x1b[36m%s\x1b[0m',"[Server]:"+ data)  
    })
}

function Request(socket, type, data, monitor_socket){
    console.log('\x1b[36m%s\x1b[0m',"[Server]:")
    switch (type) {
        case "LOGIN":
            login_handler(socket, type, data, monitor_socket)
            break;
        case "CALL":
            call_handler(socket, type, data, monitor_socket)
            break;
        case "SEND":
            obj_sent_handler(socket, type, data, monitor_socket)
            break;
        case "OBJ_RCV":
            obj_rcv_handler(socket, type, data, monitor_socket)
            break;
        case "CANCEL":
            cancel_handler(socket, type, data, monitor_socket)
            break;
        case "TIMEOUT":
            timeout_handler(socket, type, data, monitor_socket)
            break;
        default:
            console.log('\x1b[31m%s\x1b[0m',"Invalid Request ", type);
            socket.emit("ERROR", "ERRSTRING: There was an error")
            break;
    }
}

function onDisconnection(){
    console.log('\x1b[36m%s\x1b[0m','a user disconnected');
}

module.exports = Connection_handler