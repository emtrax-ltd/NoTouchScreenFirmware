#ifndef _PIN_TFT35_V3_0_H_ // modify to actual filename !!!
#define _PIN_TFT35_V3_0_H_ // modify to actual filename !!!

//MCU type (STM32F10x, STM32F2xx)
#include "stm32f2xx.h"

// LCD resolution, font and icon size
#ifndef TFT_RESOLUTION
  #define TFT_RESOLUTION
  #include "./Resolution/TFT_480X320.h"
#endif

// LCD interface
#ifndef TFTLCD_DRIVER
  #define TFTLCD_DRIVER ILI9488  // Type of LCD driver, now support[ILI9488, ILI9341, ST7789, HX8558].
  #define TFTLCD_DRIVER_SPEED         0x03
  #define TFTLCD_0_DEGREE_REG_VALUE   0X28
  #define TFTLCD_180_DEGREE_REG_VALUE 0XE8
#endif
#define STM32_HAS_FSMC // FSMC 8080 interface(high speed), or normal IO interface(low speed)
#ifndef LCD_DATA_16BIT
  #define LCD_DATA_16BIT 1 // LCD data 16bit or 8bit
#endif

// LCD Backlight pin (PWM can adjust brightness)
#define LCD_LED_PIN            PD12
#define LCD_LED_PIN_ALTERNATE  GPIO_AF_TIM4
#define LCD_LED_PWM_CHANNEL    _TIM4_CH1
#define LCD_LED_PWM_BRIGHTNESS 100

// SD Card SPI pins
#define SD_SPI_SUPPORT
#ifdef SD_SPI_SUPPORT
  #define SD_LOW_SPEED  7 // 2^(SPEED+1) = 256 frequency division
  #define SD_HIGH_SPEED 0 // 2 frequency division
  #define SD_SPI        _SPI1
  #define SD_CS_PIN     PA4
#endif

// SD Card CD detect pin
#define SD_CD_PIN     PC4

// ST7920 Simulator SPI pins
#define ST7920_SPI    _SPI2

#endif
