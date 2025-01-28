
#include "../inc/appRes.h"
static uint8_t gu8IP;
static uint8_t gu8WriteState;


/*
 --------------------------------------------------------------------------------------------------------
 |                                 <Variables>                                                       |
 --------------------------------------------------------------------------------------------------------
 */
/*
 *<@var : Board Info and configuration var
 */
static boardinfo_t gstboardInfo;
/*
 * <@var : system configurations
 */
static SystemConfig_t gsSystemConfig;
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <Internal function Definitions>                                         |
 --------------------------------------------------------------------------------------------------------
 */
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveSerial>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveSerial                                                           |
 | < @Description         : save serial number On boot section this function reboot system              |   
 | < @return              : void                                                     |          
 --------------------------------------------------------------------------------------------------------
 */
static void OnSaveSerial(uint8_t *buf);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <Internal function >                                         |
 --------------------------------------------------------------------------------------------------------
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveSerial>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveSerial                                                           |
 | < @Description         : save serial number On boot section this function reboot system              |   
 | < @return              : void                                                     |          
 --------------------------------------------------------------------------------------------------------
 */
static void OnSaveSerial(uint8_t *buf) {
    copyBuff((uint8_t *) & gstboardInfo.Time, (&buf[0]) + 3, 4);
    copyBuff((uint8_t*) & gstboardInfo.Code, (&buf[0]) + 9, 6);
    gu8WriteState = 6;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveIp>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveIp                                                               |
 | < @Description         :save Ip and Re-boot system                                                   |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void OnSaveIp(uint8_t Ip) {
    gu8IP = Ip;
    csmaInitStationIp(gu8IP);
    gu8WriteState = 3;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <RoomGetType>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void RoomGetType                                                            |
 | < @Description         : get hw type v0 or v1                                                        |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t RoomGetType() {
    return gsSystemConfig.option.HWType;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getBuzzerState>                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getBuzzerState                                                         |
 | < @Description         : get State of the Buzzer                                                     |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getBuzzerState() {
    return gsSystemConfig.option.Buz;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getAcceptState>                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getAcceptState                                                         |
 | < @Description         : get value of response of call or Emg                                        |   
 | < @return              : 0 is accept value active and  1 is accept value cencel                      |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getAcceptState() {
    return gsSystemConfig.option.DisapledSystem;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemScollerTime>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t SystemScollerTime                                                    |
 | < @Description         : get scoller Time                                                             |   
 | < @return              : void                                                                         |          
 --------------------------------------------------------------------------------------------------------
 */
time_t SystemScollerTime() {
    return ((time_t) gsSystemConfig.scollerTime * 1000UL);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getBuzzerTimeFactor>                                               |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getBuzzerTimeFactor                                                    |
 | < @Description         : get max value of actor to run buzzer                                        |   
 | < @return              :max number of Time Factor 0 To 255                                           |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getBuzzerTimeFactor() {
    return gsSystemConfig.option.buzzerTimeFactor;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <ConfigurationInit>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void ConfigurationInit                                                      |
 | < @Description         : get Init all data in this File                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void ConfigurationInit() {
    gu8IP = 1;
    gu8WriteState = 0;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveConfiguration>                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveConfiguration                                                    |
 | < @Description         : save configuartion On boot section this function reboot system              |   
 | < @return              : 0 is off and  1 is on                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
void OnSaveConfiguration(uint8_t *buf) {
    copyBuff(&gsSystemConfig, buf, sizeof (SystemConfig_t));

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <noSerial>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void noSerial                                                               |
 | < @Description         : system have serial or not                                                   |   
 | < @return              : 0 is not have a serial and  1 system have a serial                          |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t SystemIsSerial() {
    if (gstboardInfo.Time == 0) {
        return (0);
    }
    return (1);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemIp>                                                            |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t SystemIp                                                             |
 | < @Description         : get system ip                                                                |   
 | < @return              : void                                                                         |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t SystemIp() {
    return gu8IP;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <EEpromCallback>                                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t EEpromCallback                                                              |
 | < @Description         : get ip from eeprom                                                              |   
 | < @return              : return system ip                                                            |          
 --------------------------------------------------------------------------------------------------------
 */
void EEpromCallback() {
    if (eepromIsBusy()) {
        return;
    }
    switch (gu8WriteState) {
        case 0:
            eepromRequestSterm(0, 1);
            gu8WriteState = 1;
            break;
        case 1:
            eepromRead(&gu8IP);
            if (gu8IP == 0 || gu8IP >= MAX_DEVICE_USED) {
                gu8IP = 1;
            }
            gu8WriteState = 4;
            break;
        case 2:
            break;
        case 3:
            eepromWriteBuf(0, 1, &gu8IP);
            gu8WriteState = 2;
            break;
        case 4:
            eepromRequestSterm(1, sizeof (boardinfo_t));
            gu8WriteState = 5;
            break;
        case 5:
            eepromRead((uint8_t *) & gstboardInfo);
            gu8WriteState = 7;
            break;
        case 6:
            eepromWriteBuf(1, sizeof (boardinfo_t), (uint8_t *) & gstboardInfo);
            gu8WriteState = 7;
            break;
        case 7:
            if (MatchBufWithValue((uint8_t *) & gstboardInfo, sizeof (boardinfo_t), 0x00)) {
                
            } else if (MatchBufWithValue((uint8_t *) & gstboardInfo, sizeof (boardinfo_t), 0xFF)) {
                setBuff((uint8_t *) & gstboardInfo, 0x00, sizeof (boardinfo_t));
            }
            csmaInitStationIp(gu8IP);
            csmaSaveSerialRegister(OnSaveSerial);
            csmaloadConfig(gstboardInfo.CH0, gstboardInfo.Time);
            gu8WriteState = 2;
            break;
        default:
            gu8WriteState = 0;
            break;

    }
}