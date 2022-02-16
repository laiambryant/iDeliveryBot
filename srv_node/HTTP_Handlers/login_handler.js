const m_send_msg = require("../Monitor/m_send_msg");
const user = require("../schemas/user");
const assert = require("assert");

module.exports = function login_handler(socket, type, data, monitor_socket){
    console.log('\x1b[36m%s\x1b[0m',"Login Request incoming");
    var json_data = JSON.parse(data);
    
    //SRC: https://thewebdev.info/2021/08/13/how-to-fix-the-javascript-replaceall-is-not-a-function-error/
    if (typeof String.prototype.replaceAll == "undefined") {  
        String.prototype.replaceAll = function(match, replace) {  
          return this.replace(new RegExp(match, 'g'), () => replace);  
        } ;
    } 
    var monitor_data = data.replaceAll("\"", "");
    user.findOne({username:json_data.username}).then(function(res){
        try{
            assert(res.username===json_data.username);
            if(json_data.password == res.password){
                user.updateOne({logged_in:true});
                socket.emit("LOGIN_SUCCESS", res.username, res.x_pos, res.y_pos);
                    user.find({}).then(function(res){
                        socket.emit("USERS", res);
                    });
                monitor_data = monitor_data.replace("}",",x_pos:"+res.x_pos+",y_pos:" +res.y_pos +"}");
            } else {
                console.log('\x1b[31m%s\x1b[0m',"Incorrect Pw");
                socket.emit("LOGIN_FAILURE", "Incorrect Password");
            }
        }catch(err){
            socket.emit("LOGIN_FAILURE", "You must insert a username and a password");
        }
    }).then(function(){
        m_send_msg(monitor_data, type, monitor_socket);
    });
};