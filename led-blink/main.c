#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {

    // Step 1: Set PB5 as output
    DDRB |= (1 << DDB5);

    while (1) {

        // Step 2: LED ON
        PORTB |= (1 << PORTB5);

        // Step 3: Wait
        _delay_ms(5000);

        // Step 4: LED OFF
        PORTB &= ~(1 << PORTB5);

        // Step 5: Wait again
        _delay_ms(5000);
    }
}