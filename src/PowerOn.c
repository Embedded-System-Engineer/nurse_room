#include "../inc/appRes.h"
/*
 <@var Power on state 
 */
static uint8_t gu8PowerOnStateConfig;
/*
 <@var Power on state 
 */
static uint8_t gu8PowerOnData;
/*
 *<@var Power on Time out to send Frame 
 */
static stTimer_TimeOut_t gstPowerOnTimeOutConfig;
/*
 *<@var Power on Time out to send Frame 
 */
static stTimer_TimeOut_t gstPowerOnTimeOutData;
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBackData>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void PowerOnCallBackData();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBackData>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void PowerOnCallBackConfig();

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnInit>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnInit                                                            |
 | < @Description         : Init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PowerOnInit() {
    gu8PowerOnData = 3;
    gu8PowerOnStateConfig = 0;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBack>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PowerOnCallBack() {

    if (!SystemIsSerial()) {
        gu8PowerOnData = 0;
        gu8PowerOnStateConfig = 0;
        return;
    }

    if (!SystemIp()) {
        gu8PowerOnData = 0;
        gu8PowerOnStateConfig = 0;
        return;
    }

    if (csmaGetStationAddress() == 0) {
        gu8PowerOnData = 0;
        gu8PowerOnStateConfig = 0;
        return;
    }

    PowerOnCallBackConfig();
    PowerOnCallBackData();

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PoweronRestart>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PoweronRestart                                                        |
 | < @Description         : Power on Restart after change Ip                                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PoweronRestart() {
    gu8PowerOnData = 0;
    gu8PowerOnStateConfig = 0;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBackData>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void PowerOnCallBackData() {

    switch (gu8PowerOnData) {
        case 0:
            sysSetPeriodMS(&gstPowerOnTimeOutData, 1000);
            gu8PowerOnData = 1;
            break;
        case 1:
            if (sysIsTimeoutMs(&gstPowerOnTimeOutData) == 0) {
                gu8PowerOnData = 2;
            }
            break;
        case 2:
            if (PowerOnRequest()) {
                gu8PowerOnData = 0;
            }
            break;
        case 3:/*stop case*/
            break;
        default:
            gu8PowerOnData = 0;
            break;
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBackData>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void PowerOnCallBackConfig() {

    switch (gu8PowerOnStateConfig) {
        case 0:
            if (RoomGetConfigReq()) {
                sysSetPeriodMS(&gstPowerOnTimeOutConfig, 200);
                gu8PowerOnStateConfig = 1;
            }
            break;
        case 1:
            if (sysIsTimeoutMs(&gstPowerOnTimeOutConfig) == 0) {
                gu8PowerOnStateConfig = 0;
            }
            break;
        case 2:/*stop case*/
            break;
        default:
            gu8PowerOnStateConfig = 0;
            break;
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <stopPowerOnDisplayData>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void stopPowerOnDisplayData                                                        |
 | < @Description         : stop Request Data from display                                                             |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void stopPowerOnRoomData() {
    gu8PowerOnData = 3;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <stopPowerOnDisplayConfig>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void stopPowerOnDisplayConfig                                                        |
 | < @Description         : stop Request config from display                                                             |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void stopPowerOnRoomConfig() {
    gu8PowerOnStateConfig = 2;
}