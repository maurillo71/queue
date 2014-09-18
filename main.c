#include <stdio.h>
#include <stdint.h>

#include "queue.h"



int main(void)
{
    uint8_t msg;

    queue_init();

    queue_add(1);

    queue_add(2);

    queue_add(3);

    queue_add(4);

    queue_add(5);

    queue_add(6);

    queue_add(7);

    msg = queue_get();
    printf("Get %d\n", msg);

    msg = queue_get();
    printf("Get %d\n", msg);

    msg = queue_get();
    printf("Get %d\n", msg);

    msg = queue_get();
    printf("Get %d\n", msg);

    msg = queue_get();
    printf("Get %d\n", msg);

    msg = queue_get();
    printf("Get %d\n", msg);

    msg = queue_get();
    printf("Get %d\n", msg);

    printf("Hello World!\n");
    return 0;
}

