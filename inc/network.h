/* 
 * File:   network.h
 * Author: hassa
 *
 * Created on April 23, 2023, 1:43 PM
 */

#ifndef NETWORK_H
#define	NETWORK_H
#include "appRes.h"

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkInit>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkInit                                                            |
 | < @Description         : Init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkInit();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkRoomCallBack>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t NetworkRoomCallBack                                                      |
 | < @Description         : find my ip in this list of ips                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkRoomCallBack();
#endif	/* NETWORK_H */

