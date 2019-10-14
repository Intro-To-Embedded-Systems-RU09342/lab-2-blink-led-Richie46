#include <msp430.h> 

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
    P1REN |= BIT1;                          //enable resistor
    P1DIR |= BIT0;                          // Clear P1.0 output latch for a defined power-on state
    P1OUT |= BIT1;

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    while (1)
    {
        if ((P1IN & BIT1) != BIT1)                    //enable when button is pressed down
        {
            P1OUT ^= BIT0;
            __delay_cycles(100000);
        }
    }

	return 0;
}
