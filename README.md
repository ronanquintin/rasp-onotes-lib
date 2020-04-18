# rasp-onotes-lib

Contains Raspberry related content. Contains C++ material to drive my RaspberryPI with it. Released under GNU GPLv3 licence. 


# Compile

This program is written in C++ (version 11) and need wiringPi to compile. I've compile it on Raspbian without any prerequisite, but as I write and work on my Ubuntu and then compile and execute code on my Raspberry Pi I had to install devlopment libraries first :

```sh
sudo apt install libwiringpi-dev
```

Then all I have to to do is


```sh
make
```

And simply execute the binary :

```sh
./bin/rasp-onotes-lib
```


# Libraries

 * WiringPi
 
## WiringPi

As it is said at <http://wiringpi.com/> : *WiringPi is a PIN based GPIO access library written in C for the BCM2835, BCM2836 and BCM2837 SoC devices used in all Raspberry Pi*. I don't know much about this library or it's author "Gordon". I just can say that it is released under the GNU Lesser Public License version 3, and that Gordon seems to make some good looking bread.

# Webliography ressources

C++ Singleton : 
* <https://stackoverflow.com/questions/1008019/c-singleton-design-pattern>

Raspberry pins description : 
 * <https://www.raspberrypi.org/documentation/usage/gpio/>
 * <https://pinout.xyz/#>

Markdown Cheatsheet :
* <https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet>


