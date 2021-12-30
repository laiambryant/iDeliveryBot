# iDeliveryBot



## Preliminary actions

To run the code some preliminary setup steps must be taken. To run this software you will need to have installed Docker (https://www.docker.com/), git (https://git-scm.com/) and ROS(http://wiki.ros.org/) on your device. First of all you must clone and compile the srrg2_orazio and srrg2_webctl (master branch if on ubuntu <= 18.04, test_20.04 if on ubuntu 20.04)repositories. <br>

### srrg2_orazio
<code> \$ git clone https://gitlab.com/srrg-software/srrg2_orazio </code>

### srrg2_webctl (ubuntu <= 18.04)
<code>\$ git clone https://gitlab.com/srrg-software/srrg2_webctl </code>

### srrg2_webctl (ubuntu 20.04)
<code>\$ git clone https://gitlab.com/srrg-software/srrg2_webctl --branch=test_20.04</code> <br>

Compile the content of the two repositories (srrg2_orazio with <code>catkin build</code>, webctl with <code>make all</code>) and then, while in the srrg2_orazio/devel folder, run the following command:
<br> <code>\$ source setup.bash </code> <br>

Should you not want to run all these setup steps you can run the install_dependencies.py script using the following command:<br>
<code>\$ python utils/scripts/install_dependencies.py <br><br> </code> 


## Running 
Then, while in the root directory, run the following command to run the server: <br>
<code>\$ python utils/scripts/srv_setup.py <br><br> </code> 
This script will run npm install to install dependencies and then run the node js server. After running the server, always in the root directory, run the other script in another terminal using the following command: <br>
<code>\$ python .py <br><br> </code>


### Links

| Name | Site | Link |
|------|------|------|
| srrg2_orazio | gitlab |  https://gitlab.com/srrg-software/srrg2_orazio 
| srrg2_webctl | gitlab |  https://gitlab.com/srrg-software/srrg2_webctl  |
srrg2_webctl (ubuntu 20.04) | gitlab | https://gitlab.com/srrg-software/srrg2_webctl --branch=test_20.04 