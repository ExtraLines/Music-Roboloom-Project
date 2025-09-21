//Modes
#define MOVE_ROW  1
#define CALIBRATE 2

//Cal Modes
#define CAL_MOVE_SMALL 1
#define CAL_SET_MOTOR  2
#define CAL_SET_ALL    3

char buffer[100];
int len;

void check_serial() {
    int  mode       = 0;
    int  cal_mode   = 0;
    int  dir        = 0;
    int  motor      = 0;
    char bitmap[40] = "";

    if (Serial.available() > 0) {
      // read all incoming data:
      len = Serial.readBytesUntil('\n', buffer, 100);
    
      if (debugPrint) {
        Serial.print("I received w/ len: ");
        Serial.println(len);
        /*
        * Print Buffer
        for(int i = 0; i < len; i++) {
          Serial.println(buffer[i]);
        }
        */
      }

      //Assemble Commands
      mode = int(buffer[0] - '0');
      
      switch(mode) {
        case MOVE_ROW:
          strcpy(bitmap, buffer+1);
          if(debugPrint) {
            Serial.print("bitmap = ");
            Serial.println(bitmap);
          }

          move_row(bitmap, len-1);
          break;
        case CALIBRATE:
          cal_mode  = int(buffer[1]-'0');
          dir       = int(buffer[2]-'0');
          
          if(debugPrint) {
            Serial.println("Cal Mode & Dir");
            Serial.println(cal_mode);
            Serial.println(dir);
          }

          switch(cal_mode) {
            case CAL_MOVE_SMALL:
              motor = convertMotorNumber(buffer[3], buffer[4]);
              move_motor_cal(motor, dir);
              break;
            case CAL_SET_MOTOR:
              motor = convertMotorNumber(buffer[3], buffer[4]);
              set_motor_pos(motor, dir);
              break;
            case CAL_SET_ALL:
              set_motor_pos_all(dir);
              break;
          }
          break;
      }
      Serial.flush();
    }
}

int convertMotorNumber(char digit0, char digit1) {
  int  motor;
  char temp[10]= ""; 
  strncat(temp, &digit0, sizeof(digit0));
  strncat(temp, &digit1, sizeof(digit1));
  
  if(debugPrint) {
    Serial.print("Old Motor is: ");
    Serial.println(temp);
  }
  
  motor = atoi(temp);
  motor = remapMotorIndex(motor);
  
  if (debugPrint) {
    Serial.print("New motor is: ");
    Serial.println(motor);
  }
  return motor;
}