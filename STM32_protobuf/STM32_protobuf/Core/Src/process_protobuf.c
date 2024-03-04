/**
  ******************************************************************************
  * @file    process_protobuf.c
  * @author  Karpati Soma
  * @brief   This module provides interface to process protobuf messages. This
  * 		 includes decoding the message and executing commands based on the
  * 		 message. The module encapsulates the common and generated protobuf
  * 		 source files from nanopb.
  * 		 Current version can process commands to change the state of the
  * 		 green user led.
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/
#include "process_protobuf.h"

#include "pb_decode.h"
#include "STM32_led.pb.h"


/* Private variables ---------------------------------------------------------*/
static bool pbDecodeStatus;


/* Function definitions ------------------------------------------------------*/

/**
  * @brief 			Decode protobuf message and change the state of the green
  * 				user led accordingly.
  * @param buffer   Pointer to data buffer, which contains the coded message.
  * @retval 		If decoding protobuf was successful.
  */
bool processProtobufMsg( uint8_t *buffer )
{
	// Allocate space for the decoded message.
	ChangeLedStateMsg message = ChangeLedStateMsg_init_zero;

	//Create a stream that reads from the buffer.
	pb_istream_t stream = pb_istream_from_buffer(buffer, LED_STATE_MSG_LENGTH);

	//Now we are ready to decode the message.
	pbDecodeStatus = pb_decode(&stream, ChangeLedStateMsg_fields, &message);

	/* Change led state based on protobuf message. */
	if (message.has_led_state & pbDecodeStatus)
	{
		if (message.led_state == 1)
		{
			// Set green led.
			HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
		}
		else if (message.led_state == 0)
		{
			// Reset green led.
			HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
		}
	}

	return pbDecodeStatus;
}
