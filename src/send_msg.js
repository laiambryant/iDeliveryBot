const fs = require('fs');
const {Module} = require('module')

const monitor_comm_in_path = "../iDelivery_bot_logic/src/srv_monitor/products/in.txt"

var msg_counter = 0

module.exports = function send_msg(msg, type) {

    ret = "[" + msg_counter + "," + type + "]:" + msg

    fs.writeFile(monitor_comm_in_path, ret , function(err){
        if(err){
            return console.log(err);
        }
    });

    msg_counter+=1

}
