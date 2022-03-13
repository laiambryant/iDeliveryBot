// The almighty express
const express = require('express');

//Mongodb
const mongoose = require("mongoose");

// My Modules
const Connection_handler = require("./HTTP_Handlers/requests");
const robo_pos_periodic_update = require("./HTTP_Handlers/robo_pos_periodic_update");

// TCP SERVER COMMUNICATING WITH MONITOR
const monitor_net = require("net");
const monitor_port = 5000 ;
var monitor_cli_sock;

//TCP SERVER POS_UPDATE
const pos_update_net = require("net");
const pos_monitor_handler = require('./Monitor/pos_monitor_handler');
const pos_update_port = 5100;
var pos_update_cli_sock;

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
tcp_server.on('connection', function(cli_socket_srv){        
    console.log('\x1b[33m%s\x1b[0m',"Monitor connected");
    monitor_cli_sock = cli_socket_srv;
    pos_monitor_handler(cli_socket_srv, io.sockets);
});
tcp_server.on('end', function(){
    console.log('\x1b[33m%s\x1b[0m',"Monitor disconnected");
});
tcp_server.listen(monitor_port, "127.0.0.1" ,function(){
    console.log('\x1b[33m%s\x1b[0m', "[MONITOR]:Monitor_communication initialized on port: " + monitor_port);
});

//Server for pos updates
tcp_pos_server = pos_update_net.createServer();
tcp_pos_server.on('connection', function(cli_socket_srv_pos){
    pos_update_cli_sock = cli_socket_srv_pos;
    console.log("\x1b[33m", "[POS_UPDATE]: Pos updater connected");
    pos_monitor_handler(cli_socket_srv_pos, io.sockets);
});
tcp_pos_server.on('end', function(){
    console.log("\x1b[33m", "[POS_UPDATE]: Pos updater disconnected");
});
tcp_pos_server.listen(pos_update_port, "127.0.0.1" ,function(){
    console.log('\x1b[34m%s\x1b[0m', "[POS_UPDATE]:Waiting for bot position updates on port: " + (pos_update_port));
}); 

// HTTP SERVER
app.use(express.static(__dirname)); 
try{
    http.listen(port, function(){
        console.log('\x1b[36m%s\x1b[0m', '[SERVER]:listening on port ' + port); 
    });
}catch(error){
    console.log('\x1b[31m%s\x1b[0m',error);
}

io.sockets.on("connection", function(generic_sock){
    Connection_handler(generic_sock, monitor_cli_sock);
    robo_pos_periodic_update(io,T);
});