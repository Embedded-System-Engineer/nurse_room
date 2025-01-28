
#include "../inc/appRes.h"
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Variables>                                                |
 --------------------------------------------------------------------------------------------------------
 */

/*
 *<@var user Indicator System
 */
static uint8_t gu8UserSystem2;
/*
 *user Last Indicator System 
 */
static uint8_t gu8UserSystemLast2;
/*
 *<@var : Emg USer State
 */
static uint8_t gu8EMGUserState2;
/*
 *<@var : Emg USer State
 */
static uint8_t gu8AcceptLastState2;
/*
 *<@var : Accept USer State
 */
static uint8_t gu8UserCounter2;
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
static void onDefault2();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onStartConfig>                                                      |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onStartConfig                                                          |
 | < @Description         : Active On system set new config System                                      |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onStartConfig2();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserCall>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserCall                                                             |
 | < @Description         : user indicator at call events                                               |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserCall2();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserAssiest>                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserAssiest                                                         |
 | < @Description         : user indicator at asseissiet events                                        |      
 | < @return              : void                                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserAssiest2();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserEMG>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserEMG                                                             |
 | < @Description         : user indicator at emg events                                               |      
 | < @return              : void                                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserEMG2();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserCencel>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserCencel                                                           |
 | < @Description         : user indicator at cencel events                                             |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserCencel2();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserAccept>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserAccept                                                           |
 | < @Description         : user indicator at accept  events                                            |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onUserAccept2();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Function >                                                |
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
static void onDefault2() {
    /*LED is run every 50ms*/
    if (!isTonePlaying(1)) {
        Toneplay(1, 100, 1, 50);
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
static void onStartConfig2() {
    if (!isTonePlaying(1)) {

        if (gu8EMGUserState2) {
            gu8UserSystem2 = gu8UserSystemLast2;
            updateQueueState(QUEUE_DEFUALT_CASE);
            gu8UserCounter2 = 0;
            Tonestop(TONE_PIN1_GPIO, 1, GPIO_LOW);
            Tonestop(TONE_PIN0_GPIO, 0, GPIO_LOW);
        } else {
            Toneplay(1, 1000, 20, 100);
            if (getBuzzerState()) {
                return;
            }
            Toneplay(0, 1000, 20, 100);
        }
        gu8EMGUserState2 ^= 1;
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
static void onUserCall2() {
    /*check buzzer configuarion*/
    digitalPinWrite(TONE_PIN1_GPIO, GPIO_LOW);
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
static void onUserAssiest2() {
    if (!isTonePlaying(1)) {
        if (gu8EMGUserState2) {
            Toneplay(1, 1000, 3, 0);
        } else {
            Toneplay(1, 1000, 3, 300);
        }
        gu8EMGUserState2 ^= 1;
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
static void onUserEMG2() {
    if (!isTonePlaying(1)) {
        if (gu8EMGUserState2) {
            Toneplay(1, 400, 3, 0);
            Toneplay(0, 400, 3, 0);
        } else {
            Toneplay(1, 400, 3, 200);

            if (!getBuzzerState() && gu8UserCounter2 < getBuzzerTimeFactor()) {
                gu8UserCounter2++;
                Toneplay(0, 400, 3, 200);
            }
        }
        gu8EMGUserState2 ^= 1;
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
static void onUserCencel2() {
    /*wait last duration and stop tone*/
    if (!isTonePlaying(0)) {
        Tonestop(TONE_PIN0_GPIO, 0, GPIO_LOW);
    }
    /*stop*/
    digitalPinWrite(TONE_PIN1_GPIO, GPIO_HIGH);
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
static void onUserAccept2() {
    if (gu8AcceptLastState2 == SYSTEM_CALL_EVENT) {
        onUserCall2();
        return;
    }

    if (gu8AcceptLastState2 == SYSTEM_EMG_EVENT) {
        onUserEMG2();
        return;
    }

    if (gu8AcceptLastState2 == SYSTEM_ASSISSET_EVENT) {
        onUserAssiest2();
        return;
    }
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
void RegisterOnUserSystem2(uint8_t UserIndicatorId) {
    gu8UserSystemLast2 = gu8UserSystem2;
    gu8UserSystem2 = UserIndicatorId;

    gu8EMGUserState2 = 0;
    gu8UserCounter2 = 0;
    Tonestop(TONE_PIN0_GPIO, 0, GPIO_LOW);
    Tonestop(TONE_PIN1_GPIO, 1, GPIO_LOW);
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
void UserInit2() {
    gu8UserSystem2 = 0;
    gu8EMGUserState2 = 0;
    gu8AcceptLastState2 = 0;
    gu8UserCounter2 = 0;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onDefault>                                                          |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onSerial                                                               |
 | < @Description         : state with set Value                                                        |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onSerial2() {
    /*LED is run every 50ms*/
    if (!isTonePlaying(1)) {
        Toneplay(1, 100, 1, 50);
    }
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
void UserCallBack2() {

    if (!SystemIsSerial()) {
        onSerial2();
        return;
    }
    switch (gu8UserSystem2) {
        case SYSTEM_DEFALUT_EVENT:
            onDefault2();
            break;
        case SYSTEM_START_ADDRESS_EVENT:
            onStartConfig2();
            break;
        case SYSTEM_CANCEL_EVENT:
            onUserCencel2();
            break;
        case SYSTEM_ACCEPT_EVENT:
            if (getAcceptState()) {
                onUserCencel2();
            } else {
                onUserAccept2();
            }
            break;
        case SYSTEM_ASSISSET_EVENT:
            onUserAssiest2();
            break;
        case SYSTEM_CALL_EVENT:
            onUserCall2();
            break;
        case SYSTEM_EMG_EVENT:
            onUserEMG2();
            break;
        default:
            gu8UserSystem2 = SYSTEM_DEFALUT_EVENT;
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
void UserSetAcceptValueRun2(uint8_t state) {
    gu8AcceptLastState2 = state;
}