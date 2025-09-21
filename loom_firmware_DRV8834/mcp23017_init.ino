#include "Wire.h"

#define GPIOA_REG 0x00
#define GPIOB_REG 0x01
#define GPIOA 0x12
#define GPIOB 0x13
#define addr1 0x20
#define addr2 0x21
#define addr3 0x22
#define addr4 0x23
#define addr5 0x24
#define OUT 0x00

void set_reg_output(int addr, int reg)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.write(OUT);
  Wire.endTransmission();  
}

void init_mcp23017() {
  Wire.begin(); // wake up I2C bus
  // set I/O pins to outputs
  set_reg_output(addr1, GPIOA_REG);
  set_reg_output(addr1, GPIOB_REG);
  set_reg_output(addr2, GPIOA_REG);
  set_reg_output(addr2, GPIOB_REG);
  set_reg_output(addr3, GPIOA_REG);
  set_reg_output(addr3, GPIOB_REG);
  set_reg_output(addr4, GPIOA_REG);
  set_reg_output(addr4, GPIOB_REG);
  set_reg_output(addr5, GPIOA_REG);
  set_reg_output(addr5, GPIOB_REG);
}

void write_byte(int addr, int gpio, int info)
{
   Wire.beginTransmission(addr);
   Wire.write(gpio);
   Wire.write(info);
   Wire.endTransmission();
}

void write_dir() {
  byte gpioB3 = motorDir[0] | motorDir[1]<<1 | motorDir[2]<<2 | motorDir[3]<<3 | motorDir[4]<<4 | motorDir[5]<<5 | motorDir[6]<<6 | motorDir[7]<<7;
  byte gpioA4 = motorDir[8] | motorDir[9]<<1 | motorDir[10]<<2 | motorDir[11]<<3 | motorDir[12]<<4 | motorDir[13]<<5 | motorDir[14]<<6 | motorDir[15]<<7;
  byte gpioB4 = motorDir[16] | motorDir[17]<<1 | motorDir[18]<<2 | motorDir[19]<<3 | motorDir[20]<<4 | motorDir[21]<<5 | motorDir[22]<<6 | motorDir[23]<<7;
  byte gpioA5 = motorDir[24] | motorDir[25]<<1 | motorDir[26]<<2 | motorDir[27]<<3 | motorDir[28]<<4 | motorDir[29]<<5 | motorDir[30]<<6 | motorDir[31]<<7;
  byte gpioB5 = motorDir[32] | motorDir[33]<<1 | motorDir[34]<<2 | motorDir[35]<<3 | motorDir[36]<<4 | motorDir[37]<<5 | motorDir[38]<<6 | motorDir[39]<<7;

  Serial.println(gpioB3);

  write_byte(addr3, GPIOB, gpioB3);
  write_byte(addr4, GPIOA, gpioA4);
  write_byte(addr4, GPIOB, gpioB4);
  write_byte(addr5, GPIOA, gpioA5);
  write_byte(addr5, GPIOB, gpioB5);
}

void write_enable() {
  byte gpioA1 = motorEnable[0] | motorEnable[1]<<1 | motorEnable[2]<<2 | motorEnable[3]<<3 | motorEnable[4]<<4 | motorEnable[5]<<5 | motorEnable[6]<<6 | motorEnable[7]<<7;
  byte gpioB1 = motorEnable[8] | motorEnable[9]<<1 | motorEnable[10]<<2 | motorEnable[11]<<3 | motorEnable[12]<<4 | motorEnable[13]<<5 | motorEnable[14]<<6 | motorEnable[15]<<7;
  byte gpioA2 = motorEnable[16] | motorEnable[17]<<1 | motorEnable[18]<<2 | motorEnable[19]<<3 | motorEnable[20]<<4 | motorEnable[21]<<5 | motorEnable[22]<<6 | motorEnable[23]<<7;
  byte gpioB2 = motorEnable[24] | motorEnable[25]<<1 | motorEnable[26]<<2 | motorEnable[27]<<3 | motorEnable[28]<<4 | motorEnable[29]<<5 | motorEnable[30]<<6 | motorEnable[31]<<7;
  byte gpioA3 = motorEnable[32] | motorEnable[33]<<1 | motorEnable[34]<<2 | motorEnable[35]<<3 | motorEnable[36]<<4 | motorEnable[37]<<5 | motorEnable[38]<<6 | motorEnable[39]<<7;

  write_byte(addr1, GPIOA, gpioA1);
  write_byte(addr1, GPIOB, gpioB1);
  write_byte(addr2, GPIOA, gpioA2);
  write_byte(addr2, GPIOB, gpioB2);
  write_byte(addr3, GPIOA, gpioA3);
}
