const express = require('express');
const Connection_handler = require("./HTTP_Server/requests");
const comm_handler = require("./Monitor/comm_handler")

//TCP SERVER COMMUNICATING WITH MONITOR
const net = require("net");
const tcp_port = 5000 

//HTTP SERVER COMMUNICATING WITH APP
const app = express(); 
const http = require('http').Server(app);
const io = require('socket.io')(http);
const port = process.env.PORT || 5050;

var monitor_sock;

//TCP SERVER
tcp_server = net.createServer();
tcp_server.listen(tcp_port, "127.0.0.1" ,()=>{
    console.log("[Monitor]:Monitor_communication initialized on port: " + tcp_port +"\n")
})
tcp_server.on("connection", (socket)=>{
    monitor_sock = socket
    comm_handler(socket)
})

//HTTP SERVER
app.use(express.static(__dirname)); 
try{
    http.listen(port, () => {
        console.log('[Server]:listening on port ' + port); 
    });
}catch(error){
    console.log("Could not Start server, restart server:")
    console.log(error)
}

io.sockets.on("connection", (socket)=>{
    Connection_handler(socket, monitor_sock)
})
