/**
  ******************************************************************************
  * File Name          : mxconstants.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MXCONSTANT_H
#define __MXCONSTANT_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define RL14_Pin GPIO_PIN_2
#define RL14_GPIO_Port GPIOE
#define RL15_Pin GPIO_PIN_3
#define RL15_GPIO_Port GPIOE
#define RL16_Pin GPIO_PIN_4
#define RL16_GPIO_Port GPIOE
#define RL17_Pin GPIO_PIN_5
#define RL17_GPIO_Port GPIOE
#define RL18_Pin GPIO_PIN_6
#define RL18_GPIO_Port GPIOE
#define RL19_Pin GPIO_PIN_13
#define RL19_GPIO_Port GPIOC
#define RL20_Pin GPIO_PIN_2
#define RL20_GPIO_Port GPIOC
#define I2C_SCL3_Pin GPIO_PIN_3
#define I2C_SCL3_GPIO_Port GPIOC
#define I2C_SDA3_Pin GPIO_PIN_0
#define I2C_SDA3_GPIO_Port GPIOA
#define RL1_Pin GPIO_PIN_3
#define RL1_GPIO_Port GPIOA
#define RL2_Pin GPIO_PIN_4
#define RL2_GPIO_Port GPIOA
#define RL3_Pin GPIO_PIN_5
#define RL3_GPIO_Port GPIOA
#define RL4_Pin GPIO_PIN_6
#define RL4_GPIO_Port GPIOA
#define RL5_Pin GPIO_PIN_0
#define RL5_GPIO_Port GPIOB
#define RL6_Pin GPIO_PIN_1
#define RL6_GPIO_Port GPIOB
#define RL7_Pin GPIO_PIN_7
#define RL7_GPIO_Port GPIOE
#define RL8_Pin GPIO_PIN_8
#define RL8_GPIO_Port GPIOE
#define KEY_1_Pin GPIO_PIN_9
#define KEY_1_GPIO_Port GPIOE
#define KEY_20_Pin GPIO_PIN_10
#define KEY_20_GPIO_Port GPIOE
#define KEY_2_Pin GPIO_PIN_11
#define KEY_2_GPIO_Port GPIOE
#define KEY_19_Pin GPIO_PIN_12
#define KEY_19_GPIO_Port GPIOE
#define KEY_3_Pin GPIO_PIN_13
#define KEY_3_GPIO_Port GPIOE
#define KEY_18_Pin GPIO_PIN_14
#define KEY_18_GPIO_Port GPIOE
#define KEY_4_Pin GPIO_PIN_15
#define KEY_4_GPIO_Port GPIOE
#define KEY_17_Pin GPIO_PIN_10
#define KEY_17_GPIO_Port GPIOB
#define KEY_5_Pin GPIO_PIN_14
#define KEY_5_GPIO_Port GPIOB
#define KEY_16_Pin GPIO_PIN_15
#define KEY_16_GPIO_Port GPIOB
#define KEY_6_Pin GPIO_PIN_10
#define KEY_6_GPIO_Port GPIOD
#define KEY_15_Pin GPIO_PIN_11
#define KEY_15_GPIO_Port GPIOD
#define KEY_7_Pin GPIO_PIN_12
#define KEY_7_GPIO_Port GPIOD
#define KEY_14_Pin GPIO_PIN_13
#define KEY_14_GPIO_Port GPIOD
#define KEY_8_Pin GPIO_PIN_14
#define KEY_8_GPIO_Port GPIOD
#define KEY_13_Pin GPIO_PIN_15
#define KEY_13_GPIO_Port GPIOD
#define KEY_21_Pin GPIO_PIN_6
#define KEY_21_GPIO_Port GPIOC
#define KEY_12_Pin GPIO_PIN_7
#define KEY_12_GPIO_Port GPIOC
#define KEY_22_Pin GPIO_PIN_8
#define KEY_22_GPIO_Port GPIOC
#define KEY_11_Pin GPIO_PIN_9
#define KEY_11_GPIO_Port GPIOC
#define KEY_23_Pin GPIO_PIN_8
#define KEY_23_GPIO_Port GPIOA
#define KEY_10_Pin GPIO_PIN_11
#define KEY_10_GPIO_Port GPIOA
#define KEY_9_Pin GPIO_PIN_12
#define KEY_9_GPIO_Port GPIOA
#define POWER_INT_2_Pin GPIO_PIN_15
#define POWER_INT_2_GPIO_Port GPIOA
#define RS485_ENABLE_1_Pin GPIO_PIN_0
#define RS485_ENABLE_1_GPIO_Port GPIOD
#define RS458_ENABLE_2_Pin GPIO_PIN_1
#define RS458_ENABLE_2_GPIO_Port GPIOD
#define POWER_INI_1_Pin GPIO_PIN_3
#define POWER_INI_1_GPIO_Port GPIOD
#define POWER_INT_3_Pin GPIO_PIN_4
#define POWER_INT_3_GPIO_Port GPIOD
#define SPK_Pin GPIO_PIN_5
#define SPK_GPIO_Port GPIOD
#define RL9_Pin GPIO_PIN_6
#define RL9_GPIO_Port GPIOD
#define RL10_Pin GPIO_PIN_7
#define RL10_GPIO_Port GPIOD
#define RL11_Pin GPIO_PIN_3
#define RL11_GPIO_Port GPIOB
#define I2C_SCL2_Pin GPIO_PIN_4
#define I2C_SCL2_GPIO_Port GPIOB
#define I2C_SDA2_Pin GPIO_PIN_5
#define I2C_SDA2_GPIO_Port GPIOB
#define I2C_SCL1_Pin GPIO_PIN_6
#define I2C_SCL1_GPIO_Port GPIOB
#define I2C_SDA1_Pin GPIO_PIN_7
#define I2C_SDA1_GPIO_Port GPIOB
#define RL12_Pin GPIO_PIN_8
#define RL12_GPIO_Port GPIOB
#define RL13_Pin GPIO_PIN_9
#define RL13_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MXCONSTANT_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
