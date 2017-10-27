/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#include <stdint.h>
#ifndef RCC_H_
#define RCC_H_


#define RCC_BASE_ADDR			0x40023800
#define RCC_AHB1RST_OFF			0x10U
#define RCC_AHB1EN_OFF			0x30U

extern uint32_t *rccAhb1Rst;
extern uint32_t *rccAhb1En;
void enableGpioG(void);
void enableGpioA(void);

#endif /* RCC_H_ */
