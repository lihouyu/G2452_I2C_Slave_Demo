/*
 * USI_I2C_slave_callback.c
 *
 *  Created on: 2013-5-16
 *      Author: li.houyu
 */

#include <msp430g2452.h>

/***********************************************
 * User defined variables and functions
 ***********************************************/
unsigned char I2C_data[64]; // User defined data store area, can be in EEPROM.
unsigned char blink = 1;

unsigned char get4th_byte() {
	return I2C_data[3];
}

void set_data() {
	I2C_data[0] = 0x01;
	I2C_data[1] = 0x02;
	I2C_data[2] = 0x03;
	if (blink)
		I2C_data[3] = 0x04;
	else
		I2C_data[3] = 0x00;
}
//**********************************************/



/***********************************************
 * Callback related variables (Mandatory)
 * Do not change the variable name
 ***********************************************/
unsigned char _USI_I2C_slave_n_byte;
//**********************************************/

/***********************************************
 * Mandatory functions for callback
 * You can modify codes in these functions
 * 		to deal with data received
 * 		or data to be sent
 * 		but left function name unchanged
 ***********************************************/
unsigned char * USI_I2C_slave_TX_callback() {
	_USI_I2C_slave_n_byte++;
	if (_USI_I2C_slave_n_byte == 1) {
		blink ^= 1;
		set_data();
		P1OUT |= BIT0;
	}
	if (_USI_I2C_slave_n_byte == 4) {
		P1OUT &= ~BIT0;
		__delay_cycles(12);
	}
	return I2C_data + _USI_I2C_slave_n_byte - 1;
}

unsigned char USI_I2C_slave_RX_callback(unsigned char * byte) {
	*(I2C_data + _USI_I2C_slave_n_byte) = *byte;
	_USI_I2C_slave_n_byte++;
	return 0; // 0: No error; Not 0: Error in received data
}

void _USI_I2C_slave_reset_byte_count() {
	_USI_I2C_slave_n_byte = 0;
}
//**********************************************/
