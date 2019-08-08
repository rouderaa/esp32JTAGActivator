#include <Arduino.h>

/*
Copyright 2019 Rob van der Ouderaa (rouderaa@hccnet.nl)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation 
files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, 
modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom 
the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

By running this sketch it is possible to set the esp32 JTAG pads 12,13,14
and 15 to be active for JTAG source level debugging, for example with
the debugger in platformio (http://platformio.org) .
Make sure these pins are not used or attached to other sources than the
JTAG debugger in your system by examining the schematic specific for your ESP32 based system.
Attach the JTAG debugger ARM-USB-OCD-H for the Adafruit esp32 Feather
like this
(the pin 1 is indicated on the connector by a little triangle):

Adafruit ESP32 Feather |  ARM-USB-OCD-H
----------------------------------------
RST                       pin 3
3V                        pin 1 and 2
GND                       pin 20
13/A12                    pin 11
12/A11                    pin 5
15/A8                     pin 13
14/A6                     pin 7

Note 1 : Remove the red LED from the board since it is attached to one of
the lines used by the  JTAG port.

NOTE 2 : Also attach the USB cable to the USB port of the PC.
It is used to show the Serial port data in your program along with your debugger.
(You can connect the program Putty to it for example)
 */

#include "soc/io_mux_reg.h"

void setup() {
    // activate the JTAG signals of the esp32 to their pads 12,13,14 and 15
    // You only have to run this once
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, FUNC_MTDI_MTDI);
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, FUNC_MTCK_MTCK);
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U, FUNC_MTMS_MTMS);      
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, FUNC_MTDO_MTDO);
}

void loop() {
}
