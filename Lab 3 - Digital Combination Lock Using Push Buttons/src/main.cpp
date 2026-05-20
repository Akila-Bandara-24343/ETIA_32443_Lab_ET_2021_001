#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5));// PB inputs
    DDRD |= (1 << PD6) | (1 << PD7); // LEDS
    char pwd = '4231';
    char inpwd;
    while (1) {

      if ((PIND & (1 << PD2)) == 0) { // Check if button 1 is pressed
          char b1 = '2';
          inpwd = inpwd + b1;
          _delay_ms(100);
        } 
      else if ((PIND & (1 << PD3)) == 0) { // Check if button 2 is pressed
          char b2 = '1';
          inpwd = inpwd + b2;
          _delay_ms(100);
        }
      else if ((PIND & (1 << PD4)) == 0) { // Check if button 3 is pressed
          char b3 = '3';
          inpwd = inpwd + b3;
          _delay_ms(100);
        }
      else if ((PIND & (1 << PD5)) == 0) { // Check if button 4 is pressed
          char b4 = '4';
          inpwd = inpwd + b4;
          _delay_ms(100);
        }

      if (inpwd == pwd) {
          PORTD |= (1 << PD6); // Turn on Green LED
          PORTD &= ~(1 << PD7); // Turn off RED LED
        } else {
          PORTD &= ~(1 << PD6); // Turn Green LED
          PORTD |= (1 << PD7); // Turn RED LED
        }

    }
    return 0;
}