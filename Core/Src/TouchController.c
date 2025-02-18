/*
 * TouchController.c
 *
 *  Created on: Feb 17, 2025
 *      Author: hussam
 */

#include "TouchController.h"
#include "lvgl.h"
#include "main.h"
#include "i2c.h"


#define FT5336_I2C_ADDR     (0x38 << 1)  // 8-bit I2C address
#define FT5336_TD_STATUS    0x02
#define FT5336_TOUCH1_XH    0x03
#define FT5336_TOUCH1_YH    0x05
#define SCREEN_WIDTH        480
#define SCREEN_HEIGHT       272


static volatile uint8_t touch_irq = 0;
static volatile int32_t last_x = 0;
static volatile int32_t last_y = 0;
static volatile lv_indev_state_t last_state = LV_INDEV_STATE_RELEASED;

uint8_t data_buffer[4];

static void lvgl_touchscreen_read (lv_indev_t *indev, lv_indev_data_t *data);

void lvgl_touchscreen_init (void)
{
  /* basic LVGL driver initialization */
  lv_indev_t * indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, lvgl_touchscreen_read);

}

static void
lvgl_touchscreen_read (lv_indev_t      *indev,
                       lv_indev_data_t *data)
{
  /*Use the saved coordinates if there were an interrupt*/
  if(touch_irq)
    {
      /* reset interrupt flag */
      touch_irq = 0;
	  data->point.x = last_x;
	  data->point.y = last_y;
	  data->state = last_state;
    }
    /*If there is no interrupt the touch is released*/
    else
    {
	  last_state = LV_INDEV_STATE_RELEASED;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == CTP_INT_Pin)
	{
		touch_irq = 1;
		uint8_t state;
		/* read x/y coordinates */

		state=HAL_I2C_Mem_Read(&hi2c4, FT5336_I2C_ADDR, FT5336_TOUCH1_XH, 1, data_buffer, 4, HAL_MAX_DELAY);
		if(state==HAL_OK)
		{
			last_y = ((data_buffer[0] & 0x0F) << 8) | data_buffer[1];
			last_x = ((data_buffer[2] & 0x0F) << 8) | data_buffer[3];

			last_state = LV_INDEV_STATE_PRESSED;
		}

		else
		{
			last_state = LV_INDEV_STATE_RELEASED;
		}
	}
}
