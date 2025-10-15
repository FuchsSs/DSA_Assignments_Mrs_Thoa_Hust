#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file
{
    char name[100];
    int pages;
} file;

typedef struct queue
{
    int front;
    int rear;
    int size;
    file *Q;

} queue;

void initQueue(queue *q, int size)
{
    q->front = q->rear = -1;
    q->size = size;
    q->Q = (file *)malloc(sizeof(file) * q->size);
}

void enQueue(queue *q, file x)
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
file deQueue(queue *q)
{
    file x = {"\0", 0};
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
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    int i = q->front + 1;
    while (i <= q->rear)
    {
        printf("%s %d\n", q->Q[i].name, q->Q[i].pages);
        i++;
    }
}

int main()
{
    queue q;
    initQueue(&q, 3);
    file A = {"A", 3};
    file B = {"B", 4};
    file C = {"C", 10};
    enQueue(&q, A);
    enQueue(&q, C);
    enQueue(&q, B);
    display(&q);
}