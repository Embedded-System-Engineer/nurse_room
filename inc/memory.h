/* 
 * File:   memory.h
 * Author: hassa
 *
 * Created on April 19, 2023, 12:07 PM
 */

#ifndef MEMORY_H
#define	MEMORY_H
#include "appRes.h"

typedef union {
    uint8_t Options;

    struct {
        unsigned Buz : 1;
        unsigned HWType : 1;
        unsigned DisapledSystem : 1;
        unsigned buzzerTimeFactor : 5;
    };
} RoomOptions_t;

typedef struct callPoint_s {
    uint8_t State;
    uint16_t userSwID;
    uint16_t userRID;
} callPoint_t;
typedef struct SystemConfig_t {
    uint8_t scollerTime;
    RoomOptions_t option;
} SystemConfig_t;
/*
 * < @macro APP_START : start of the application       
 */
#define  BOOT_START      asm("JMP 0x3E00")


#define  LED0            GPIO_C0
#define  LED1            GPIO_C1
#define  LED2            GPIO_C2

/*
 * <@marco system cancel state
 */
#define SYSTEM_DEFALUT_EVENT               0x00
/*
 * <@marco system cancel state
 */
#define SYSTEM_START_ADDRESS_EVENT         0x01
/*
 * <@marco system cancel state
 */
#define SYSTEM_CANCEL_EVENT                0x02
/*
 * <@marco system call state
 */
#define  SYSTEM_ACCEPT_EVENT               0x03
/*
 * <@marco system call state
 */
#define SYSTEM_ASSISSET_EVENT              0x04
/*
 * <@marco system call state
 */
#define SYSTEM_CALL_EVENT                  0x05
/*
 * <@marco system call state
 */
#define SYSTEM_EMG_EVENT                   0x06

#endif	/* MEMORY_H */

