/*
* TTSi7006
* Version 1.0 July, 2017
* Copyright 2017 TOLDO TECHNIK
* For more details, see https://github.com/TOLDOTECHNIK/TTSi7006
*/

#include "TTSi7006.h"

TTSi7006::TTSi7006(boolean wireBegin){
  if(wireBegin){
    Wire.begin();
  }
}

boolean TTSi7006::isConnected(){
  Wire.beginTransmission(TTSi7006_I2C_ADDRESS);
  return !Wire.endTransmission();
}

float TTSi7006::readHumidity(){
  float humidity = 0;
  uint8_t retries = 0;

  Wire.beginTransmission(TTSi7006_I2C_ADDRESS);
  Wire.write(TTSi7006_REG_REL_HUM);
  Wire.endTransmission();
  Wire.requestFrom(TTSi7006_I2C_ADDRESS, (byte)2);
  while(!Wire.available() && retries < 255) {
    retries ++;
    delay(1);
  }
  if(Wire.available() > 1){
    humidity = Wire.read() * 256.0 + Wire.read();
    humidity = ((125 * humidity) / 65536.0) - 6;
  }
  Serial.println(humidity);
  return humidity;
}

float TTSi7006::readTemperatureC(){
  float temperature = 0;
  uint8_t retries = 0;

  Wire.beginTransmission(TTSi7006_I2C_ADDRESS);
  Wire.write(TTSi7006_REG_TEMP);
  Wire.endTransmission();
  Wire.requestFrom(TTSi7006_I2C_ADDRESS, (byte)2);
  while(!Wire.available() && retries < 255) {
    retries ++;
    delay(1);
  }
  if(Wire.available() > 1){
    temperature = Wire.read() * 256.0 + Wire.read();
    temperature = ((175.72 * temperature) / 65536.0) - 46.85;
  }

  return temperature;
}

float TTSi7006::readTemperatureF(){
  return readTemperatureC() * 1.8 + 32;
}
