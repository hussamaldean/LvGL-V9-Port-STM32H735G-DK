/**
  ******************************************************************************
  * @file    stm32h735g_discovery_bus.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for STM32H735G_DK LEDs,
  *          push-buttons hardware resources.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32H735G_DK_BUS_H
#define STM32H735G_DK_BUS_H

#ifdef __cplusplus
 extern "C" {
#endif


 /* Includes ------------------------------------------------------------------*/
#include "../../BSP_old/Components/Common/stm32h735g_discovery_conf.h"

#if defined(BSP_USE_CMSIS_OS)
#include "cmsis_os.h"
#endif
/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32H735G_DK
  * @{
  */

/** @addtogroup STM32H735G_DK_BUS
  * @{
  */
/** @defgroup STM32H735G_DK_BUS_Exported_Types Exported Types
  * @{
  */

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
typedef struct
{
  pI2C_CallbackTypeDef  pMspI2cInitCb;
  pI2C_CallbackTypeDef  pMspI2cDeInitCb;
}BSP_I2C_Cb_t;
#endif /* (USE_HAL_I2C_REGISTER_CALLBACKS == 1) */

/**
  * @}
  */

/** @defgroup STM32H735G_DK_BUS_Exported_Constants Exported Constants
  * @{
  */
/* Definition for I2C4 clock resources */
#define BUS_I2C4                               I2C4
#define BUS_I2C4_CLK_ENABLE()                  __HAL_RCC_I2C4_CLK_ENABLE()
#define BUS_I2C4_CLK_DISABLE()                 __HAL_RCC_I2C4_CLK_DISABLE()
#define BUS_I2C4_SCL_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOF_CLK_ENABLE()
#define BUS_I2C4_SCL_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOF_CLK_DISABLE()
#define BUS_I2C4_SDA_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOF_CLK_ENABLE()
#define BUS_I2C4_SDA_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOF_CLK_DISABLE()

#define BUS_I2C4_FORCE_RESET()                 __HAL_RCC_I2C4_FORCE_RESET()
#define BUS_I2C4_RELEASE_RESET()               __HAL_RCC_I2C4_RELEASE_RESET()

/* Definition for I2C4 Pins */
#define BUS_I2C4_SCL_PIN                       GPIO_PIN_14
#define BUS_I2C4_SDA_PIN                       GPIO_PIN_15
#define BUS_I2C4_SCL_GPIO_PORT                 GPIOF
#define BUS_I2C4_SDA_GPIO_PORT                 GPIOF
#define BUS_I2C4_SCL_AF                        GPIO_AF4_I2C4
#define BUS_I2C4_SDA_AF                        GPIO_AF4_I2C4

#ifndef BUS_I2C4_FREQUENCY
   #define BUS_I2C4_FREQUENCY                  400000U /* Frequency of I2Cn in Hz*/
#endif

/**
  * @}
  */

/** @addtogroup STM32H735G_DK_BUS_Private_Variables
  * @{
  */
extern I2C_HandleTypeDef hbus_i2c4;
/**
  * @}
  */

/** @defgroup STM32H735G_DK_BUS_Exported_FunctionsPrototypes Exported Functions Prototypes
  * @{
  */
int32_t BSP_I2C4_Init(void);
int32_t BSP_I2C4_DeInit(void);
int32_t BSP_I2C4_WriteReg(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C4_ReadReg(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C4_WriteReg16(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C4_ReadReg16(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C4_Recv(uint16_t DevAddr, uint16_t Reg, uint16_t MemAddSize, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C4_Send(uint16_t DevAddr, uint16_t Reg, uint16_t MemAddSize, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C4_IsReady(uint16_t DevAddr, uint32_t Trials);
int32_t BSP_GetTick(void);
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
int32_t BSP_I2C4_RegisterDefaultMspCallbacks (void);
int32_t BSP_I2C4_RegisterMspCallbacks (BSP_I2C_Cb_t *Callback);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
HAL_StatusTypeDef MX_I2C4_Init(I2C_HandleTypeDef *phi2c, uint32_t timing);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32H735G_DK_BUS_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
