var Bot = require("../../schemas/bot")
const mongoose = require("mongoose")
    mongoose.connect("mongodb://localhost:27017/users").then(function(){
        var bot = new Bot({
            id:1,
            x_pos:900,
            y_pos:700
        });     bot.save();
    });    