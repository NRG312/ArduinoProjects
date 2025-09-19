#include <ManagePin.h>
#include <avr/io.h>
#include <stdint.h>

uint8_t ManagePin(volatile uint8_t *Setddr,volatile uint8_t *Setport, int8_t pin, SetModePin mode, SetIO io, uint8_t status){
    
    //Input or Output
    if (io == Input)
    {
        *Setddr &= ~(1 << pin);//Set input
    }
    else if (io == Output)
    {
        *Setddr |= (1 << pin); //Set output
    }
    //MODE
    if (mode == Turn_On)
    {
        *Setport |= (1 << pin); //set pin high voltage(5V)
        status |= (1 << pin);
    }
    else if (mode == Turn_Off)
    {
        *Setport &= ~(1 << pin); //set pin low voltage(0V)
        status &= ~(1 << pin);
    }

    return status;
}