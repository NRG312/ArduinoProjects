#include <ManagePin.h>
#include "stdint.h"
#include <avr/io.h>

bool CheckActiveButton(void);
void ManagePins();

uint8_t status = 0b00000000;

int main(void){
    DDRB |= (1 << PB5);//port for diode 13
    ManagePins();
    while(1){
        if (CheckActiveButton())
        {
            status |= (1 << 3);
            PORTB |= (1 << 5);
        }
        else{
            status &= ~(1 << 3);
            PORTB &= ~(1 << 5);
        }
    }
}

bool CheckActiveButton(void){
    return !(PIND & (1 << PD2)); //true when click button
}
void ManagePins(){
    status = ManagePin(&DDRD,&PORTD,2,Turn_On,Input,status); //Set pin for button
    status = ManagePin(&DDRD,&PORTD,4,Turn_Off,Output,status); //Set pin for Diode1
    status = ManagePin(&DDRD,&PORTD,7,Turn_Off,Output,status); //Set pin for Diode2
}