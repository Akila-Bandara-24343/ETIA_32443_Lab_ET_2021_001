#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5));
    DDRD = (1 << PD6) | (1 << PD7);

    while (1) {
    }
    return 0;
}