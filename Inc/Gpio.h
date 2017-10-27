/*
 * Gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef GPIO_H_
#define GPIO_H_

#include<stdint.h>
#define GPIOG_BASE_ADDR 			0x40021800
#define GPIOA_BASE_ADDR				0x40020000
#define GPIO_MODE_OFF	 	0x0
#define GPIO_OSPEED_OFF	 	0x8
#define GPIO_PUPD_OFF		0x0c
#define GPIO_OTYPE_OFF		0x04
#define GPIO_ODR_OFF		0x14
#define GPIO_IDR_OFF		0x10

#define  GPIO_MODE_IN   	0x00000000U   /*!< Input Floating Mode                   */
#define  GPIO_MODE_OUT		0x00000001U   /*!< Output Push Pull Mode                 */
#define  GPIO_MODE_AF	    0x00000002U   /*!< Alternate Function Push Pull Mode     */
#define  GPIO_MODE_AN		3

#define GPIO_PUSH_PULL			0
#define GPIO_OPEN_DRAIN			1

#define GPIO_L_SPEED			0
#define GPIO_M_SPEED			1
#define GPIO_H_SPEED			2
#define GPIO_VH_SPEED			3

#define  GPIO_NOPULL        0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        0x00000001U   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      0x00000002U   /*!< Pull-down activation*/

void gpioGConfig(int pin, int mode, int outDriveType, int pullType, int speed);
void gpioGWrite(int pin, int state);
int gpioARead(int pin);

//export variables to other modules
extern uint32_t *gpioGOdr;
extern uint32_t *gpioGMode;
extern uint32_t *gpioOSpeed;
extern uint32_t *gpioGPupd;
extern uint32_t *gpioGOtype;
extern uint32_t *gpioAIdr;
#endif /* GPIO_H_ */
