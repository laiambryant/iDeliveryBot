import my_thread as Thread
import colors as c
import os
import platform
import shutil

ORAZIO_GIT_REPO = "https://gitlab.com/grisetti/labiagi_2020_21.git"
WEBCTL_GIT_REPO = "https://gitlab.com/srrg-software/srrg2_webctl"

def clone_webctl():
    if(not os.path.exists("srrg2_webctl")):
        if(platform.system()=="Linux"):
            if(platform.version().find("20.04")>0):
                print(c.colors.MSG + "Ubuntu 20.04 webctl download..." + c.colors.RESET)
                os.spawnvp(mode=os.P_WAIT, file="git", args=["webctl_clone","clone", WEBCTL_GIT_REPO, "-b", "test_20.04"])
            if(platform.version().find("18.04")>0):
                print(c.colors.MSG +"Ubuntu 18.04 webctl download..." + c.colors.RESET)
                os.spawnvp(mode=os.P_WAIT, file="git", args=["webctl_clone","clone", WEBCTL_GIT_REPO])
            if(platform.version().find("18.04")<0 and platform.version().find("20.04")<0):
                print(c.colors.FAIL +"Unsupported linux version" + c.colors.RESET)
        elif(platform.system()!="Linux"):
            print(c.colors.FAIL + "Unsupported OS" + c.colors.RESET)
    elif(os.path.exists("srrg2_webctl")):
        print(c.colors.WARNING + "Webctl already exists..." + c.colors.RESET)

def clone_orazio():
    if(not os.path.exists("srrg2_labiagi")):
        print(c.colors.MSG +"Cloning Orazio Repository..." + c.colors.RESET)
        os.spawnvp(mode=os.P_WAIT, file="git", args=["orazio_clone","clone", ORAZIO_GIT_REPO])
        print(c.colors.MSG +"Cleaning Orazio Repository..." + c.colors.RESET)
        os.chdir("labiagi_2020_21/workspaces")
        try :
            shutil.move(src="srrg2_labiagi", dst="../../")
        except:
            print(c.colors.WARNING + "Folder already exists" + c.colors.RESET)
        os.chdir("../../")
        shutil.rmtree(path="labiagi_2020_21")
    if(os.path.exists("srrg2_labiagi")):
        print(c.colors.WARNING + "Didn't need to clone, dir already exists" + c.colors.RESET)
   

def compile_orazio():
    print(c.colors.MSG +"Compiling orazio..." + c.colors.RESET)
    if(not os.path.exists("srrg2_labiagi/build")):
        os.chdir("srrg2_labiagi")    
        os.spawnvp(mode=os.P_WAIT, file="catkin", args=["compile_orazio","build"])
        os.chdir("..")
    elif(os.path.exists("srrg2_labiagi/build")):
        print(c.colors.WARNING + "To recompile orazio run catkin clean before running script..." + c.colors.RESET)

def compile_webctl():
    print(c.colors.MSG +"Compiling webctl" + c.colors.RESET)
    os.chdir("srrg2_webctl")
    if(os.path.exists("proc_webctl")):
        print(c.colors.WARNING)
    os.spawnvp(mode=os.P_WAIT, file="make", args=["compile_webctl","all"])
    os.chdir("..")
    print(c.colors.RESET)

def source_orazio():
    print(c.colors.MSG +"Adding to ros env..."+ c.colors.RESET)
    os.spawnvp(mode=os.P_WAIT, file="source", args=["source orazio","srrg2_labiagi/devel/setup.sh"])

def run_webctl():
    print(c.colors.MSG +"Starting webctl..."+ c.colors.RESET)
    os.chdir("srrg2_webctl")
    os.spawnvp(mode=os.P_WAIT, file="./proc_webctl", args=["start webctl","../srrg2_labiagi/src/srrg2_navigation_2d/config/run_navigation.webctl"])
    os.chdir("..")

webctl_clone_thread = Thread.myThread(1, "clone_Webctl", 1, clone_webctl)
orazio_clone_thread = Thread.myThread(2, "clone_orazio", 2, clone_orazio)
webctl_compile_thread = Thread.myThread(3, "compile_webctl", 3,compile_webctl)
orazio_compile_thread = Thread.myThread(4, "compile_orazio", 4,compile_orazio)
orazio_source_thread = Thread.myThread(5, "source_orazio", 5, source_orazio)
webctl_run_thread = Thread.myThread(6, "run_webctl", 6, run_webctl)

#Downloads repo contents
webctl_clone_thread.start()
webctl_clone_thread.join()
orazio_clone_thread.start()
orazio_clone_thread.join()

#Compiles WebCtl
webctl_compile_thread.start()
webctl_compile_thread.join()

#Compiles Orazio
orazio_compile_thread.start()
orazio_compile_thread.join()

#Adds setup.bash to source
orazio_source_thread.start()
orazio_source_thread.join()

#starts webctl using run_navigation.webctl
webctl_run_thread.start()
webctl_run_thread.join()