
#include "../inc/appRes.h"

/*
 * <@var Display Queue Index
 */
static uint8_t gu8DisplayQueue[MAX_DEVICE_USED];
/*
 * Index of the current switch ip
 */
static uint8_t gu8QueueIndex;
/*
 * Display Queue State
 */
static uint8_t gu8DataQueueState;
/*
 * Display Queue State
 */
static uint8_t gu8DataLastState;
/*
 * Display scoller time
 */
static stTimer_TimeOut_t gsRoomScollerTimeOut;

/*
 * new Request switch ip
 */
static uint8_t gu8NewRequestIndex;
/*
 * Save State
 */
static uint8_t gu8SaveState;
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemGetLargestStateIndex>     +                                    |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void SystemGetLargestStateIndex                                             |
 | < @Description         : get Laragest state from queue                                               | 
 | < @Param switchIp      : Switch ip 0 to 126                                                                  |
 | < @return              : void                                                                        |                   
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t SystemGetLargestStateIndex(uint8_t switchIp);

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemPutInQueue>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void SystemPutInQueue                                                       |
 | < @Description         : put data Into Queue                                                         | 
 | < @Param switchIp      : Switch ip                                                                   |
 | < @Param state          : switch state                                                | 
 | < @return              : void                                                                        |                   
 --------------------------------------------------------------------------------------------------------
 */
void SystemPutInQueue(uint8_t switchIp, uint8_t State) {
    gu8DisplayQueue[switchIp - 1] = State;
    

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemIcrementQueueIndex>                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void SystemIcrementQueueIndex                                               |
 | < @Description         : get Next Switch ip                                                          | 
 | < @return              : void                                                                        |                   
 --------------------------------------------------------------------------------------------------------
 */
void SystemIcrementQueueIndex() {
    gu8QueueIndex++;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemGetLargestStateIndex>     +                                    |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void SystemGetLargestStateIndex                                             |
 | < @Description         : get Laragest state from queue                                               | 
 | < @Param switchIp      : Switch ip 0 to 126                                                                  |
 | < @return              : void                                                                        |                   
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t SystemGetLargestStateIndex(uint8_t switchIp) {
    /*check of EMG*/
    for (uint8_t i = switchIp; i < MAX_DEVICE_USED; i++) {
        if (gu8DisplayQueue[i] == SYSTEM_EMG_EVENT) {
            return (i);
        }
    }
    for (uint8_t i = 0; i < switchIp; i++) {
        if (gu8DisplayQueue[i] == SYSTEM_EMG_EVENT) {
            return (i);
        }
    }

    for (uint8_t i = switchIp; i < 127; i++) {
        if ((gu8DisplayQueue[i] == SYSTEM_CALL_EVENT) || (gu8DisplayQueue[i] == SYSTEM_ASSISSET_EVENT)) {
            return (i);
        }
    }

    for (uint8_t i = 0; i < switchIp; i++) {
        if ((gu8DisplayQueue[i] == SYSTEM_CALL_EVENT) || (gu8DisplayQueue[i] == SYSTEM_ASSISSET_EVENT)) {
            return (i);
        }
    }

    return (128);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <DisplayQueueCallBack>                                               |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void DisplayQueueCallBack                                                   |
 | < @Description         : run in background task                                                      | 
 | < @return              : void                                                                        |                   
 --------------------------------------------------------------------------------------------------------
 */
void DisplayQueueCallBack() {
    if (!SystemIsSerial()) {
        return;
    }

    switch (gu8DataQueueState) {
        case QUEUE_DEFUALT_CASE:
            gu8QueueIndex = SystemGetLargestStateIndex(gu8QueueIndex);
            if (gu8QueueIndex == 128) {
                gu8QueueIndex = 0;
                /*update display user action*/
                RegisterOnUserSystem(SYSTEM_CANCEL_EVENT);
            } else {
                gu8DataQueueState = QUEUE_TIMIEOUT_CASE;
                sysSetPeriodMS(&gsRoomScollerTimeOut, SystemScollerTime());
                RegisterOnUserSystem(gu8DisplayQueue[gu8QueueIndex]);
            }
            break;

        case QUEUE_NEWREQUEST_CASE:
            if ((gu8SaveState == SYSTEM_CANCEL_EVENT)) {
                gu8DataQueueState = gu8DataLastState;
            } else {
                sysSetPeriodMS(&gsRoomScollerTimeOut, SystemScollerTime());
                RegisterOnUserSystem(gu8SaveState);
                gu8QueueIndex = gu8NewRequestIndex;
                gu8DataQueueState = QUEUE_TIMIEOUT_CASE;
            }
            break;
        case QUEUE_TIMIEOUT_CASE:
            if (sysIsTimeoutMs(&gsRoomScollerTimeOut) == 0) {
                gu8QueueIndex++;
                gu8DataQueueState = QUEUE_DEFUALT_CASE;
            }
            break;
        case QUEUE_WAIT_CASE:
            break;
        default:
            gu8QueueIndex = 0;
            gu8SaveState = SYSTEM_CANCEL_EVENT;
            gu8DataLastState = QUEUE_DEFUALT_CASE;
            gu8DataQueueState = QUEUE_DEFUALT_CASE;
            gu8NewRequestIndex = 0;
            break;
    }

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <DisplayQueueInit>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void DisplayQueueInit                                                       |
 | < @Description         : Init all data in this file                                                  | 
 | < @return              : void                                                                        |                   
 --------------------------------------------------------------------------------------------------------
 */
void DisplayQueueInit() {
    gu8QueueIndex = 0;
    setBuff(gu8DisplayQueue, SYSTEM_CANCEL_EVENT, MAX_DEVICE_USED);
    gu8DataQueueState = 0;
    gu8DataLastState = 0;
    gu8SaveState = 0;
    gu8NewRequestIndex = 0;

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <DateQueueupdateState                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void DateQueueupdateState                                                   |
 | < @Description         : update state of the queue                                                   | 
 | < @Param State         : Queue state in the system                                                   |
 | < @return              : void                                                                        |                   
 --------------------------------------------------------------------------------------------------------
 */
void updateQueueState(uint8_t State) {
    gu8DataQueueState = State;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getQueuestate                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getQueuestate                                                          |
 | < @Description         : get state of the queue                                                      |                                                   |
 | < @return              : state of queue                                                              |                   
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getQueuestate() {
    return gu8DataQueueState;

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <updateWithNewRequest>                                               |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void updateWithNewRequest                                                   |
 | < @Description         : system have new Request                                                     |                                                   |
 | < @return              : void                                                            |                   
 --------------------------------------------------------------------------------------------------------
 */
void updateWithNewRequest(uint8_t swip, uint8_t State) {
    gu8DataLastState = gu8DataQueueState;
    gu8NewRequestIndex = swip - 1;
    gu8SaveState = State;
    updateQueueState(QUEUE_NEWREQUEST_CASE);
}

