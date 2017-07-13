/*
* TTSi7006
* Version 1.0 July, 2017
* Copyright 2017 TOLDO TECHNIK
* For more details, see https://github.com/TOLDOTECHNIK/TTSi7006
*/

#ifndef TTSi7006_H
#define TTSi7006_H

#include <Wire.h>
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <Wprogram.h>
#endif

//CONSTANTS
#define TTSi7006_I2C_ADDRESS              0x40
#define TTSi7006_ID                       0x186

#define TTSi7006_REG_REL_HUM              0xE5
#define TTSi7006_REG_TEMP                 0xE3

class TTSi7006{
  public:
    TTSi7006(boolean wireBegin);

    boolean isConnected();
    float readHumidity();
    float readTemperatureC();
    float readTemperatureF();
   
  private:
    
};

#endif