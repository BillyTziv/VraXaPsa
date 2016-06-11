# VraXaPsa
VraXaPsa is a 2D tetris like game. VraXaPsa game was developed for Computer Graphics and Interactive Systems, an undergraduate course in Computer Sience and Englneering Department of Ioannina, University of Ioannina and was finally reviewed by Ioannis Fudos.

Video link: https://youtu.be/5GzoTVR9vcQ
![Alt text](https://github.com/BillyTziv/VraXaPsa/blob/master/images/vraxapsa.png "VraXaPsa")

#Concept
The concept is the same, as the one in a simple tetris game but instead of various cube shapes, the possible objects that may be dropping from the top are rocks, scissors, papers, bombs and magic cubes. Some of the objects win/'eat' others. For example, a rock wins all scissors and a paper wins all rocks. Bombs win everything and magic cubes can be win other by bombs.

The project was developed in C++ language using openGL graphics library.

#Installation
To run and play the game, OpenGL is necessary. In Ubuntu 16.04LTS you will need to follow the next steps in order to install the OpenGL and play the game.

    sudo apt-get install build-essential
    sudo apt-get install freeglut3 freeglut3-dev
    Download the library from http://www.rpmseek.com/rpm-pl/libglui2c2.html?hl=com&cs=libgcc1:RE:0:0:0:0:2420 according to your system. Then use sudo dpkg -i to install it.

Now you should be able to play the game! Enjoy! :)

# How to play
First you need to make the executable. Run
make all
and then
for one player ./vraxapsa 1
for two players ./vraxapsa 2

#Contact
Please feel free to contact me for anything you might want in vtzivaras@gmail.com
