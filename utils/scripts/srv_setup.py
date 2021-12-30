import os
import my_thread as Thread

def setup():
    os.chdir("srv_node")
    os.spawnvp(mode=os.P_WAIT, file="npm", args=["setup", "install"])
    os.chdir("..")

def launch_srv():
    os.spawnvp(mode=os.P_WAIT, file="node", args=["server","srv_node/app.js"])

setup_thread = Thread.myThread(1, "Setup_Thread", 1, setup)
srv_launch_thread = Thread.myThread(2, "Launch_Thread", 2, launch_srv)

setup_thread.start()
setup_thread.join()
srv_launch_thread.start()
srv_launch_thread.join()