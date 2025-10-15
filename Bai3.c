#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int val;
    int prio;
} Element;

typedef struct Queue
{
    int size;
    Element *Q;
    int rear;
} Queue;

void initQueue(Queue *q, int size)
{
    q->rear = -1;
    q->size = size;
    q->Q = (Element *)malloc(sizeof(Element) * q->size);
}

void enQueue(Queue *q, int val, int p)
{
    if (q->rear < q->size - 1)
    {
        int x = ++q->rear;
        while (x > 0 && q->Q[x - 1].prio >= p)
        {
            q->Q[x] = q->Q[x - 1];
            x--;
        }
        q->Q[x].val = val;
        q->Q[x].prio = p;
    }
    else
    {
        printf("Queue is full\n");
    }
}

Element deQueue(Queue *q)
{
    Element e = q->Q[0];
    if (q->rear < 0)
    {
        printf("Empty Queue\n");
    }
    else
    {
        e.prio = q->Q[q->rear].prio;
        e.val = q->Q[q->rear].val;
        q->rear--;
    }
    return e;
}

void display(Queue *q)
{
    if (q->rear < 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Value:    ");
        for (int i = 0; i <= q->rear; i++)
        {
            printf("%d ", q->Q[i].val);
        }
        printf("\nPriority: ");
        for (int i = 0; i <= q->rear; i++)
        {
            printf("%d ", q->Q[i].prio);
        }
    }
}
int main()
{
    Queue q;
    initQueue(&q, 3);
    enQueue(&q, 3, 1);
    enQueue(&q, 4, 5);
    enQueue(&q, 5, 3);

    Element tmp = deQueue(&q);

    printf("Dequeue: %d %d\n", tmp.val, tmp.prio);
    display(&q);
}