var Bot = require("../../schemas/bot")
const mongoose = require("mongoose")
    mongoose.connect("mongodb://localhost:27017/users").then(function(){
        var bot = new Bot({
            id:1,
            x_pos:49,
            y_pos:11
        });     bot.save();
    });    


//    [ INFO] [1643910926.974775957, 15647.200000000]: {"x_pos":"49.376978","y_pos":"11.776821"}
