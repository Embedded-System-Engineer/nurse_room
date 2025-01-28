/*
---------------------------------------------------------------------------------------------------------
|                           < Module  Definition >                                                      | 
---------------------------------------------------------------------------------------------------------
| < FILE                     : app.h                                                                    |                                  
| < Author                   : Hassan Elsaied                                                           |
| < Version                  : Mega2v241022                                                             |
| < Refences                 : no- ref                                                                  |  
| < SRAM USAGE               : 22-Byte                                                                  |
| < PROGRAM USAGE            : 388 Byte  (0 Instruction)                                                |                                    
| < Hardware Usage           : External eeprom Modeule                                                  |
| < File Created             : 24-10-2022                                                               |
---------------------------------------------------------------------------------------------------------
 */



#include "../inc/appRes.h"

/*Register som Function */

void appBoot(void) {

}

void appInit(void) {
    UserInit();
    NetworkInit();
    DisplayQueueInit();
    PowerOnInit();
    UserInit2();
    ConfigurationInit();
}

void appSync(void) {

}

void appMain(void) {

    EEpromCallback();
   // PowerOnCallBack();
    if (RoomGetType()) {
        UserCallBack2();
    } else {
        UserCallBack();
    }
    NetworkRoomCallBack();
    DisplayQueueCallBack();
    
}



