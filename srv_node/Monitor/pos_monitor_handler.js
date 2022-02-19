var monitor_event_handler = require("./monitor_event_handler");

module.exports = function comm_handler(socket, other_users){
    socket.setEncoding("utf-8");

    socket.on("data", function(data){ 
        monitor_event_handler(data, other_users);
    });
    
    socket.on("error",function(error){
        console.log('\x1b[31m%s\x1b[0m',error);
    });
};