var user = require("../../schemas/user")
const mongoose = require("mongoose")

mongoose.connect("mongodb://localhost:27017/users").then(function(){
    var user1 = new user({
        id:0,
        username:"adamkadmon",
        password:"illuminati_666",
        x_pos:38,
        y_pos:-14,
        logged_in:false
    });     user1.save();
    var user2 = new user({
        id:1,
        username:"FrancescoTotti",
        password:"forzamagica_Werpupone",
        x_pos:-30,
        y_pos:16,
        logged_in:false
    });      user2.save()

    var user3 = new user({
        id:2,
        username:"dr_lecter",
        password:"willgraham123",
        x_pos:28,
        y_pos:13,
        logged_in:false
    });     user3.save()     
});   
