#ifndef ManagePin_h
#define ManagePin_h
#include "stdint.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef enum {
    Turn_On,
    Turn_Off
}SetModePin;

typedef enum{
    Output,
    Input
}SetIO;

uint8_t ManagePin(volatile uint8_t *Setddr,volatile uint8_t *Setport, int8_t pin, SetModePin mode, SetIO io, uint8_t status);

#ifdef __cplusplus
}
#endif

#endif