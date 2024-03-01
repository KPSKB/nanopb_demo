#include <stdio.h>
#include "pb_encode.h"
#include "pb_decode.h"
#include "STM32_led.pb.h"

int main()
{
    /* This is the buffer where we will store our message. */
    uint8_t buffer[128];
    size_t message_length;
    bool status;

    /* Encode our message */
    {
        /* Allocate space on the stack to store the message data.
         *
         * Nanopb generates simple struct definitions for all the messages.
         * - check out the contents of simple.pb.h!
         * It is a good idea to always initialize your structures
         * so that you do not have garbage data from RAM in there.
         */
        ChangeLedStateMsg message = ChangeLedStateMsg_init_zero;

        /* Create a stream that will write to our buffer. */
        pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

        /* Fill in the lucky number */
        message.has_led_state = true;
        message.led_state = 1;

        /* Now we are ready to encode the message! */
        status = pb_encode(&stream, ChangeLedStateMsg_fields, &message);
        message_length = stream.bytes_written;

        //! My code
        printf("Size of buffer = %d\n", sizeof(buffer));

        for(int i = 0; i < message_length; i++)
        {
            printf("%d : %d\n", i, buffer[i]);
        }
        //! End of my code

        /* Then just check for any errors.. */
        if (!status)
        {
            printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }
    }

    /* Now we could transmit the message over network, store it in a file or
     * wrap it to a pigeon's leg.
     */

    /* But because we are lazy, we will just decode it immediately. */

    {
        /* Allocate space for the decoded message. */
        ChangeLedStateMsg message = ChangeLedStateMsg_init_zero;

        /* Create a stream that reads from the buffer. */
        pb_istream_t stream = pb_istream_from_buffer(buffer, message_length);

        /* Now we are ready to decode the message. */
        status = pb_decode(&stream, ChangeLedStateMsg_fields, &message);

        /* Check for errors... */
        if (!status)
        {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }

        /* Print the data contained in the message. */
        if(message.has_led_state == true)
        {
            printf("Change LED state to %d\n", (int)message.led_state);
        }
        else
        {
            printf("No LED state received");
        }

    }

    return 0;
}


