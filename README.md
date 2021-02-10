# rasp-onotes-lib

Contains Raspberry related content. Contains Java, C++ sources material to drive my RaspberryPI with it. Also contains some hardware (sensors, engines, etc...) documentation. Released under GNU GPLv3 licence. 

# My Raspberries

I've got a Raspberry Pi 2 model B V1.1

# Java code

The Java source code is located in rasp-onotes-lib/sources/java, this project is named "Raspoji"

## Pi4jv2

I'm using pi4j v2 in order to use Java 11, even if this version is not stable. 

It depends on wiringPi which is installed on the raspianOS, and of course Java. To install java you have to execute thoses commands :

```sh
sudo apt update
sudo apt install openjdk-8-jdk
```

And then install pi4J to launch the java code :

```sh
curl -sSL https://pi4j.com/install | sudo bash
```

## Raspoji

The raspoji code is packaged with maven, it has to be installed : 

```sh
sudo apt update
sudo apt -y install maven
```

Then simply go to rasp-onotes-lib/sources/java/raspoji and type :

```sh
mvn clean install
```

And then 

```sh
cd packaging/target/raspoji/
chmod u+x launch-raspoji.sh
./launch-raspoji.sh
```

# C++ code

The C++ source code is located into rasp-onotes-lib/sources/cplusplus
 
## Compile
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


## Libraries

 * WiringPi
 
## WiringPi

As it is said at <http://wiringpi.com/> : *WiringPi is a PIN based GPIO access library written in C for the BCM2835, BCM2836 and BCM2837 SoC devices used in all Raspberry Pi*. I don't know much about this library or it's author "Gordon". I just can say that it is released under the GNU Lesser Public License version 3, and that Gordon seems to make some good looking bread.

# Webliography ressources

Pi4jv2 : 
 * <https://v2.pi4j.com>

C++ Singleton : 
* <https://stackoverflow.com/questions/1008019/c-singleton-design-pattern>

Raspberry pins description : 
 * <https://www.raspberrypi.org/documentation/usage/gpio/>
 * <https://pinout.xyz/#>

Markdown Cheatsheet :
* <https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet>

HC-SR04 Ultrasonic sensor : 
 * <https://thepihut.com/blogs/raspberry-pi-tutorials/hc-sr04-ultrasonic-range-sensor-on-the-raspberry-pi>


