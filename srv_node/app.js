// The almighty express
const express = require('express');

//Mongodb
const mongoose = require("mongoose");

// My Modules
const Connection_handler = require("./HTTP_Handlers/requests");
const monitor_event_handler = require("./Monitor/monitor_event_handler");
const robo_pos_periodic_update = require("./HTTP_Handlers/robo_pos_periodic_update");

// TCP SERVER COMMUNICATING WITH MONITOR
const monitor_net = require("net");
const monitor_port = 5000 ;
var monitor_sock;

//TCP SERVER POS_UPDATE
const pos_update_net = require("net");
const pos_monitor_handler = require('./Monitor/pos_monitor_handler');
const pos_update_port = 5100;
var pos_update_sock;

// HTTP SERVER COMMUNICATING WITH APP
const app = express(); 
const http = require('http').Server(app);
const io = require('socket.io')(http);
const port = process.env.PORT || 5050;

//T to fetch position of bot
const T = 6000; //ms

// MongoDB Connection
mongoose.connect("mongodb://localhost:27017/users").then(function(){
    console.log('\x1b[35m%s\x1b[0m',"Connected to MongoDB...");
}).catch(function(err){
    console.log('\x1b[31m%s\x1b[0m',err);
});

// TCP SERVER
tcp_server = monitor_net.createServer();
tcp_server.listen(monitor_port, "127.0.0.1" ,function(){
    console.log('\x1b[33m%s\x1b[0m', "[MONITOR]:Monitor_communication initialized on port: " + monitor_port);
});
tcp_server.on("connection", function(socket){
    console.log('\x1b[33m%s\x1b[0m',"Monitor connected");
    monitor_sock = socket;
});
tcp_server.on("close", function(){
    console.log("Monitor disconnected");
});

//Server for pos updates
tcp_pos_server = pos_update_net.createServer(); 
tcp_pos_server.listen(pos_update_port, "127.0.0.1", function(){
    console.log('\x1b[34m%s\x1b[0m', "[POS_UPDATE]:Waiting for bot position updates on port: " + (pos_update_port));
});
tcp_pos_server.on("connection", function(pos_socket){
    pos_update_sock = pos_socket;
    pos_monitor_handler(pos_update_sock, io.sockets);
});
tcp_pos_server.on("close", function(){
    console.log("\x1b[33m", "[POS_UPDATE]: Pos updater disconnected");
});

// HTTP SERVER
app.use(express.static(__dirname)); 
try{
    http.listen(port, function(){
        console.log('\x1b[36m%s\x1b[0m', '\n[SERVER]:listening on port ' + port); 
    });
}catch(error){
    console.log('\x1b[31m%s\x1b[0m',error);
}

io.sockets.on("connection", function(generic_sock){
    Connection_handler(generic_sock, monitor_sock);
    robo_pos_periodic_update(io,T);
});