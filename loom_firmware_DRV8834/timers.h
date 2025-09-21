#include <timeObj.h>

int full_length = 3200;
int cal_length = 200;

timeObj resetTimer(full_length, false);

timeObj move1(full_length, false);
timeObj move2(full_length, false);
timeObj move3(full_length, false);
timeObj move4(full_length, false);
timeObj move5(full_length, false);
timeObj move6(full_length, false);
timeObj move7(full_length, false);
timeObj move8(full_length, false);
timeObj move9(full_length, false);
timeObj move10(full_length, false);
timeObj move11(full_length, false);
timeObj move12(full_length, false);
timeObj move13(full_length, false);
timeObj move14(full_length, false);
timeObj move15(full_length, false);
timeObj move16(full_length, false);
timeObj move17(full_length, false);
timeObj move18(full_length, false);
timeObj move19(full_length, false);
timeObj move20(full_length, false);
timeObj move21(full_length, false);
timeObj move22(full_length, false);
timeObj move23(full_length, false);
timeObj move24(full_length, false);
timeObj move25(full_length, false);
timeObj move26(full_length, false);
timeObj move27(full_length, false);
timeObj move28(full_length, false);
timeObj move29(full_length, false);
timeObj move30(full_length, false);
timeObj move31(full_length, false);
timeObj move32(full_length, false);
timeObj move33(full_length, false);
timeObj move34(full_length, false);
timeObj move35(full_length, false);
timeObj move36(full_length, false);
timeObj move37(full_length, false);
timeObj move38(full_length, false);
timeObj move39(full_length, false);
timeObj move40(full_length, false);

timeObj cal1(cal_length, false);
timeObj cal2(cal_length, false);
timeObj cal3(cal_length, false);
timeObj cal4(cal_length, false);
timeObj cal5(cal_length, false);
timeObj cal6(cal_length, false);
timeObj cal7(cal_length, false);
timeObj cal8(cal_length, false);
timeObj cal9(cal_length, false);
timeObj cal10(cal_length, false);
timeObj cal11(cal_length, false);
timeObj cal12(cal_length, false);
timeObj cal13(cal_length, false);
timeObj cal14(cal_length, false);
timeObj cal15(cal_length, false);
timeObj cal16(cal_length, false);
timeObj cal17(cal_length, false);
timeObj cal18(cal_length, false);
timeObj cal19(cal_length, false);
timeObj cal20(cal_length, false);
timeObj cal21(cal_length, false);
timeObj cal22(cal_length, false);
timeObj cal23(cal_length, false);
timeObj cal24(cal_length, false);
timeObj cal25(cal_length, false);
timeObj cal26(cal_length, false);
timeObj cal27(cal_length, false);
timeObj cal28(cal_length, false);
timeObj cal29(cal_length, false);
timeObj cal30(cal_length, false);
timeObj cal31(cal_length, false);
timeObj cal32(cal_length, false);
timeObj cal33(cal_length, false);
timeObj cal34(cal_length, false);
timeObj cal35(cal_length, false);
timeObj cal36(cal_length, false);
timeObj cal37(cal_length, false);
timeObj cal38(cal_length, false);
timeObj cal39(cal_length, false);
timeObj cal40(cal_length, false);

timeObj frame_t1(full_length, false);
timeObj frame_t2(full_length, false);
timeObj frame_t3(full_length, false);
timeObj frame_t4(full_length, false);
timeObj frame_t5(full_length, false);
timeObj frame_t6(full_length, false);
timeObj frame_t7(full_length, false);
timeObj frame_t8(full_length, false);
timeObj frame_t9(full_length, false);
timeObj frame_t10(full_length, false);
timeObj frame_t11(full_length, false);
timeObj frame_t12(full_length, false);
timeObj frame_t13(full_length, false);
timeObj frame_t14(full_length, false);
timeObj frame_t15(full_length, false);
timeObj frame_t16(full_length, false);
timeObj frame_t17(full_length, false);
timeObj frame_t18(full_length, false);
timeObj frame_t19(full_length, false);
timeObj frame_t20(full_length, false);
timeObj frame_t21(full_length, false);
timeObj frame_t22(full_length, false);
timeObj frame_t23(full_length, false);
timeObj frame_t24(full_length, false);
timeObj frame_t25(full_length, false);
timeObj frame_t26(full_length, false);
timeObj frame_t27(full_length, false);
timeObj frame_t28(full_length, false);
timeObj frame_t29(full_length, false);
timeObj frame_t30(full_length, false);
timeObj frame_t31(full_length, false);
timeObj frame_t32(full_length, false);
timeObj frame_t33(full_length, false);
timeObj frame_t34(full_length, false);
timeObj frame_t35(full_length, false);
timeObj frame_t36(full_length, false);
timeObj frame_t37(full_length, false);
timeObj frame_t38(full_length, false);
timeObj frame_t39(full_length, false);
timeObj frame_t40(full_length, false);

timeObj moveTimers[40] = {move1, move2, move3, move4, move5, move6, move7, move8, move9, move10, 
                          move11, move12, move13, move14, move15, move16, move17, move18, move19, move20, 
                          move21, move22, move23, move24, move25, move26, move27, move28, move29, move30, 
                          move31, move32, move33, move34, move35, move36, move37, move38, move39, move40};
timeObj calTimers[40] = {cal1, cal2, cal3, cal4, cal5, cal6, cal7, cal8, cal9, cal10, 
                         cal11, cal12, cal13, cal14, cal15, cal16, cal17, cal18, cal19, cal20, 
                         cal21, cal22, cal23, cal24, cal25, cal26, cal27, cal28, cal29, cal30, 
                         cal31, cal32, cal33, cal34, cal35, cal36, cal37, cal38, cal39, cal40};
timeObj frameTimers[40] = {frame_t1, frame_t2, frame_t3, frame_t4, frame_t5, frame_t6, frame_t7, frame_t8, frame_t9, frame_t10, 
                          frame_t11, frame_t12, frame_t13, frame_t14, frame_t15, frame_t16, frame_t17, frame_t18, frame_t19, frame_t20, 
                          frame_t21, frame_t22, frame_t23, frame_t24, frame_t25, frame_t26, frame_t27, frame_t28, frame_t29, frame_t30, 
                          frame_t31, frame_t32, frame_t33, frame_t34, frame_t35, frame_t36, frame_t37, frame_t38, frame_t39, frame_t40};
