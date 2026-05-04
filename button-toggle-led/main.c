#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
    // LED (PB5)
    DDRB |= (1 << DDB5);

    // Button (PD2)
    DDRD &= ~(1 << DDD2);
    PORTD |= (1 << PORTD2); // pull-up

    uint8_t led_state = 0;
    uint8_t prev_button = 1;

    while (1)
    {
        uint8_t curr_button = PIND & (1 << PIND2);

        // Detect press (HIGH → LOW)
        if (prev_button && !curr_button)
        {
            led_state ^= 1;  // toggle

            if (led_state)
                PORTB |= (1 << PORTB5);
            else
                PORTB &= ~(1 << PORTB5);
        }

        prev_button = curr_button;
    }
}