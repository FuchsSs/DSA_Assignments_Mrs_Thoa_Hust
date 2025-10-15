#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Khach
{
    char name[100];
    int stt;
} Khach;

typedef struct CirQueue
{
    int front;
    int rear;
    int size;
    char **Q;
} CirQueue;

void initQueue(CirQueue *q, int size)
{
    q->front = q->rear = 0;
    q->size = size + 1;
    q->Q = (char **)malloc(sizeof(char **) * q->size);
}

void enQueue(CirQueue *q, char *A)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = A;
        printf("Khach %s den cua hang\n", A);
    }
}

char *deQueue(CirQueue *q)
{
    char *x = "\0";
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
        printf("Da phuc vu khach: %s\n", x);
    }
    return x;
}

void display(CirQueue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    int i = (q->front + 1) % q->size;
    printf("Danh sach cac khach dang cho: ");
    while (i != (q->rear + 1) % q->size)
    {
        printf("%s ", q->Q[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main()
{
    CirQueue q;
    initQueue(&q, 3);
    enQueue(&q, "A");
    enQueue(&q, "B");
    enQueue(&q, "C");

    display(&q);
    deQueue(&q);

    enQueue(&q, "D");
    display(&q);

    deQueue(&q);
    return 0;
}