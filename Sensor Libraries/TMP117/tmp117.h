#ifndef TMP117_H
#define TMP117_H

#include <Arduino.h>
#include "GLEE_Sensor.h"


#define TMP117_RESOLUTION (double)0.0078125

enum TMP117_Register
{
  TMP117_TEMP_REG = 0X00,
  TMP117_CONFIG_REG = 0x01,
  TMP117_HIGH_LIMIT_REG = 0X02,
  TMP117_LOW_LIMIT_REG = 0X03,
  TMP117_EEPROM_UL_REG = 0X04,
  TMP117_EEPROM1_REG  = 0X05,
  TMP117_EEPROM2_REG  = 0X06,
  TMP117_TEMP_OFFSET_REG = 0X07,
  TMP117_EEPROM3_REG = 0X08,
  TMP117_DEVICE_ID = 0X0F
};



class TMP117 : public Sensor
{
    public:
        TMP117();
        uint8_t getAddress();

        double getTemperatureC();
        double getTemperatureF();

        float getUncertainty(float inputTemperature);

        void setLowLimit(float lowLimit);
        float getLowLimit();
        void setHighLimit(float highLimit);
        float getHighLimit();
        bool getHighAlert();
      	bool getLowAlert();

        void reset();

        bool dataReady();
        uint16_t read2Byte(uint8_t registerAddress);
  };
  #endif
