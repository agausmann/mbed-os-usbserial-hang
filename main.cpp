/* mbed Microcontroller Library
 * Copyright (c) 2023 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#include <usb/USBSerial.h>

// Any X divisible by 64 will time out reads by a Windows host
#define X 64

int main()
{
    USBSerial serial;

    uint8_t buf[X];
    memset(buf, 'A', X);
    buf[X - 1] = '\n';

    while (1) {
        // Wait until prompted by host
        while (!serial.receive(buf, 1)) {}

        serial.send(buf, X);

        // Sending data not divisible by 64 will fix the timeout on the host.
        // buf[0] = 'B';
        // serial.send(buf, 1);
    }
    return 0;
}
