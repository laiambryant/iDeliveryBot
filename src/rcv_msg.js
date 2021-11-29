const fs = require('fs');

const monitor_comm_out_path = "../iDelivery_bot_logic/src/srv_monitor/products/out.txt"

module.exports = function read_msg(){
    
    fs.readFile(monitor_comm_out_path, 'utf-8', function(err, data){
        if(err) return console.log(err);
        return console.log(data);
    });

}