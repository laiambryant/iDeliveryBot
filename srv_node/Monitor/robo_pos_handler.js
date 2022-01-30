const bot = require("../schemas/bot")

module.exports = function robo_pos_handler(data){
    var spl = data.split("]:")
    var json = JSON.parse( spl[1])
    x = parseInt(json.x_pos)
    y = parseInt(json.y_pos)

    console.log(x, y)

    x = x * 18
    y = y * 64

    //x:899.0,y:699
    //x:49.0, y:11

    bot.find({id:1}).updateOne({x_pos:x})
    bot.find({id:1}).updateOne({y_pos:y}).then(function(res){
        console.log(res)
    })
    
}