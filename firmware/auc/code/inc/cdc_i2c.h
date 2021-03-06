/*
 * @brief Programming API used with CDC example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#ifndef __CDC_I2C_H_
#define __CDC_I2C_H_

#include "chip.h"
#include "lpcusbsio_i2c.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @ingroup EXAMPLES_USBDROM_11U14_CDC_GENERIC
 * @{
 */

#define CDC_I2C_TX_BUSY        _BIT(0)

#define CDC_I2C_STATE_INIT          0
#define CDC_I2C_STATE_DISCON        1
#define CDC_I2C_STATE_CONNECTED     2
#define CDC_I2C_STATE_NEEDRESET     3
#define CDC_I2C_STATE_UNKNOWN       4

#define CDC_I2C_EMPTY_TIME			400000
/**
 * @brief	CDC_I2C interface init routine.
 * @param	hUsb		: Handle to USB device stack
 * @param	pIntfDesc	: Pointer to CDC interface descriptor
 * @param	pUsbParam	: Pointer USB param structure returned by previous init call
 * @param	pI2C	    : Pointer to I2C port, this CDC instance needs to bind.
 * @param   pI2CCDC     : Pointer to CDC_I2C handle returned on success
 * @return	On success returns LPC_OK. Params mem_base and mem_size are updated
 *			to point to new base and available size.
 */
/*****************************************************************************
 * Public functions
 ****************************************************************************/
/* CDC init routine */
ErrorCode_t CDC_I2C_init(USBD_HANDLE_T hUsb,
		USB_CORE_DESCS_T* pDesc,
		USBD_API_INIT_PARAM_T* pUsbParam,
		LPC_I2C_T* pI2C,
		USBD_HANDLE_T* pI2CCDC);

/**
 * @brief	Process CDC_I2C request and response queue.
 * @param	hI2CCDC		: Handle to CDC_I2C instance
 */
void CDC_I2C_process(USBD_HANDLE_T hI2CCDC);

void CDC_I2C_SetState(USBD_HANDLE_T hI2CCDC, uint8_t state);
uint8_t CDC_I2C_GetState(USBD_HANDLE_T hI2CCDC);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __CDC_I2C_H_ */
