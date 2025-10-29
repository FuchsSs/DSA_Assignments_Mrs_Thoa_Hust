#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void merge(struct Node *q2_front, struct Node *q2_rear)
{
    if (q2_front == NULL)
        return;
    if (front == NULL)
    {
        front = q2_front;
        rear = q2_rear;
    }
    else
    {
        rear->next = q2_front;
        rear = q2_rear;
    }
}