/*
 * LCDController.h
 *
 *  Created on: Feb 17, 2025
 *      Author: hussam
 */

#ifndef INC_LCDCONTROLLER_H_
#define INC_LCDCONTROLLER_H_

#include "lvgl.h"

/* Initialize low level display driver */
void lv_port_disp_init(void);

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void);

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void);


#endif /* INC_LCDCONTROLLER_H_ */
