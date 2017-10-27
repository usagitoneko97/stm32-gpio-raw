/*
 * Gpio.c

 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#include"Gpio.h"

uint32_t *gpioGMode = (uint32_t*)(GPIOG_BASE_ADDR+GPIO_MODE_OFF);
uint32_t *gpioOSpeed= (uint32_t*)(GPIOG_BASE_ADDR+GPIO_OSPEED_OFF);
uint32_t *gpioGPupd= (uint32_t*)(GPIOG_BASE_ADDR+GPIO_PUPD_OFF);
uint32_t *gpioGOtype = (uint32_t*)(GPIOG_BASE_ADDR + GPIO_OTYPE_OFF);
uint32_t *gpioGOdr= (uint32_t*)(GPIOG_BASE_ADDR + GPIO_ODR_OFF);
uint32_t *gpioAIdr = (uint32_t*)(GPIOA_BASE_ADDR + GPIO_IDR_OFF);


void gpioGConfig(int pin, int mode, int outDriveType, int pullType, int speed){
	/*clear pin mode to 0*/
	*gpioGMode &= ~(3<<(pin*2));
	/*set the mode*/
	*gpioGMode |= (mode<<(pin*2));
	//*gpioGMode = 0xff;

	*gpioOSpeed   &= ~(3<<(pin*2)); //clear the pin speed
	*gpioOSpeed   |= speed<<(pin*2); //set the pin speed

	*gpioGPupd = ~(pullType<<(pin*2)); //set the pupd

	*gpioGOtype |= (outDriveType<<pin);

}

void gpioGWrite(int pin, int state){
	if(state == 1){
		*gpioGOdr |= 1<<pin;

	}
	else{
		*gpioGOdr &= ~(1<<pin);
	}
}

int gpioARead(int pin){
	return (((*gpioAIdr)&0x1) > 0);
}

