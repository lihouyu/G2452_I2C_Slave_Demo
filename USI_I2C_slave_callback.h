/*
 * USI_I2C_slave_callback.h
 *
 *  Created on: 2013-5-16
 *      Author: li.houyu
 */

#ifndef USI_I2C_SLAVE_CALLBACK_H_
#define USI_I2C_SLAVE_CALLBACK_H_

unsigned char get4th_byte();
void set_data();

/***********************************************
 * Mandatory functions for callback
 ***********************************************/
unsigned char * USI_I2C_slave_TX_callback();
unsigned char USI_I2C_slave_RX_callback(unsigned char * byte);
void _USI_I2C_slave_reset_byte_count();
//**********************************************/

#endif /* USI_I2C_SLAVE_CALLBACK_H_ */
