// The almighty express
const express = require('express');

//Mongodb
const mongoose = require("mongoose")

// My Modules
const Connection_handler = require("./HTTP_Handlers/requests");
const comm_handler = require("./Monitor/comm_handler")
const robo_pos_periodic_update = require("./HTTP_Handlers/robo_pos_periodic_update")

// TCP SERVER COMMUNICATING WITH MONITOR
const net = require("net");
const tcp_port = 5000 

// HTTP SERVER COMMUNICATING WITH APP
const app = express(); 
const http = require('http').Server(app);
const io = require('socket.io')(http);
const port = process.env.PORT || 5050;
var monitor_sock;

//T to fetch position of bot
const T = 6000 //ms

// MongoDB Connection
mongoose.connect("mongodb://localhost:27017/users").then(()=>{
    console.log('\x1b[35m%s\x1b[0m',"Connected to MongoDB...")
}).catch((err)=>{
    console.log('\x1b[31m%s\x1b[0m',err)
})

// TCP SERVER
tcp_server = net.createServer();
tcp_server.listen(tcp_port, "127.0.0.1" ,()=>{
    console.log('\x1b[33m%s\x1b[0m', "[Monitor]:Monitor_communication initialized on port: " + tcp_port)
})
tcp_server.on("connection", (socket)=>{
    console.log("Monitor connected")
    monitor_sock = socket
})

//Server for pos updates
tcp_pos_server = net.createServer();
tcp_pos_server.listen(tcp_port+1, "127.0.0.1", ()=>{
    console.log('\x1b[33m%s\x1b[0m', "[POS_UPDATE]:Waiting for bot position updates on port: " + tcp_port + 1)
})
tcp_pos_server.on("connection", (socket)=>{
    comm_handler(socket)
})


// HTTP SERVER
app.use(express.static(__dirname)); 
try{
    http.listen(port, () => {
        console.log('\x1b[36m%s\x1b[0m', '\n[Server]:listening on port ' + port); 
    });
}catch(error){
    console.log('\x1b[31m%s\x1b[0m',error)
}

io.sockets.on("connection", (socket)=>{
    Connection_handler(socket, monitor_sock)
    robo_pos_periodic_update(io,T)
})