#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1


void UART_init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;

    UCSR0B = (1 << TXEN0); // Enable transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

void UART_transmit(char data) {
    while (!(UCSR0A & (1 << UDRE0)));

    UDR0 = data;
}

void UART_print(char *str) {
    while (*str) {
        UART_transmit(*str++);
    }
}

int main(void) {

    UART_init(MYUBRR);

  	DDRD &= ~(1 << PD2); // PIR input pin -> Digital pin 2
    DDRD = (1 << PD4)|(1 << PD3)|(1 << PD7); // Motion detection LED (RED) -> Digital pin 3 ,System detection LED (GREEN) -> Digital pin 4

    while (1) {
      
      //System indicating section 
        PORTD |= (1 << PD4);
        _delay_ms(1000);
        PORTD &= ~(1 << PD4);
        _delay_ms(1000);


      //PIR Detection and motion indicating section 
        if (PIND & (1 << PIND2)) {
          UART_print("Motion Detected\r\n"); 
          _delay_ms(1000);
        } else {
          UART_print("No Motion is detected\r\n");
          _delay_ms(1000);
        }
    }
    return 0;
}