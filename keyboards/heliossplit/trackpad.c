#include "pointing_device.h"
#include "quantum.h"
#include "report.h"
#include "IQS5xx.h"
#include "print.h"
#include "i2c_master.h"
#include "timer.h"
#include "config.h"
#include "trackpad.h"


uint8_t 	Data_Buff[44];
uint8_t     activeRefreshRate[2] = {0, TRACKPAD_RATE};
uint8_t     idleRefreshRate[2] = {0,16};
uint16_t	ui16SnapStatus[15], ui16PrevSnap[15];
uint8_t		stop = 1;

void pointing_device_init(void) { 
    print("\ntrackpad setup start\n");
	// Configure RDY pin
	//
	//setPinInputHigh(RDY_PIN);
	
	//I2C_Setup();
	if(is_keyboard_master()){
		i2c_init();
		print("\nedwn\n");
		uint8_t dat[2] = {0};
		i2c_status_t t = i2c_readReg16(IQS5xx_ADDR<<1, 0, &dat[0], 2, 10);
		if (t == I2C_STATUS_TIMEOUT) {
			print("\nedw\n");
		}

		/* i2c_status_t status = i2c_start(devaddr, I2C_TIMEOUT); */
		/* if (status < 0) { */
		/* 	goto error; */
		/* } */

		/* i2c_writeReg16(IQS5xx_ADDR<<1, END_WINDOW, &stop, 1, 7); */
		
		/* i2c_writeReg16(IQS5xx_ADDR<<1, END_WINDOW, &stop, 1, 7); */
		/* i2c_writeReg16(IQS5xx_ADDR<<1, IdleTouchRR_adr, &idleRefreshRate[0], 2, 4); */
		/* i2c_writeReg16(IQS5xx_ADDR<<1, END_WINDOW, &stop, 1, 7); */
		/* i2c_writeReg16(IQS5xx_ADDR<<1, LP1RR_adr, &idleRefreshRate[0], 2, 4); */
		/* i2c_writeReg16(IQS5xx_ADDR<<1, END_WINDOW, &stop, 1, 7); */
		/* i2c_writeReg16(IQS5xx_ADDR<<1, LP2RR_adr, &idleRefreshRate[0], 2, 4); */
		/* i2c_writeReg16(IQS5xx_ADDR<<1, END_WINDOW, &stop, 1, 7); */
	}
}

uint16_t timeout = 2;
static uint16_t timer = 0;

bool pointing_device_task(void) {
	if(is_keyboard_master()){
		if(timer_elapsed(timer) >= timeout) {
			//RDY_wait();
			timer = timer_read(); 
			i2c_status_t t = i2c_readReg16(IQS5xx_ADDR<<1, GestureEvents0_adr, &Data_Buff[0], 44, 10);

			if (t == I2C_STATUS_TIMEOUT) {
				/* print("\nedw\n"); */
			}
			i2c_writeReg16(IQS5xx_ADDR<<1, END_WINDOW, &stop, 1, 1);
			// Process received data 
			Process_XY();
		}
	}
	return true;
}
