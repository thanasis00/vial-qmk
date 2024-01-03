// Copyright 2022 Conor Burns (@Conor-Burns)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// #define SERIAL_USART_TX_PIN GP0
// #define USB_VBUS_PIN GP19
#define SELECT_SOFT_SERIAL_SPEED 0
#define SERIAL_PIO_USE_PIO0
// #define MASTER_LEFT
#define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 5000
#define WS2812_PIO_USE_PIO1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led which blinks when entering the bootloader

#define SERIAL_DEBUG
#define TAPPING_TERM 300
//RDY = GP20
//RST = GP23
//SDA = GP2
//SCL = GP3
#define ZOOM_ENABLED            FALSE
#define SCROLL_ENABLED          TRUE
/* #define SPLIT_POINTING_ENABLE */
/* #define POINTING_DEVICE_RIGHT */

#define IQS5xx_ADDR          	0x74
#define MOUSEKEY_INTERVAL           8
#define MOUSEKEY_DELAY              0
#define MOUSEKEY_TIME_TO_MAX        60
#define MOUSEKEY_MAX_SPEED          6
#define MOUSEKEY_WHEEL_DELAY        400
#define MOUSEWHEEL_SENSITIVITY      1
#define TRACKPAD_RATE       10
#define	END_WINDOW				(uint16_t)0xEEEE

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3