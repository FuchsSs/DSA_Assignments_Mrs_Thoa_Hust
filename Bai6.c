#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void reverse()
{
    struct Node *p, *q;
    if (front == NULL && front->next == NULL)
        return;
    else
    {
        struct Node *prevNode = NULL;
        struct Node *currNode = front;
        struct Node *nextNode = NULL;

        rear = front;

        while (currNode != NULL)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
        }
        front = prevNode;
    }
}