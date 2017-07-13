# Si7006 Arduino Library

The Si7006 I2C Humidity and Temperature Sensor is a monolithic CMOS IC integrating humidity and temperature sensor elements, an analog-to-digital converter, signal processing, calibration data, and an I2C Interface. See <a href="Documents/Si7006 Sensor Datasheet.pdf">datasheet</a> for more detail.

<img src="Documents/Si7006.png" width="250" />

Library feature list:

 * Easy Si7006 interfacing
 * Relative humidity measurement
 * Temperature measurement in °C and °F
 * Not implemented: Reset, Reading Device ID and FW version, Heating

Note: This implementation uses the "Hold Master Mode" approach. This means the sensor holds the I2C clock line low (I2C clock stretching) until a measurement is done.

## History
2017-07-13 Initial release

## Installation
Download the ZIP file and extract its content. Move the TTSi7006 folder to "ARDUINOAPP/hardware/libraries/". In the Arduino IDE you'll find the sample sketches under Samples->TTSi7006.

## Wiring
If you are using an Arduino board other than 3.3V, ensure to use a logic level shifter!

## Usage
### Create object TTSi7006(wireBegin)

#### Parameters
wireBegin: true does a Wire.begin() for you. If false you have to Wire.begin() before doing some sensor readings.

#### Example
```cpp
TTSi7006 si7006 = TTSi7006(true);
```

### isConnected()
Returns true if IC is connected correctly and detected by the I2C master.

#### Parameters
none

#### Returns
boolean true/false

#### Example
```cpp
if(si7006.isConnected()){
  Serial.println("Si7006 IC is connected and running.");
}
```


### readHumidity()
Returns the relative humidity in % as a float data type.

#### Parameters
none

#### Returns
float: relative humidity in %

#### Example
```cpp
float h = si7006.readHumidity();
```


### readTemperatureC()
Returns the current temperature in °C as a float data type.

#### Parameters
none

#### Returns
float: temperature in °C

#### Example
```cpp
float tc = si7006.readTemperatureC();
```


### readTemperatureF()
Returns the current temperature in °F as a float data type.

#### Parameters
none

#### Returns
float: temperature in °F

#### Example
```cpp
float tc = si7006.readTemperatureF();
```