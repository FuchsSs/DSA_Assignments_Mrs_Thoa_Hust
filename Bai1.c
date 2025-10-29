#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
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
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
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

        // Trường hợp xóa phần tử duy nhất thì rear phải trỏ về NULL.
        if (front == NULL)
        {
            rear = NULL;
        }
        free(t);
    }

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
        do
        {
            printf("%d ", t->data);
            t = t->next;

        } while (t != NULL);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display_queue();

    dequeue();

    display_queue();
}