/* 
 * File:   DisplayQueue.h
 * Author: hassa
 *
 * Created on April 25, 2023, 1:52 PM
 */

#ifndef DISPLAYQUEUE_H
#define	DISPLAYQUEUE_H

#include "appRes.h"
/*
 * <@macro Display Queue Default case 
 */
#define QUEUE_DEFUALT_CASE         (0)
/*
 * <@macro Display new request  
 */
#define QUEUE_NEWREQUEST_CASE      (1)
/*
 * <@macro Display new request  
 */
#define QUEUE_TIMIEOUT_CASE        (2)
/*
 * <@macro Display new request  
 */
#define QUEUE_WAIT_CASE        (3)
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
void SystemPutInQueue(uint8_t switchIp, uint8_t State);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <DisplayQueueCallBack>                                               |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void DisplayQueueCallBack                                                   |
 | < @Description         : run in background task                                                      | 
 | < @return              : void                                                                        |                   
 --------------------------------------------------------------------------------------------------------
 */
void DisplayQueueCallBack();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <DisplayQueueInit>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void DisplayQueueInit                                                       |
 | < @Description         : Init all data in this file                                                  | 
 | < @return              : void                                                                        |                   
 --------------------------------------------------------------------------------------------------------
 */
void DisplayQueueInit();
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
void updateQueueState(uint8_t State);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getQueuestate                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getQueuestate                                                          |
 | < @Description         : get state of the queue                                                      |                                                   |
 | < @return              : state of queue                                                              |                   
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getQueuestate();

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <updateWithNewRequest>                                               |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void updateWithNewRequest                                                   |
 | < @Description         : system have new Request                                                     |                                                   |
 | < @return              : void                                                            |                   
 --------------------------------------------------------------------------------------------------------
 */
void updateWithNewRequest(uint8_t swip , uint8_t State);


#endif	/* DISPLAYQUEUE_H */

