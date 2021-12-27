# iDeliveryBot



## Instructions 

To run the code some preliminary setup steps must be taken. To run this software you will need to have installed Docker (https://www.docker.com/), git (https://git-scm.com/) and ROS(http://wiki.ros.org/) on your device. First of all you must clone and compile the srrg2_orazio and srrg2_webctl (master branch if on ubuntu <= 18.04, test_20.04 if on ubuntu 20.04)repositories. <br>

### srrg2_orazio
<code> \$ git clone https://gitlab.com/srrg-software/srrg2_orazio </code>

### srrg2_webctl (ubuntu <= 18.04)
<code>\$ git clone https://gitlab.com/srrg-software/srrg2_webctl </code>

### srrg2_webctl (ubuntu 20.04)
<code>\$ git clone https://gitlab.com/srrg-software/srrg2_webctl --branch=test_20.04</code>

<br>Compile the content of the two repositories (srrg2_orazio with catkin build, webctl with make all) and then, while in the srrg2_orazio/devel folder, run the following command:
<br> <code>\$ source setup.bash </code> <br> <br>

Then, while in the directory, build the docker container of the server and run it with the following commands: <br>
<code>\$ sudo docker build srv_node/ -t srv_node <br> \$ sudo docker run srv_node <br><br> </code>
Or, if you prefer using docker-compose use the following command: <br>
<code>\$ sudo docker-compose up</code>


### Links

| Name | Site | Link |
|------|------|------|
| srrg2_orazio | gitlab |  https://gitlab.com/srrg-software/srrg2_orazio 
| srrg2_webctl | gitlab |  https://gitlab.com/srrg-software/srrg2_webctl  |
srrg2_webctl (ubuntu 20.04) | gitlab | https://gitlab.com/srrg-software/srrg2_webctl --branch=test_20.04 