#include <msp430g2452.h>

#include "USI_I2C_slave.h"
#include "USI_I2C_slave_callback.h"

unsigned char I2C_slave_own_address = 0x41;
/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    BCSCTL1 = CALBC1_12MHZ;
    DCOCTL = CALDCO_12MHZ;

    P1DIR |= BIT0;
    P1OUT &= ~BIT0;

    USI_I2C_slave_init(I2C_slave_own_address);

    while (1) {
    	/*
        if (get4th_byte() == 4)
        	P1OUT |= BIT0;
        else
        	P1OUT &= ~BIT0;
        */
    }
}
