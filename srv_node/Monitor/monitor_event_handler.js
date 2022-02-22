const bot = require("../schemas/bot");
var prev_pos = [0,0];

module.exports = function monitor_event_handler(data, other_users){

    //[5,ROBO_POS]:{x_pos:49.442328,y_pos:11.765573}
    //[49,SEND]:{"x_sender":"92.000000","y_sender":"10.000000","x_reciever":"38.000000","y_reciever":"0.000000"}
    //[45,ARRIVED]:{"x_sender":"92.000000","y_sender":"10.000000","x_reciever":"10.000000","y_reciever":"0.000000"}
    //[7,DELIVERED]:{from:adamkadmon, to:francescototti} da inviare a tutti
    //[43,OBJ_RCV]:{"x_sender":"92.000000","y_sender":"10.000000","x_reciever":"10.000000","y_reciever":"0.000000"}
    //[24,CANCEL]:{}
    //[20,TIMEOUT]


    var spl = data.toString().split("]:");
    var json = JSON.parse(spl[1]);
    var header = spl[0];
    var type = "";



    if(header.indexOf("CALL")!=-1)
        type = "CALL";
    if(header.indexOf("SEND")!=-1)
        type = "SEND";
    if(header.indexOf("DELIVERED")!=-1)
        type = "DELIVERED";
    if(header.indexOf("OBJ_RCV")!=-1)
        type = "OBJ_RCV";
    if(header.indexOf("CANCEL")!=-1)
        type = "CANCEL";
    if(header.indexOf("TIMEOUT")!=-1)
        type = "TIMEOUT";
    if(header.indexOf("ROBO_POS")!=-1)
        type = "ROBO_POS";
    if(header.indexOf("ARRIVED")!=-1)
        type = "ARRIVED";
    switch (type) {
        case "ROBO_POS":
            x = parseInt(json.x_pos);
            y = parseInt(json.y_pos);
            bot.find({id:1}).updateOne({x_pos:x, y_pos:y}).then(function(){
                if(prev_pos[0]!=x&&prev_pos[1]!=y){
                    console.log("Old Position", prev_pos[0], prev_pos[1]);
                    prev_pos[0]=x; prev_pos[1]=y;
                    console.log("Updated Position", prev_pos[0], prev_pos[1]);
                }
            });
            break;
        case "CALL":
            other_users.emit("CALL_RES", json);
            break;
        case "SEND":
            other_users.emit("SEND_RES", json);
            break;
        case "DELIVERED":
            other_users.emit("DELIVERED_RES", json);
            break;
        case "OBJ_RCV":
            other_users.emit("OBJ_RCV_RES", json);
            break;
        case "CANCEL":
            other_users.emit("CANCEL_RES", json);
            break;
        case "TIMEOUT":
            other_users.emit("TIMEOUT_RES", json);
            break;  
        case "ARRIVED":
            other_users.emit("ARRIVED_RES", json);
            break;           
        default:
            console.log("Invalid Header", header);
            break;
    }


};