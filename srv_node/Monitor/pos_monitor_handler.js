var robo_pos_handler = require("./robo_pos_handler");

module.exports = function comm_handler(socket){
    socket.setEncoding("utf-8");

    socket.on("data", function(data){ 
        robo_pos_handler(data);
    });
    
    socket.on("error",function(error){
        console.log('\x1b[31m%s\x1b[0m',error);
    });
};

//[5,ROBO_POS]:{x_pos:49.442328,y_pos:11.765573}