const { stringify } = require("mocha/lib/utils");
const bot = require("../schemas/bot");

module.exports = function monitor_event_handler(data, other_users){

    //[5,ROBO_POS]:{x_pos:49.442328,y_pos:11.765573}
    //[6,TIMEOUT]:{} da inviare a tutti
    //[7,DELIVERED]:{from:adamkadmon, to:francescototti} da inviare a tutti

    var spl = data.split("]:");
    var json = JSON.parse(spl[1]);
    var header = spl[0];
    var type = "";
    if(header.indexOf("TIMEOUT")!=-1)
        type = "TIMEOUT";
    if(header.indexOf("ROBO_POS")!=-1)
        type = "ROBO_POS";
    if(header.indexOf("DELIVERED")!=-1)
        type = "DELIVERED";

    switch (type) {
        case "ROBO_POS":
            x = parseInt(json.x_pos);
            y = parseInt(json.y_pos);
            bot.find({id:1}).updateOne({x_pos:x, y_pos:y}).then(function(){
                console.log("New x: ", x, "\t New y: ", y);
            });
            break;
        case "TIMEOUT":
            other_users.emit("TIMEOUT",json);
            break;
        case "DELIVERED":
            other_users.emit("DELIVERED", json);
            break;
        default:
            break;
    }

};