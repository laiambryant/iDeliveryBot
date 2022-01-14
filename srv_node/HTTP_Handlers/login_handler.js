const m_send_msg = require("../Monitor/m_send_msg")
const user = require("../schemas/user")
const assert = require("assert")

module.exports = function login_handler(socket, type, data, monitor_socket){
    console.log("Login Request incoming")
    var json_data = JSON.parse(data)
    var monitor_data = data.replaceAll("\"", "")
    
    user.findOne({username:json_data.username}).then(function(res){
        try{
            assert(res.username===json_data.username)
            if(json_data.password == res.password){
                user.updateOne({username:json_data.username}, {logged_in:true})
                socket.emit("LOGIN_SUCCESS", res.username, res.x_pos, res.y_pos)
            } else {
                console.log("Incorrect Pw")
                socket.emit("LOGIN_FAILURE", "Incorrect Password")
            }
        }catch(err){
            socket.emit("LOGIN_FAILURE", "You must insert a username and a password")
        }
    })
    m_send_msg(monitor_data, type, monitor_socket)
}

/* 
 user.find({}).then(function(res){
                for (let i = 0; i < res.length; i++) {
                    res[i].username
                }
            })
*/