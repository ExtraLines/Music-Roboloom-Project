int remapMotorIndex(int oldMotor){
  int motorIndex = 10*(3-oldMotor%4) + floor(oldMotor/4);
  return motorIndex;
}

void motor_off(int motor) {
  if (debugPrint) {
    Serial.println("Motor Off");
  }
  
  //change the motor in the enable variable
  motorEnable[motor] = DISABLE;
  // set motor moving false 
  motors[motor].motorMoving = false;
  
  //Write all the enables
  write_enable();
}

void set_motor_pos(int motor, int dir) {
  motors[motor].motorPos = dir;
  motors[motor].motorMoving = false;
  if (debugPrint) {
    Serial.print("Setting direction for calibration: ");
    Serial.println(motors[motor].motorPos);
  }
}

void set_motor_pos_all(int dir) {
  for(int i = 0; i < numMotors; i++) {
    motors[i].motorPos = dir;
    motors[i].motorMoving = false;
    if (debugPrint) {
      Serial.print("Setting down for calibration: ");
      Serial.println(motors[i].motorPos);
    }
  }
}

void move_motor_cal(int motor, int dir) {
  // Start the motor in question moving on it's calibration timer  
  if (debugPrint) {
    Serial.println("Motor Calibrate");
  }
  
  // if the motor is not moving
  if (!motors[motor].motorMoving){
    // Set the correct direction and write it
    motorDir[motor] = dir;
    write_dir();
    // start calibrate timer
    calTimers[motor].start();
    // set moving to true
    motors[motor].motorMoving = true;
    // Set the enable pin
    motorEnable[motor] = ENABLE;
    write_enable();
  }
}

void move_motor(int motor, int dir) {
  // Start the motor in question moving on it's move timer
  if (debugPrint) {
    Serial.println("Motor Move");
    Serial.println(motors[motor].motorMoving);
    Serial.println(motors[motor].motorPos);
  }
  // if motor position is not undefined and not the direction you're trying to go and the motor is not moving
  if (motors[motor].motorPos != UNDEFINED && !motors[motor].motorMoving && motors[motor].motorPos != dir){
    // Set the correct direction and write it
    motorDir[motor] = dir;
    write_dir();
    // set moving to true
    motors[motor].motorMoving = true;
    // turn motor on
    motorEnable[motor] = ENABLE;
    write_enable();
    //set motor position to dir
    motors[motor].motorPos = dir;
    // start move timer
    moveTimers[motor].start();
  }
}

void move_row(char *bitmap, int len) {  
  int dir, motorIndex;
  for(int i = 0; i<len; i++) {
    dir = bitmap[i]-'0';
    motorIndex = remapMotorIndex(i);

    if (motors[motorIndex].motorPos == UNDEFINED || motors[motorIndex].motorMoving || motors[motorIndex].motorPos == dir){
      if (debugPrint) {
        Serial.print("Mapped i of = ");
        Serial.println(i);
        Serial.print("Mapped to motorIndex = ");
        Serial.println(motorIndex);
        Serial.println("Error Handler: Move Motor Cmd Denied | Motor is already active, or in desired position.");
        Serial.println(motors[motorIndex].motorMoving);
        Serial.println(motors[motorIndex].motorPos);
      }
      continue;
    }
    
    if (debugPrint) {
      Serial.println("Debug Handler: Move Motor Cmd Approved");
    }
    motorDir[motorIndex]           = dir;
    motors[motorIndex].motorPos    = dir;
    motors[motorIndex].motorMoving = true;
    motorEnable[motorIndex]        = ENABLE;
    moveTimers[motorIndex].start();
  }

  write_dir();
  write_enable();
}

// This function is to correct the direction pins being flipped across their cables
int trans_dir_pos(int dir) {
  return (9-dir%10)+10*int(dir/10);
}

void move_all_down(){
  for (int i=0; i<numMotors; i++){
    motor_off(i);
    moveTimers[i].reset();
    move_motor(i, DOWN);
  }
}
