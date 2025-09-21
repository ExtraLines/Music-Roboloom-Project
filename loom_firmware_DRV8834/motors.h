#define UNDEFINED 2
#define UP 1
#define DOWN 0
#define DISABLE 1
#define ENABLE 0

struct motorObj {
  int motorPos;
  bool motorMoving;
};

/* MOTOR VARIABLES */
const int numMotors = 40;

const int motorInds[numMotors] = {0, 10, 20, 30, 1, 11, 21, 31, 2, 12, 22, 32, 3, 13, 23, 33, 4, 14, 24, 34, 
                                  5, 15, 25, 35, 6, 16, 26, 36, 7, 17, 27, 37, 8, 18, 28, 38, 9, 19, 29, 39};

int motorEnable[numMotors] = {DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE,
                              DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE,
                              DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE,
                              DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE};
int motorDir[numMotors] = {UP, UP, UP, UP, UP, UP, UP, UP, UP, UP,
                           UP, UP, UP, UP, UP, UP, UP, UP, UP, UP,
                           UP, UP, UP, UP, UP, UP, UP, UP, UP, UP,
                           UP, UP, UP, UP, UP, UP, UP, UP, UP, UP};

motorObj motor1 = {UNDEFINED, false};
motorObj motor2 = {UNDEFINED, false};
motorObj motor3 = {UNDEFINED, false};
motorObj motor4 = {UNDEFINED, false};
motorObj motor5 = {UNDEFINED, false};
motorObj motor6 = {UNDEFINED, false};
motorObj motor7 = {UNDEFINED, false};
motorObj motor8 = {UNDEFINED, false};
motorObj motor9 = {UNDEFINED, false};
motorObj motor10 = {UNDEFINED, false};
motorObj motor11 = {UNDEFINED, false};
motorObj motor12 = {UNDEFINED, false};
motorObj motor13 = {UNDEFINED, false};
motorObj motor14 = {UNDEFINED, false};
motorObj motor15 = {UNDEFINED, false};
motorObj motor16 = {UNDEFINED, false};
motorObj motor17 = {UNDEFINED, false};
motorObj motor18 = {UNDEFINED, false};
motorObj motor19 = {UNDEFINED, false};
motorObj motor20 = {UNDEFINED, false};
motorObj motor21 = {UNDEFINED, false};
motorObj motor22 = {UNDEFINED, false};
motorObj motor23 = {UNDEFINED, false};
motorObj motor24 = {UNDEFINED, false};
motorObj motor25 = {UNDEFINED, false};
motorObj motor26 = {UNDEFINED, false};
motorObj motor27 = {UNDEFINED, false};
motorObj motor28 = {UNDEFINED, false};
motorObj motor29 = {UNDEFINED, false};
motorObj motor30 = {UNDEFINED, false};
motorObj motor31 = {UNDEFINED, false};
motorObj motor32 = {UNDEFINED, false};
motorObj motor33 = {UNDEFINED, false};
motorObj motor34 = {UNDEFINED, false};
motorObj motor35 = {UNDEFINED, false};
motorObj motor36 = {UNDEFINED, false};
motorObj motor37 = {UNDEFINED, false};
motorObj motor38 = {UNDEFINED, false};
motorObj motor39 = {UNDEFINED, false};
motorObj motor40 = {UNDEFINED, false};

motorObj motors[numMotors] = {motor1, 
                       motor2, 
                       motor3, 
                       motor4, 
                       motor5, 
                       motor6, 
                       motor7, 
                       motor8, 
                       motor9, 
                       motor10,
                       motor11, 
                       motor12, 
                       motor13, 
                       motor14, 
                       motor15, 
                       motor16, 
                       motor17, 
                       motor18, 
                       motor19, 
                       motor20, 
                       motor21, 
                       motor22, 
                       motor23, 
                       motor24, 
                       motor25, 
                       motor26, 
                       motor27, 
                       motor28, 
                       motor29, 
                       motor30, 
                       motor31, 
                       motor32, 
                       motor33, 
                       motor34, 
                       motor35, 
                       motor36, 
                       motor37, 
                       motor38, 
                       motor39, 
                       motor40};
