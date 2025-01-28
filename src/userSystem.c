
#include "../inc/appRes.h"
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Variables>                                                |
 --------------------------------------------------------------------------------------------------------
 */

/*
 *<@var user Indicator System
 */
static uint8_t gu8UserSystem;
/*
 *user Last Indicator System 
 */
static uint8_t gu8UserSystemLast;
/*
 *<@var : Emg USer State
 */
static uint8_t gu8EMGUserState;
/*
 *<@var : Emg USer State
 */
static uint8_t gu8AcceptLastState;
/*
 *<@var : Accept USer State
 */
static uint8_t gu8UserCounter;
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Function Definitions>                                                |
 --------------------------------------------------------------------------------------------------------
 */
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onDefault>                                                          |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onDefault                                                              |
 | < @Description         : System In Default Case                                                      |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onDefault();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onStartConfig>                                                      |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onStartConfig                                                          |
 | < @Description         : Active On system set new config System                                      |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onStartConfig();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserCall>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserCall                                                             |
 | < @Description         : user indicator at call events                                               |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserCall();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserAssiest>                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserAssiest                                                         |
 | < @Description         : user indicator at asseissiet events                                        |      
 | < @return              : void                                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserAssiest();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserEMG>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserEMG                                                             |
 | < @Description         : user indicator at emg events                                               |      
 | < @return              : void                                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserEMG();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserCencel>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserCencel                                                           |
 | < @Description         : user indicator at cencel events                                             |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserCencel();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserAccept>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserAccept                                                           |
 | < @Description         : user indicator at accept  events                                            |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserAccept();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Function >                                                |
 --------------------------------------------------------------------------------------------------------
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onDefault>                                                          |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onSerial                                                               |
 | < @Description         : state with set Value                                                        |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onSerial() {
    /*LED is run every 50ms*/
    if (!isTonePlaying(1)) {
        Toneplay(1, 200, 1, 100);
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onDefault>                                                          |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onDefault                                                              |
 | < @Description         : System In Default Case                                                      |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onDefault() {
    /*LED is run every 50ms*/
    if (!isTonePlaying(2)) {
        Toneplay(2, 200, 1, 100);
    }

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onStartConfig>                                                      |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onStartConfig                                                          |
 | < @Description         : Active On system set new config System                                      |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onStartConfig() {
    if (!isTonePlaying(2)) {

        if (gu8EMGUserState) {
            updateQueueState(QUEUE_DEFUALT_CASE);
            gu8UserSystem = gu8UserSystemLast;
            gu8UserCounter = 0;
            Tonestop(TONE_PIN2_GPIO, 3, GPIO_LOW);
            Tonestop(TONE_PIN0_GPIO, 0, GPIO_LOW);
        } else {
            Toneplay(2, 1000, 20, 100);
            if (getBuzzerState()) {
                return;
            }
            Toneplay(0, 1000, 20, 100);
        }
        gu8EMGUserState ^= 1;
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserCall>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserCall                                                             |
 | < @Description         : user indicator at call events                                               |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserCall() {
    /*check buzzer configuarion*/
    digitalPinWrite(TONE_PIN1_GPIO, GPIO_HIGH);
    if (getBuzzerState()) {
        return;
    }
    if (!isTonePlaying(0)) {
        if (gu8UserCounter < getBuzzerTimeFactor()) {
            gu8UserCounter++;
            Toneplay(0, 3000, 1, 300);
        } else {
            Tonestop(TONE_PIN0_GPIO, 0, GPIO_LOW);
        }
    }

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserAssiest>                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserAssiest                                                         |
 | < @Description         : user indicator at asseissiet events                                        |      
 | < @return              : void                                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserAssiest() {
    if (!isTonePlaying(1)) {
        if (gu8EMGUserState) {
            Toneplay(1, 1000, 3, 0);
            Toneplay(0, 1000, 3, 0);
        } else {
            Toneplay(1, 1000, 3, 300);

            if (!getBuzzerState() && gu8UserCounter < getBuzzerTimeFactor()) {
                gu8UserCounter++;
                Toneplay(0, 1000, 3, 300);
            }
        }
        gu8EMGUserState ^= 1;
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserEMG>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserEMG                                                             |
 | < @Description         : user indicator at emg events                                               |      
 | < @return              : void                                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserEMG() {
    digitalPinWrite(TONE_PIN3_GPIO, GPIO_HIGH);
    if (getBuzzerState()) {
        return;
    }
    if (!isTonePlaying(0)) {
        if (gu8UserCounter < getBuzzerTimeFactor()) {
            gu8UserCounter++;
            Toneplay(0, 500, 1, 100);
        } else {
            Tonestop(TONE_PIN0_GPIO, 0, GPIO_LOW);
        }
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserCencel>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserCencel                                                           |
 | < @Description         : user indicator at cencel events                                             |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserCencel() {
    /*wait last duration and stop tone*/
    if (!isTonePlaying(0)) {
        Tonestop(TONE_PIN0_GPIO, 0, GPIO_LOW);
    }
    /*stop*/
    digitalPinWrite(TONE_PIN2_GPIO, GPIO_HIGH);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserAccept>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserAccept                                                           |
 | < @Description         : user indicator at accept  events                                            |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserAccept() {
    if (gu8AcceptLastState == SYSTEM_CALL_EVENT) {
        onUserCall();
        return;
    }

    if (gu8AcceptLastState == SYSTEM_EMG_EVENT) {
        onUserEMG();
        return;
    }

    if (gu8AcceptLastState == SYSTEM_ASSISSET_EVENT) {
        onUserAssiest();
        return;
    }
    onUserCencel();
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < RegisterOnUserSystem >                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function                  : void RegisterOnUserSystem                                             |
 | < @Description               : user indicator show                                                   |     
 | < @Param  UserIndicatorId    : system indicator hav a 6 Indicator                                    |
 |                               : 0 OnDefault System                                                   |
 |                               : 1 OnStart Configuration Set                                          |
 |                               : 2 On Call State                                                      |
 |                               : 3 On Emg State                                                       |
 |                               : 4 On Cencel State                                                    |
 *  |                            : 5 On Accept State                                                    |
 | < @return                     : void                                                                 |
 --------------------------------------------------------------------------------------------------------
 */
void RegisterOnUserSystem(uint8_t UserIndicatorId) {
    if (RoomGetType()) {
        RegisterOnUserSystem2(UserIndicatorId);
        return;
    }
    gu8UserSystemLast = gu8UserSystem;
    gu8UserSystem = UserIndicatorId;

    gu8EMGUserState = 0;
    gu8UserCounter = 0;
    Tonestop(TONE_PIN0_GPIO, 0, GPIO_LOW);
    Tonestop(TONE_PIN1_GPIO, 1, GPIO_LOW);
    Tonestop(TONE_PIN2_GPIO, 2, GPIO_LOW);
    Tonestop(TONE_PIN3_GPIO, 3, GPIO_LOW);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserInit>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserInit                                                               |
 | < @Description         : Init all variable in this file                                              |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserInit() {
    gu8UserSystem = 0;
    gu8EMGUserState = 0;
    gu8AcceptLastState = 0;
    gu8UserCounter = 0;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserCallBack>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserCallBack                                                           |
 | < @Description         : run in background                                                           |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserCallBack() {
    if (!SystemIsSerial()) {
        onSerial();
        return;
    }


    switch (gu8UserSystem) {
        case SYSTEM_DEFALUT_EVENT:
            onDefault();
            break;
        case SYSTEM_START_ADDRESS_EVENT:
            onStartConfig();
            break;
        case SYSTEM_CANCEL_EVENT:
            onUserCencel();
            break;
        case SYSTEM_ACCEPT_EVENT:
            if (getAcceptState()) {
                onUserCencel();
            } else {
                onUserAccept();
            }
            break;
        case SYSTEM_ASSISSET_EVENT:
            onUserAssiest();
            break;
        case SYSTEM_CALL_EVENT:
            onUserCall();
            break;
        case SYSTEM_EMG_EVENT:
            onUserEMG();
            break;
        default:
            gu8UserSystem = SYSTEM_DEFALUT_EVENT;
            break;
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserSetAcceptValueRun>                                              |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserSetAcceptValueRun                                                  |
 | < @Description         : set accept state is run is emg or  Call                                     |   
 | < @Param state         : 1 is call and 2 is Emg else not run any case                                |
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserSetAcceptValueRunif(uint8_t state) {
    if (RoomGetType()) {
        UserSetAcceptValueRun2(state);
        return;
    }
    if (state == SYSTEM_ASSISSET_EVENT) {
        return;
    }
    gu8AcceptLastState = state;
}