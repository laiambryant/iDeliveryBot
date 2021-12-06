const send_msg_to_monitor = require("./send_msg");
const rcv_msg = require("./rcv_msg")

function Connection_handler(socket){
    console.log('a user connected');
    socket.on('disconnect', onDisconnection);
    socket.onAny((type, data)=>{
        Request(socket, type, data)  
        console.log(data)  
    })
}

function Request(socket, type, data){
    switch (type) {
        case "LOGIN":
            console.log("Login Request incoming")
            send_msg_to_monitor(data, "LOGIN")
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