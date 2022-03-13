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
        type = "CALL_RES";
    if(header.indexOf("SEND")!=-1)
        type = "SEND_RES";
    if(header.indexOf("DELIVERED")!=-1)
        type = "DELIVERED_RES";
    if(header.indexOf("OBJ_RCV")!=-1)
        type = "OBJ_RCV_RES";
    if(header.indexOf("CANCEL")!=-1)
        type = "CANCEL_RES";
    if(header.indexOf("TIMEOUT")!=-1)
        type = "TIMEOUT_RES";
    if(header.indexOf("ROBO")!=-1)
        type = "ROBO_POS";
    if(header.indexOf("ARRIVED")!=-1)
        type = "ARRIVED_RES";
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
        case "CALL_RES":
            other_users.emit("CALL_RES", json);
            console.log("Sending <", type, "> response");
            break;
        case "SEND_RES":
            other_users.emit("SEND_RES", json);
            console.log("Sending <", type, "> response");
            break;
        case "DELIVERED_RES":
            other_users.emit("DELIVERED_RES", json);
            console.log("Sending <", type, "> response");
            break;
        case "OBJ_RCV_RES":
            other_users.emit("OBJ_RCV_RES", json);
            console.log("Sending <", type, "> response");
            break;
        case "CANCEL_RES":
            other_users.emit("CANCEL_RES", json);
            console.log("Sending <", type, "> response");
            break;
        case "TIMEOUT_RES":
            other_users.emit("TIMEOUT_RES", json);
            console.log("Sending <", type, "> response");
            break;  
        case "ARRIVED_RES":
            other_users.emit("ARRIVED_RES", json);
            console.log("Sending <", type, "> response");
            break;           
        default:
            console.log("Invalid Header", header);
            console.log("Sending <", type, "> response");
            break;
    }


};