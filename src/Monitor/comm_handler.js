module.exports = function comm_handler(socket){
    socket.setEncoding("utf-8")
    console.log("[Node]Connected to monitor")
    socket.on("data", (data)=>{
        console.log("[Monitor]:%s", data)
        
    })
    socket.on("error",(error)=>{
        console.log(error)
    })
}

