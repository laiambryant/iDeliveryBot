# iDeliveryBot

This application uses ROS, C++, and Node.js to implement a pick and delivery service.

## Preliminary actions

To run the code some preliminary setup steps must be taken. To run this software you will need to have installed git (<https://git-scm.com/>), node.js(<https://nodejs.org/en/>) and ROS(<http://wiki.ros.org/>) on your device. First of all you must clone and compile the srrg2_orazio and srrg2_webctl (master branch if on ubuntu <= 18.04, test_20.04 if on ubuntu 20.04) repositories. <br>

### <b>srrg2_orazio</b>

<code>\$ git clone <https://gitlab.com/srrg-software/srrg2_orazio> </code>

### <b> srrg2_webctl (ubuntu <= 18.04) </b>

<code>\$ git clone <https://gitlab.com/srrg-software/srrg2_webctl> </code>

### <b> srrg2_webctl (ubuntu 20.04) </b>

<code>\$ git clone <https://gitlab.com/srrg-software/srrg2_webctl> --branch=test_20.04</code> <br>

Compile the content of the two repositories (srrg2_orazio with <code>catkin build</code>, webctl with <code>make all</code>) and then run the following command:
<br> <code>\$ source srrg2_labaigi/devel/setup.bash </code> <br>

Now compile the code from this repository navigating into the /logic folder and running <code>catkin build</code> followed by <code>\$ source devel/setup.bash </code>

## Running

Then, while in the root directory, run the following command to run the server: <br>
<code>\$ python utils/scripts/srv_setup.py <br><br> </code>
This script will run npm install to install dependencies and then run the node js server. <br>
Now you have to launch the webctl to launch the srrg2_labaigi nodes. Run the following command to check if dependency conditions are all met and to run webctl:<br>
<code>\$ python utils/scripts/install_dependencies.py <br><br> </code>

Open your browser and go to the following address: http://localhost:9001. You wil then be able to launch the nodes that are necessary. Run the following nodes:<br>
1. roscore
2. stage
3. mapserver
4. rviz
5. localize
6. planner
7. follower

You now have to launch my nodes in any order using the following commands:<br>


<code>\$ rosrun monitor monitor <br> </code>
<code>\$ rosrun delivery delivery <br> </code>
<code>\$ rosrun pos_update pos_update <br> </code>
<br>

The app now is working. You can connect now with the clients app you can find at the following address: https://github.com/laiambryant/iDelivery_bot_client

Alternatively you can 

## Links

| Name | Site | Link |
|------|------|------|
| srrg2_orazio | gitlab |  <https://gitlab.com/srrg-software/srrg2_orazio>
| srrg2_webctl | gitlab |  <https://gitlab.com/srrg-software/srrg2_webctl>  |
srrg2_webctl (ubuntu 20.04) | gitlab | <https://gitlab.com/srrg-software/srrg2_webctl> --branch=test_20.04
|js func| thewebdev.info | <https://thewebdev.info/2021/08/13/how-to-fix-the-javascript-replaceall-is-not-a-function-error/>
