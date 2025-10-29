#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void swap(struct Node *a, struct Node *b)
{
    int tmp = 0;
    tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

void SortGreater_LinkedList()
{
    struct Node *p1, *p2;
    for (p1 = front; p1 != NULL; p1 = p1->next)
    {
        for (p2 = p1->next; p2 != NULL; p2 = p2->next)
        {
            if (p2->data < p1->data)
            {
                swap(p2, p1);
            }
        }
    }
}
