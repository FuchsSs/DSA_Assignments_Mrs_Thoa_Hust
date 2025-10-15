#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int size;
    int *Q;

} queue;

void initQueue(queue *q, int size)
{
    q->front = q->rear = -1;
    q->size = size;
    q->Q = (int *)malloc(sizeof(int) * q->size);
}

void enQueue(queue *q, int x)
{
    if (q->rear < q->size - 1)
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
    else
    {
        printf("Queue is full\n");
    }
}
int deQueue(queue *q)
{
    int x = -1;
    if (q->front != q->rear)
    {
        q->front++;
        x = q->Q[q->front];
    }
    else
    {
        printf("Queue is empty\n");
    }
    return x;
}

void display(queue *q)
{
    do
    {
        q->front++;
        printf("%d ", q->Q[q->front]);
    } while (q->front != q->rear);
}

int main()
{
    queue q;
    initQueue(&q, 5);
    enQueue(&q, 3);
    enQueue(&q, 4);
    enQueue(&q, 5);
    enQueue(&q, 6);
    enQueue(&q, 7);
    enQueue(&q, 8);
    enQueue(&q, 9);
    display(&q);
}