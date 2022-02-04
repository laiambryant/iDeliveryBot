# iDeliveryBot

This application uses ROS, C++, and Node.js to implement a pick and delivery service. This README will explain in detail how the various parts of the software were implemented and it will be structured in the following way:

1. Introduction to the software
2. Design Choices
3. Architecture
4. State and Transitions diagrams
5. Activity Diagrams
6. Preliminary actions
7. Running the project
8. Other
9. Further Expansions
10. Links

# 1) Introduction to the software 
This software handles pick and delivery logic for a robot running ROS. It is divided in 3 main blocks, clients, the server and the ros nodes. This specific Readme will only address the server and the ros nodes, to see what design choices were made in designing the client you shoud read the wiki for the client app, also available on my github at the following link: https://github.com/laiambryant/iDelivery_bot_client

# 2) Design Choices

# 3) Architecture

# 4) State and Transitions diagrams

# 5) Activity Diagrams

# 6) Preliminary actions

To run the code some preliminary setup steps must be taken. To run this software you will need to have installed git (<https://git-scm.com/>), node.js(<https://nodejs.org/en/>) and ROS(<http://wiki.ros.org/>) on your device. First of all you must clone and compile the srrg2_orazio and srrg2_webctl (master branch if on ubuntu <= 18.04, test_20.04 if on ubuntu 20.04) repositories. <br>

### srrg2_orazio

<code>\$ git clone <https://gitlab.com/srrg-software/srrg2_orazio> </code>

### <b> srrg2_webctl (ubuntu <= 18.04) </b>

<code>\$ git clone <https://gitlab.com/srrg-software/srrg2_webctl> </code>

### <b> srrg2_webctl (ubuntu 20.04) </b>

<code>\$ git clone <https://gitlab.com/srrg-software/srrg2_webctl> --branch=test_20.04</code> <br>

Compile the content of the two repositories (srrg2_orazio with <code>catkin build</code>, webctl with <code>make all</code>) and then, while in the srrg2_orazio/devel folder, run the following command:
<br> <code>\$ source setup.bash </code> <br>

Should you not want to run all these setup steps you can run the install_dependencies.py script using the following command:<br>
<code>\$ python utils/scripts/install_dependencies.py <br><br> </code>

## Running

Then, while in the root directory, run the following command to run the server: <br>
<code>\$ python utils/scripts/srv_setup.py <br><br> </code>
This script will run npm install to install dependencies and then run the node js server. After running the server, always in the root directory, run the other script in another terminal using the following command: <br>
<code>\$ python .py <br><br> </code>


# 7) Running the project

# 8) Other

# 9) Further Expansions

# 10) Links

| Name | Site | Link |
|------|------|------|
| srrg2_orazio | gitlab |  <https://gitlab.com/srrg-software/srrg2_orazio>
| srrg2_webctl | gitlab |  <https://gitlab.com/srrg-software/srrg2_webctl>  |
srrg2_webctl (ubuntu 20.04) | gitlab | <https://gitlab.com/srrg-software/srrg2_webctl> --branch=test_20.04
|js func| thewebdev.info | <https://thewebdev.info/2021/08/13/how-to-fix-the-javascript-replaceall-is-not-a-function-error/>
