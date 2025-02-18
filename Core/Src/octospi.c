/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    octospi.c
  * @brief   This file provides code for the configuration
  *          of the OCTOSPI instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "octospi.h"

/* USER CODE BEGIN 0 */
#include "stm32h735g_discovery_ospi.h"
#include "stm32h7xx_hal_ospi.h"
/* USER CODE END 0 */

OSPI_HandleTypeDef hospi1;
OSPI_HandleTypeDef hospi2;

/* OCTOSPI1 init function */
void MX_OCTOSPI1_Init(void)
{

  /* USER CODE BEGIN OCTOSPI1_Init 0 */
	  BSP_OSPI_NOR_Init_t ospi_nor_int;
  /* USER CODE END OCTOSPI1_Init 0 */

  OSPIM_CfgTypeDef sOspiManagerCfg = {0};

  /* USER CODE BEGIN OCTOSPI1_Init 1 */

  /* USER CODE END OCTOSPI1_Init 1 */
  hospi1.Instance = OCTOSPI1;
  hospi1.Init.FifoThreshold = 4;
  hospi1.Init.DualQuad = HAL_OSPI_DUALQUAD_DISABLE;
  hospi1.Init.MemoryType = HAL_OSPI_MEMTYPE_MACRONIX;
  hospi1.Init.DeviceSize = 32;
  hospi1.Init.ChipSelectHighTime = 2;
  hospi1.Init.FreeRunningClock = HAL_OSPI_FREERUNCLK_DISABLE;
  hospi1.Init.ClockMode = HAL_OSPI_CLOCK_MODE_0;
  hospi1.Init.WrapSize = HAL_OSPI_WRAP_NOT_SUPPORTED;
  hospi1.Init.ClockPrescaler = 2;
  hospi1.Init.SampleShifting = HAL_OSPI_SAMPLE_SHIFTING_NONE;
  hospi1.Init.DelayHoldQuarterCycle = HAL_OSPI_DHQC_DISABLE;
  hospi1.Init.ChipSelectBoundary = 0;
  hospi1.Init.DelayBlockBypass = HAL_OSPI_DELAY_BLOCK_BYPASSED;
  hospi1.Init.MaxTran = 0;
  hospi1.Init.Refresh = 0;
  if (HAL_OSPI_Init(&hospi1) != HAL_OK)
  {
    Error_Handler();
  }
  sOspiManagerCfg.ClkPort = 1;
  sOspiManagerCfg.DQSPort = 1;
  sOspiManagerCfg.NCSPort = 1;
  sOspiManagerCfg.IOLowPort = HAL_OSPIM_IOPORT_1_LOW;
  sOspiManagerCfg.IOHighPort = HAL_OSPIM_IOPORT_1_HIGH;
  if (HAL_OSPIM_Config(&hospi1, &sOspiManagerCfg, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN OCTOSPI1_Init 2 */
  HAL_OSPI_DeInit(&hospi1);
  ospi_nor_int.InterfaceMode = BSP_OSPI_NOR_OPI_MODE;
  ospi_nor_int.TransferRate  = BSP_OSPI_NOR_DTR_TRANSFER;
  BSP_OSPI_NOR_DeInit(0);
  if(BSP_OSPI_NOR_Init(0, &ospi_nor_int) != BSP_ERROR_NONE)
  {
    Error_Handler();
  }
  if(BSP_OSPI_NOR_EnableMemoryMappedMode(0) != BSP_ERROR_NONE)
  {
    Error_Handler();
  }
  /* USER CODE END OCTOSPI1_Init 2 */

}
/* OCTOSPI2 init function */
void MX_OCTOSPI2_Init(void)
{

  /* USER CODE BEGIN OCTOSPI2_Init 0 */
	 BSP_OSPI_RAM_Init_t ospi_ram_init;
  /* USER CODE END OCTOSPI2_Init 0 */

  OSPIM_CfgTypeDef sOspiManagerCfg = {0};
  OSPI_HyperbusCfgTypeDef sHyperBusCfg = {0};

  /* USER CODE BEGIN OCTOSPI2_Init 1 */
  OSPI_HyperbusCmdTypeDef sCommand = {0};
  OSPI_MemoryMappedTypeDef sMemMappedCfg = {0};
  /* USER CODE END OCTOSPI2_Init 1 */
  hospi2.Instance = OCTOSPI2;
  hospi2.Init.FifoThreshold = 4;
  hospi2.Init.DualQuad = HAL_OSPI_DUALQUAD_DISABLE;
  hospi2.Init.MemoryType = HAL_OSPI_MEMTYPE_HYPERBUS;
  hospi2.Init.DeviceSize = 24;
  hospi2.Init.ChipSelectHighTime = 4;
  hospi2.Init.FreeRunningClock = HAL_OSPI_FREERUNCLK_DISABLE;
  hospi2.Init.ClockMode = HAL_OSPI_CLOCK_MODE_0;
  hospi2.Init.WrapSize = HAL_OSPI_WRAP_NOT_SUPPORTED;
  hospi2.Init.ClockPrescaler = 2;
  hospi2.Init.SampleShifting = HAL_OSPI_SAMPLE_SHIFTING_NONE;
  hospi2.Init.DelayHoldQuarterCycle = HAL_OSPI_DHQC_ENABLE;
  hospi2.Init.ChipSelectBoundary = 23;
  hospi2.Init.DelayBlockBypass = HAL_OSPI_DELAY_BLOCK_USED;
  hospi2.Init.MaxTran = 0;
  hospi2.Init.Refresh = 400;
  if (HAL_OSPI_Init(&hospi2) != HAL_OK)
  {
    Error_Handler();
  }
  sOspiManagerCfg.ClkPort = 2;
  sOspiManagerCfg.DQSPort = 2;
  sOspiManagerCfg.NCSPort = 2;
  sOspiManagerCfg.IOLowPort = HAL_OSPIM_IOPORT_2_LOW;
  sOspiManagerCfg.IOHighPort = HAL_OSPIM_IOPORT_2_HIGH;
  if (HAL_OSPIM_Config(&hospi2, &sOspiManagerCfg, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }
  sHyperBusCfg.RWRecoveryTime = 3;
  sHyperBusCfg.AccessTime = 6;
  sHyperBusCfg.WriteZeroLatency = HAL_OSPI_LATENCY_ON_WRITE;
  sHyperBusCfg.LatencyMode = HAL_OSPI_FIXED_LATENCY;
  if (HAL_OSPI_HyperbusCfg(&hospi2, &sHyperBusCfg, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN OCTOSPI2_Init 2 */
  sCommand.AddressSpace = HAL_OSPI_MEMORY_ADDRESS_SPACE;
   sCommand.AddressSize  = HAL_OSPI_ADDRESS_32_BITS;
   sCommand.DQSMode      = HAL_OSPI_DQS_ENABLE;
   sCommand.Address      = 0;
   sCommand.NbData       = 1;

   if (HAL_OSPI_HyperbusCmd(&hospi2, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
     Error_Handler();
   }

   sMemMappedCfg.TimeOutActivation = HAL_OSPI_TIMEOUT_COUNTER_DISABLE;

   if (HAL_OSPI_MemoryMapped(&hospi2, &sMemMappedCfg) != HAL_OK)
   {
     Error_Handler();
   }
  /* USER CODE END OCTOSPI2_Init 2 */

}

static uint32_t HAL_RCC_OCTOSPIM_CLK_ENABLED=0;

void HAL_OSPI_MspInit(OSPI_HandleTypeDef* ospiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(ospiHandle->Instance==OCTOSPI1)
  {
  /* USER CODE BEGIN OCTOSPI1_MspInit 0 */

  /* USER CODE END OCTOSPI1_MspInit 0 */
    /* OCTOSPI1 clock enable */
    HAL_RCC_OCTOSPIM_CLK_ENABLED++;
    if(HAL_RCC_OCTOSPIM_CLK_ENABLED==1){
      __HAL_RCC_OCTOSPIM_CLK_ENABLE();
    }
    __HAL_RCC_OSPI1_CLK_ENABLE();

    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**OCTOSPI1 GPIO Configuration
    PG9     ------> OCTOSPIM_P1_IO6
    PD7     ------> OCTOSPIM_P1_IO7
    PD5     ------> OCTOSPIM_P1_IO5
    PE2     ------> OCTOSPIM_P1_IO2
    PD4     ------> OCTOSPIM_P1_IO4
    PG6     ------> OCTOSPIM_P1_NCS
    PD13     ------> OCTOSPIM_P1_IO3
    PD11     ------> OCTOSPIM_P1_IO0
    PD12     ------> OCTOSPIM_P1_IO1
    PF10     ------> OCTOSPIM_P1_CLK
    PB2     ------> OCTOSPIM_P1_DQS
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_5|GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_11|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN OCTOSPI1_MspInit 1 */

  /* USER CODE END OCTOSPI1_MspInit 1 */
  }
  else if(ospiHandle->Instance==OCTOSPI2)
  {
  /* USER CODE BEGIN OCTOSPI2_MspInit 0 */

  /* USER CODE END OCTOSPI2_MspInit 0 */
    /* OCTOSPI2 clock enable */
    HAL_RCC_OCTOSPIM_CLK_ENABLED++;
    if(HAL_RCC_OCTOSPIM_CLK_ENABLED==1){
      __HAL_RCC_OCTOSPIM_CLK_ENABLE();
    }
    __HAL_RCC_OSPI2_CLK_ENABLE();

    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    /**OCTOSPI2 GPIO Configuration
    PG11     ------> OCTOSPIM_P2_IO7
    PG10     ------> OCTOSPIM_P2_IO6
    PG12     ------> OCTOSPIM_P2_NCS
    PF1     ------> OCTOSPIM_P2_IO1
    PF0     ------> OCTOSPIM_P2_IO0
    PF2     ------> OCTOSPIM_P2_IO2
    PF4     ------> OCTOSPIM_P2_CLK
    PF3     ------> OCTOSPIM_P2_IO3
    PG1     ------> OCTOSPIM_P2_IO5
    PG0     ------> OCTOSPIM_P2_IO4
    PF12     ------> OCTOSPIM_P2_DQS
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_1|GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P2;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF3_OCTOSPIM_P2;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_4
                          |GPIO_PIN_3|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P2;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /* USER CODE BEGIN OCTOSPI2_MspInit 1 */

  /* USER CODE END OCTOSPI2_MspInit 1 */
  }
}

void HAL_OSPI_MspDeInit(OSPI_HandleTypeDef* ospiHandle)
{

  if(ospiHandle->Instance==OCTOSPI1)
  {
  /* USER CODE BEGIN OCTOSPI1_MspDeInit 0 */

  /* USER CODE END OCTOSPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    HAL_RCC_OCTOSPIM_CLK_ENABLED--;
    if(HAL_RCC_OCTOSPIM_CLK_ENABLED==0){
      __HAL_RCC_OCTOSPIM_CLK_DISABLE();
    }
    __HAL_RCC_OSPI1_CLK_DISABLE();

    /**OCTOSPI1 GPIO Configuration
    PG9     ------> OCTOSPIM_P1_IO6
    PD7     ------> OCTOSPIM_P1_IO7
    PD5     ------> OCTOSPIM_P1_IO5
    PE2     ------> OCTOSPIM_P1_IO2
    PD4     ------> OCTOSPIM_P1_IO4
    PG6     ------> OCTOSPIM_P1_NCS
    PD13     ------> OCTOSPIM_P1_IO3
    PD11     ------> OCTOSPIM_P1_IO0
    PD12     ------> OCTOSPIM_P1_IO1
    PF10     ------> OCTOSPIM_P1_CLK
    PB2     ------> OCTOSPIM_P1_DQS
    */
    HAL_GPIO_DeInit(GPIOG, GPIO_PIN_9|GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_7|GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_13
                          |GPIO_PIN_11|GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_2);

    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_10);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_2);

  /* USER CODE BEGIN OCTOSPI1_MspDeInit 1 */

  /* USER CODE END OCTOSPI1_MspDeInit 1 */
  }
  else if(ospiHandle->Instance==OCTOSPI2)
  {
  /* USER CODE BEGIN OCTOSPI2_MspDeInit 0 */

  /* USER CODE END OCTOSPI2_MspDeInit 0 */
    /* Peripheral clock disable */
    HAL_RCC_OCTOSPIM_CLK_ENABLED--;
    if(HAL_RCC_OCTOSPIM_CLK_ENABLED==0){
      __HAL_RCC_OCTOSPIM_CLK_DISABLE();
    }
    __HAL_RCC_OSPI2_CLK_DISABLE();

    /**OCTOSPI2 GPIO Configuration
    PG11     ------> OCTOSPIM_P2_IO7
    PG10     ------> OCTOSPIM_P2_IO6
    PG12     ------> OCTOSPIM_P2_NCS
    PF1     ------> OCTOSPIM_P2_IO1
    PF0     ------> OCTOSPIM_P2_IO0
    PF2     ------> OCTOSPIM_P2_IO2
    PF4     ------> OCTOSPIM_P2_CLK
    PF3     ------> OCTOSPIM_P2_IO3
    PG1     ------> OCTOSPIM_P2_IO5
    PG0     ------> OCTOSPIM_P2_IO4
    PF12     ------> OCTOSPIM_P2_DQS
    */
    HAL_GPIO_DeInit(GPIOG, GPIO_PIN_11|GPIO_PIN_10|GPIO_PIN_12|GPIO_PIN_1
                          |GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_1|GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_4
                          |GPIO_PIN_3|GPIO_PIN_12);

  /* USER CODE BEGIN OCTOSPI2_MspDeInit 1 */

  /* USER CODE END OCTOSPI2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
