/*
 * dmd.h
 *
 *  Created on: 28 de mar de 2023
 *      Author: bjlli
 */

#ifndef INC_DMD_H_
#define INC_DMD_H_

#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdlib.h"
#include "Arial14.h"
#include "Arial_Black_16_ISO_8859_1.h"
#include "SystemFont5x7.h"


//display screen (and subscreen) sizing
#define DMD_PIXELS_ACROSS         32      //pixels across x axis (base 2 size expected)
#define DMD_PIXELS_DOWN           16      //pixels down y axis
#define DMD_BITSPERPIXEL           1      //1 bit per pixel, use more bits to allow for pwm screen brightness control
#define DMD_RAM_SIZE_BYTES        ((DMD_PIXELS_ACROSS*DMD_BITSPERPIXEL/8)*DMD_PIXELS_DOWN)

//Pixel/graphics writing modes (bGraphicsMode)
#define GRAPHICS_NORMAL    0
#define GRAPHICS_INVERSE   1
#define GRAPHICS_TOGGLE    2
#define GRAPHICS_OR        3
#define GRAPHICS_NOR       4

// Font Indices
#define FONT_LENGTH             0
#define FONT_FIXED_WIDTH        2
#define FONT_HEIGHT             3
#define FONT_FIRST_CHAR         4
#define FONT_CHAR_COUNT         5
#define FONT_WIDTH_TABLE        6


#define true       1
#define false      0


void setFont(const uint8_t *font_display);
void clearScreen(uint8_t bNormal);
void DMD(uint8_t panelsWide, uint8_t panelsHigh, GPIO_TypeDef* OE_PORT, uint16_t OE_PIN, GPIO_TypeDef* SCLK_PORT, uint16_t SCLK_PIN,
GPIO_TypeDef* A_PORT, uint16_t A_PIN, GPIO_TypeDef* B_PORT, uint16_t B_PIN);
void scanDisplayBySPI(SPI_HandleTypeDef *hspi);
void writePixel(unsigned int bX, unsigned int bY, uint8_t bGraphicsMode, uint8_t bPixel);
void drawLine(int x1, int y1, int x2, int y2, uint8_t bGraphicsMode);
void drawBox(int x1, int y1, int x2, int y2, uint8_t bGraphicsMode);
void drawFilledBox(int x1, int y1, int x2, int y2, uint8_t bGraphicsMode);
int drawChar(const int bX, const int bY, const unsigned char letter, uint8_t bGraphicsMode);
void drawString(int bX, int bY, const char *bChars, uint8_t length, uint8_t bGraphicsMode);
void drawMarquee(const char *bChars, uint8_t length, int left, int top);
int stepMarquee(int amountX, int amountY);
void drawCircle(int xCenter, int yCenter, int radius, uint8_t bGraphicsMode);
void drawCircleSub(int cx, int cy, int x, int y, uint8_t bGraphicsMode);

#endif /* INC_DMD_H_ */
