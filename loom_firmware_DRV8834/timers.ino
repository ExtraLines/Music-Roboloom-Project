void check_timers () {
  for (int i=0; i < numMotors; i++) {
    // check if calibrate timer has gone off or move timer has gone off
    if (calTimers[i].ding()) {
      // turn motor off
      motor_off(i);
      calTimers[i].reset();
    }
    if (moveTimers[i].ding()) {
      // turn all motors in frame off
      motor_off(i);
      moveTimers[i].reset();
    }
  }
}
