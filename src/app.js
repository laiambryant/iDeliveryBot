const express = require('express');
const Connection_handler = require("./HTTP_Server/requests");
const comm_handler = require("./Monitor/comm_handler")

//HTTP SERVER COMMUNICATING WITH APP
const app = express(); 
const http = require('http').Server(app);
const io = require('socket.io')(http);
const port = process.env.PORT || 8080;


//TCP SERVER COMMUNICATING WITH MONITOR
const net = require("net");
const tcp_port = 6000 

//HTTP SERVER
app.use(express.static(__dirname)); 

io.sockets.on("connection", (socket)=>{
    Connection_handler(socket)
})

http.listen(port, () => {
    console.log('[Server]:listening on port ' + port);
});

//TCP SERVER
tcp_server = net.createServer();

tcp_server.listen(tcp_port, "127.0.0.1" ,()=>{
    console.log("\n[Monitor]:Monitor_communication initialized on port: " + tcp_port)
})

tcp_server.on("connection", (socket)=>{
    comm_handler(socket)
})
 

