/*****************************************************************************
* | File      	:   DEV_Config.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master
*                and enhance portability
*----------------
* |	This version:   V2.0
* | Date        :   2018-10-30
* | Info        :
# ******************************************************************************
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "DEV_Config.h"
extern cyhal_spi_t mSPI;
//extern SPI_HandleTypeDef hspi1;
void DEV_SPI_WriteByte(uint32_t value)
{

    cyhal_spi_send(&mSPI, value);
}

void DEV_SPI_Write_nByte(uint8_t *value, uint32_t len)
{
	uint8_t receive_data[len];
	cyhal_spi_transfer(&mSPI, value, len, receive_data, len, 0xFF);
}

int DEV_Module_Init(void)
{
	/*
    DEV_Digital_Write(EPD_DC_PIN, 0);
    DEV_Digital_Write(EPD_CS_PIN, 0);
	DEV_Digital_Write(EPD_PWR_PIN, 1);
    DEV_Digital_Write(EPD_RST_PIN, 1);
    */
    DEV_Digital_Write(EPD_DC_PIN, false);
    DEV_Digital_Write(EPD_CS_PIN, false);
	//DEV_Digital_Write(EPD_PWR_PIN, true);
    DEV_Digital_Write(EPD_RST_PIN, true);
	return false;
}

void DEV_Module_Exit(void)
{
    DEV_Digital_Write(EPD_DC_PIN, false);
    DEV_Digital_Write(EPD_CS_PIN, false);

    //close 5V
	//DEV_Digital_Write(EPD_PWR_PIN, false);
    DEV_Digital_Write(EPD_RST_PIN, false);
}

