# iHaospace VL53L0X

*iHaospace VL53L0X Time-of-Flight (ToF) Laser Ranging Sensor Breakout 940nm VL53L0X V2 Laser Distance Module I2C IIC*

Constructor description  : 

 * The VL53L0X time-of-flight range-finding sensor is a new generation of laser ranging module. The VL53LOX is a fully-integrated sensor equipped with embedded infrared, human-eye safety lasers, advanced filters and ultra-fast photon detection arrays to measure longer distances, speeds and More accurate.
 * 940nm Laser VCSEL
 * Measures absolute range up to 2m
 * Power supply: 3-5V (use 2.8V)
 * Communication method: I2C IIC 3-5V  

Indeed it is a carrier/breakout board for ST’s VL53L0X laser-ranging sensor. 

I have found a PDF which contains technical specifications on <https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html>. And i've added the official ST documentation PDF in this folder.

# Description

This device is a small microchip which comes with a header. All you have to do is to solder this header on the chip and then you can start to use it. It has two "face". 

The front face has a single visible component, 6 holes and some text. The name of the chip at the top *CJVL53L0XV2*. Under this name there is a black rectangular component. This tiny component seems to have two small holes. It is the dectector itself and is representated in first page of PDF, it is the concrete *VL53L0X*. The chip is only a "wrapper" for the detector. Finally under this component are the 6 holes in which you put the header to solder it. The holes are named as following (from left to right) : 

 * VCC
 * GND
 * SCL
 * SDA
 * GPIO1
 * XSHUT

The other face has 9 tiny components on it. There are somes scriptures : *C2*, *C3*, *U2*, *R3*, *R2*, *C4*. 

I have found some interesting description on <https://www.pololu.com/product/2490>

# I2C Prerequisites

The I2C bus interface must be activated. It can be done through 

```sh
sudo raspi-config
```

Look for "I2C" in "Interfacing Options"

Then use i2cdetect to check that the adress is 29 :

```sh
i2cdetect -y 1
```


