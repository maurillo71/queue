/**
* @file	        queue.c
* @brief        A simple FIFO circular queue implementation.
*
*
* @version      1
* @date	        18/09/2014
* @author       Mauro Gamba
* @note         Initial revision
*
***********************************************************************/
#include <stdint.h>
#include "queue.h"

//#define QUEUE_DIM(queue,queueDim)     ((queue.lastIdx>=queue.firstIdx)?(queue.lastIdx-queue.firstIdx):(queueDim-queue.lastIdx+queue.firstIdx-1))
#define QUEUE_DIM(queue,queueDim)     (queue.cnt)

static queue_t msgQueue;

void queue_init(void)
{
    msgQueue.firstIdx = 0;
    msgQueue.lastIdx = 0;
    msgQueue.cnt = 0;
}

void queue_add(uint8_t msgValue)
{
    msgQueue.queueArray[msgQueue.lastIdx++] = msgValue;
    if (msgQueue.lastIdx == SEND_MSG_QUEUE_DIM)
    {
        msgQueue.lastIdx = 0;
    }
    msgQueue.cnt++;
    /* Check if queue is full */
    if (msgQueue.cnt>SEND_MSG_QUEUE_DIM)
    {
        msgQueue.cnt = SEND_MSG_QUEUE_DIM;

        msgQueue.firstIdx++;
        if (msgQueue.firstIdx == SEND_MSG_QUEUE_DIM)
        {
            msgQueue.firstIdx = 0;
        }
    }
}

uint8_t queue_get(void)
{
    uint8_t msgToRet = 0;

    if (QUEUE_DIM(msgQueue, SEND_MSG_QUEUE_DIM)>0)
    {
        msgToRet = msgQueue.queueArray[msgQueue.firstIdx++];
        if (msgQueue.firstIdx == SEND_MSG_QUEUE_DIM)
        {
            msgQueue.firstIdx = 0;
        }
        msgQueue.cnt--;
    }
    return msgToRet;
}

uint8_t queue_is_empty(void)
{
    if (msgQueue.cnt>0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

