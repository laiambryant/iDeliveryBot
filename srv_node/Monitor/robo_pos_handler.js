const bot = require("../schemas/bot")

module.exports = function robo_pos_handler(data){
    var spl = data.split("]:")
    var json = JSON.parse( spl[1])
    x = parseInt(json.x_pos)
    y = parseInt(json.y_pos)

    bot.find({id:1}).updateOne({x_pos:x, y_pos:y}).then(function(){
        console.log("New x: ", x, "\t New y: ", y)
    })
}