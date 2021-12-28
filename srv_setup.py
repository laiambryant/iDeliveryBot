import os
import threading

TEST=True

class myThread(threading.Thread):
    def __init__(self, threadID, name, counter, func):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
        self.func = func
    def run(self):
        print ("Starting " + self.name)
        self.func()
        print ("Exiting " + self.name)

def setup():
    os.spawnvp(mode=os.P_WAIT, file="npm", args=["setup", "install"])

def launch_srv():
    os.spawnvp(mode=os.P_WAIT, file="node", args=["server","srv_node/app.js"])

setup_thread = myThread(1, "Setup_Thread", 1, setup)
launch_thread = myThread(2, "Launch_Thread", 2, launch_srv)

setup_thread.start()
setup_thread.join()
launch_thread.start()
launch_thread.join()

print ("Exiting Main Thread")