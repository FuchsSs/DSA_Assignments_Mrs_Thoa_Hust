#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void merge(struct Node *q2_front, struct Node *q2_rear, int index)
{

    if (q2_front == NULL)
        return;
    struct Node *t = q2_front;
    for (int i = 0; i < index; i++)
    {
        if (t == NULL)
        {
            printf("Index is out of range\n");
            return;
        }
        t = t->next;
    }
    if (front == NULL)
    {

        front = t;
        rear = q2_rear;
    }
    else
    {
        rear->next = t;
        rear = q2_rear;
    }
}