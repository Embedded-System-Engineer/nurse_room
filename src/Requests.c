#include "../inc/appRes.h"

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Functions Implements>                                    |
 --------------------------------------------------------------------------------------------------------
 */


/*
 --------------------------------------------------------------------------------------------------------
 |                                 < DisplayGetConfigReq >                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void DisplayGetConfigReq                                                           |
 | < @Description       : Request Config State                                                 |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t RoomGetConfigReq() {
    uint8_t buf[2];
    uint8_t FrameState;
    buf[0] = ROOM_POWER_ON_REQ;
    buf[1] = SystemIp();
    FrameState = putDataCh0(buf, 2, 0, RequestFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        return (1);
    }
    return (0);

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < PowerOnRequest >                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void PowerOnRequest                                                           |
 | < @Description       : request data from save unit                                                   |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t PowerOnRequest() {
    uint8_t buf[2];
    uint8_t FrameState;
    buf[0] = SW_POWERON_ROOM_REQ;
    buf[1] = SystemIp();
    FrameState = putDataCh0(buf, 2, 0xFF, RequestFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < GetIpRequest >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void GetIpRequest                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t GetIpRequest() {
    uint8_t FrameState;
    uint8_t buf[2];
    buf[0] = SET_IP_RES;
    buf[1] = SystemIp();
    FrameState = putDataCh0(buf, 2, 0, ResponseFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < ResForConfig >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void ResForConfig                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t ResForConfig() {
    uint8_t FrameState;
    uint8_t buf[2];
    buf[0] = ROOM_CONFIG_RES;
    buf[1] = SystemIp();
    FrameState = putDataCh0(buf, 2, 0, ResponseFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        return (1);
    }
    return (0);
}