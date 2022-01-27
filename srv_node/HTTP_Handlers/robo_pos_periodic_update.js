const bot = require("../schemas/bot")

module.exports = function robo_pos_periodic_update(io, T_period){
    // TODO: Emit every T seconds the position of bot to all sockets
    setInterval(()=>{
        //fetch position from DB (That will rcv updates from monitor)
        bot.find({}).then(function(res){
            //send position to all clients connected to socket
            io.emit("ROBO_POS", res)
        });
        
    }, T_period)   
}
