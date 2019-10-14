#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer

    P1DIR |= BIT0;                          // Clear P1.0 output latch for a defined power-on state                         // Set P1.0 to output direction
    P1REN |= BIT3;
    P1OUT |= BIT3;

    while(1)
    {
        if ((P1IN&BIT3)!=BIT3)
        {
            P1OUT ^= BIT0;
            __delay_cycles(100000);
        }
    }
    return 0;
}
