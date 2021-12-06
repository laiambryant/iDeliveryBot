module.exports = function comm_handler(socket){
    socket.on("data", (data,err)=>{
        if(!err) console.log(data)
        else console.log(err)
    })
}