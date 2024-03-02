/**
  ******************************************************************************
  * @file    process_protobuf.h
  * @author  Karpati Soma
  * @brief   Header file of process protobuf module.
  ******************************************************************************
**/

#ifndef INC_PROCESS_PROTOBUF_H_
#define INC_PROCESS_PROTOBUF_H_


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stdint.h"
#include "stdbool.h"


/* Public defines ------------------------------------------------------------*/
#define LED_STATE_MSG_LENGTH ( (size_t) 2 )

/* Public functions ----------------------------------------------------------*/
bool processProtobufMsg( uint8_t *buffer );


#endif /* INC_PROCESS_PROTOBUF_H_ */
