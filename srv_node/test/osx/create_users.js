var user = require("../../schemas/user")
const mocha = require("mocha")
const mongoose = require("mongoose")

describe("User creation",function(){
    it("Creates three users in mongoDB",function(done){
        mongoose.connect("mongodb://localhost:27017/users").then(function(){
            var user1 = new user({
                id:0,
                username:"adamkadmon",
                password:"illuminati_666",
                x_pos:92,
                y_pos:10,
                logged_in:false
            });     user1.save();
            // [ INFO] [1643912286.681825336, 17006.900000000]: {"x_pos":"23.163481","y_pos":"41.337284"}
            var user2 = new user({
                id:1,
                username:"FrancescoTotti",
                password:"forzamagica_Werpupone",
                x_pos:23,
                y_pos:41,
                logged_in:false
            });      user2.save()
            //[ INFO] [1643911851.054858104, 16571.200000000]: {"x_pos":"81.146609","y_pos":"37.821674"}
            var user3 = new user({
                id:2,
                username:"dr_lecter",
                password:"willgraham123",
                x_pos:81,
                y_pos:38,
                logged_in:false
            });     user3.save()   
        });     done()
    })
})