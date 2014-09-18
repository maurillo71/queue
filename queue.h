/**
* @file	        queue.h
* @brief        A simple FIFO circular queue implementation.
*
*
* @version      1
* @date	        18/09/2014
* @author       Mauro Gamba
* @note         Initial revision
*
***********************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

#define SEND_MSG_QUEUE_DIM          5

typedef struct
{
    uint8_t queueArray[SEND_MSG_QUEUE_DIM];
    uint8_t firstIdx;
    uint8_t lastIdx;
    uint8_t cnt;
} queue_t;

/**
 * void queue_init(void)
 * @brief Initialize queue.
 */
void queue_init(void);

/**
 * @fn void queue_add(uint8_t msgValue)
 * @brief Add a value to the queue.
 * @param msgValue The value to add to the queue.
 */
void queue_add(uint8_t msgValue);

/**
 * @fn uint8_t comm_queue_get(void)
 * @brief Get the first value from the queue.
 * @return The first value on the queue or 0 if the queue is empty.
 */
uint8_t queue_get(void);

/**
 * @fn uint8_t comm_queue_empty(void)
 * @brief Check if the queue is empty.
 * @return 1 if the queue is empty, 0 otherwise.
 */
uint8_t queue_is_empty(void);

#endif // QUEUE_H
