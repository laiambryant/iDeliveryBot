import threading
import colors as c

#Very simple thread implementation, spawns thread with the function passed in constructor
class myThread(threading.Thread):
    def __init__(self, threadID, name, counter, func):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
        self.func = func
    def run(self):
        print (c.colors.THREAD_MSG + "Starting " + self.name + c.colors.RESET)
        self.func()
        print (c.colors.THREAD_MSG +"Exiting " + self.name + c.colors.RESET)

