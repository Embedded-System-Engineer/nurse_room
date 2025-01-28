
#include "../inc/appRes.h"
static uint8_t gu8NetworkDisplayReq;
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkClientSystem>                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkClientSystem                                                    |
 | < @Description         : any Response can be handel from this function                               |   
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkClientSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkHostSystem>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkHostSystem                                                      |
 | < @Description         : any request can be handel from this function                                |
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkHostSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data);

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkInit>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkInit                                                            |
 | < @Description         : Init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkInit() {
    OnClientFrameCh0(NetworkClientSystem);
    OnHostFrameCh0(NetworkHostSystem);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkClientSystem>                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkClientSystem                                                    |
 | < @Description         : any Response can be handel from this function                               |   
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkClientSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data) {


    if (!SystemIsSerial()) {
        return (1);
    }


    if (Data[0] == ROOM_POWER_ON_RES) {
        if (Data[1] == SystemIp()) {
            sendFreeFrame();
            OnSaveConfiguration(Data + 2);
            stopPowerOnRoomConfig();
        }
        return (1);
    }



    if (Data[0] == SW_UPDATE_DISPLAY_RES) {
        /*update  call Point with Increment Index Reset Time To time Target*/
        /**/
        if (SystemIp() != Data[2]) {
            return (1);
        }
        stopPowerOnRoomData();
        SystemPutInQueue(Data[1], Data[3]);
        return (1);
    }
    return (1);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkHostSystem>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkHostSystem                                                      |
 | < @Description         : any request can be handel from this function                                |
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkHostSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data) {

    if (!SystemIsSerial())
        return (1);



    if (Data[0] == SW_START_CONFIG_REQ && SA == csmaGetMaxAddress()) {
        if (Data[1] == 0) {
            gu8NetworkDisplayReq = 1;
            RegisterOnUserSystem(SYSTEM_START_ADDRESS_EVENT);
            updateQueueState(QUEUE_WAIT_CASE);
        } else {
            updateQueueState(QUEUE_DEFUALT_CASE);
        }
        return (1);
    }


    if (Data[0] == SET_IP_REQ && SA == csmaGetMaxAddress()) {
        if (Data[1] != SystemIp()) {
            OnSaveIp(Data[1]);
            PoweronRestart();
        }
        updateQueueState(QUEUE_DEFUALT_CASE);
        return (1);
    }


    if (Data[0] == ROOM_CONFIG_REQ) {
        if (Data[1] == SystemIp()) {
            stopPowerOnRoomConfig();
            gu8NetworkDisplayReq = 2;
            OnSaveConfiguration((uint8_t *) (Data + 2));
        }
        return (1);
    }



    if (Data[0] == SW_UPDATE_ROOM_REQ  && Data[2] == SystemIp()) {
        SystemPutInQueue(Data[1], Data[3]);
        UserSetAcceptValueRunif(Data[3]);
        updateQueueState(QUEUE_NEWREQUEST_CASE);
        return (1);
    }


    return (1);
}




/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkRoomCallBack>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t NetworkRoomCallBack                                                      |
 | < @Description         : find my ip in this list of ips                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkRoomCallBack() {
    switch (gu8NetworkDisplayReq) {
        case 0:
            break;
        case 1:
            if (GetIpRequest()) {
                gu8NetworkDisplayReq = 0;
            }
            break;
        case 2:
            if (ResForConfig()) {
                gu8NetworkDisplayReq = 0;
            }
            break;
        default:
            gu8NetworkDisplayReq = 0;
            break;
    }
}