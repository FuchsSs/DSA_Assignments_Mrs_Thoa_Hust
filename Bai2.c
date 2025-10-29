#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
} *front = NULL;

void enqueue(int x, int priority)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        t->data = x;
        t->priority = priority;
        t->next = NULL;
        struct Node *tmp = front;
        if (front == NULL || priority < front->priority)
        {
            t->next = front;
            front = t;
        }
        else
        {
            while ((tmp->next != NULL) && (tmp->next->priority <= priority))
            {
                tmp = tmp->next;
            }
            t->next = tmp->next;
            tmp->next = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
    }
    free(t);
    return x;
}

void display_queue()
{
    struct Node *t = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while (t != NULL)
        {
            printf("Data: %d | Priority: %d\n", t->data, t->priority);
            t = t->next;
        }
    }
    printf("\n");
}

int main()
{
    enqueue(10, 1);
    enqueue(20, 2);

    enqueue(40, 10);
    enqueue(50, 4);

    dequeue();
    display_queue();
}