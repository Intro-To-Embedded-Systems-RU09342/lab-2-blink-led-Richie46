#include <msp430.h> 

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P2DIR |= BIT2;                          // Clear P1.0 output latch for a defined power-on state
    P2OUT |= BIT2;
    P2DIR |= BIT3;
    P2OUT |= BIT3;


    while (1)
    {
            P2OUT ^= BIT2;
            __delay_cycles(100000);
            P2OUT ^= BIT3;
            __delay_cycles(100000);
            P2OUT ^= BIT3;
            __delay_cycles(100000);
    }

    return 0;
}
