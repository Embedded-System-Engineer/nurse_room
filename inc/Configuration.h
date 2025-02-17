/* 
 * File:   Configuration.h
 * Author: hassa
 *
 * Created on April 22, 2023, 11:23 PM
 */

#ifndef CONFIGURATION_H
#define	CONFIGURATION_H
#include "appRes.h"

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <RoomGetType>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void RoomGetType                                                            |
 | < @Description         : get hw type v0 or v1                                                        |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t RoomGetType();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getBuzzerState>                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getBuzzerState                                                         |
 | < @Description         : get State of the Buzzer                                                     |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getBuzzerState();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getAcceptState>                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getAcceptState                                                         |
 | < @Description         : get value of response of call or Emg                                        |   
 | < @return              : 0 is accept value active and  1 is accept value cencel                      |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getAcceptState();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getBuzzerTimeFactor>                                               |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getBuzzerTimeFactor                                                    |
 | < @Description         : get max value of actor to run buzzer                                        |   
 | < @return              :max number of Time Factor 0 To 255                                           |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getBuzzerTimeFactor();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemScollerTime>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t SystemScollerTime                                                    |
 | < @Description         : get scoller Time                                                             |   
 | < @return              : void                                                                         |          
 --------------------------------------------------------------------------------------------------------
 */
time_t SystemScollerTime() ;
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <ConfigurationInit>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void ConfigurationInit                                                      |
 | < @Description         : get Init all data in this File                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void ConfigurationInit();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveConfiguration>                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveConfiguration                                                    |
 | < @Description         : save configuartion On boot section this function reboot system              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void OnSaveConfiguration(uint8_t *buf);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <noSerial>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void noSerial                                                               |
 | < @Description         : system have serial or not                                                   |   
 | < @return              : 0 is not have a serial and  1 system have a serial                          |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t SystemIsSerial();

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemIp>                                                            |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t SystemIp                                                             |
 | < @Description         : get system ip                                                                |   
 | < @return              : void                                                                         |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t SystemIp();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveIp>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveIp                                                               |
 | < @Description         :save Ip and Re-boot system                                                   |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
 void OnSaveIp(uint8_t Ip);
 /*
 --------------------------------------------------------------------------------------------------------
 |                                 <EEpromCallback>                                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t EEpromCallback                                                              |
 | < @Description         : get ip from eeprom                                                              |   
 | < @return              : return system ip                                                            |          
 --------------------------------------------------------------------------------------------------------
 */
void EEpromCallback();
#endif	/* CONFIGURATION_H */

