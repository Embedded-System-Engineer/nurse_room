/* 
 * File:   Requests.h
 * Author: hassa
 *
 * Created on April 26, 2023, 2:16 PM
 */

#ifndef REQUESTS_H
#define	REQUESTS_H
#include "appRes.h"

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < DisplayGetConfigReq >                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void DisplayGetConfigReq                                                           |
 | < @Description       : Request Config State                                                 |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t RoomGetConfigReq();

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < PowerOnRequest >                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void PowerOnRequest                                                           |
 | < @Description       : request data from save unit                                                   |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t PowerOnRequest();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < GetIpRequest >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void GetIpRequest                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t GetIpRequest();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < ResForConfig >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void ResForConfig                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t ResForConfig();
#endif	/* REQUESTS_H */

