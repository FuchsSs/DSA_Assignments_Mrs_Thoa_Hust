#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int *Q;

} Queue;

void initQueue(Queue *q, int size)
{
    q->front = q->rear = 0;
    q->size = size + 1;                          // Cần thêm 1 ô đệm để làm dấu hiệu nhận biết queue có full không
    q->Q = (int *)malloc(sizeof(int) * q->size); // q->size không phải size
}

void enQueue(Queue *q, int x)
{
    if ((q->rear + 1) % (q->size) == q->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % (q->size);
        q->Q[q->rear] = x;
    }
}

int deQueue(Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(Queue *q)
{
    int i = (q->front + 1) % q->size; // q->front là con trỏ ở ô trước, ô có front đã bị thao tác; q->rear thì sẽ thao tác trực tiếp với ô
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while (i != (q->rear + 1) % q->size) // q->rear + 1 để in ra cả giá trị ở vị trí q->rear
        {
            printf("%d ", q->Q[i]);
            i = (i + 1) % q->size;
        }
    }
}
int main()
{
    Queue q;
    initQueue(&q, 3);
    enQueue(&q, 3);
    enQueue(&q, 4);
    enQueue(&q, 5);
    deQueue(&q);
    enQueue(&q, 6);
    display(&q);
}