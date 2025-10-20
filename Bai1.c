#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Out of memory\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initLinkedList(Node **head, Node **tail)
{
    *head = NULL;
    *tail = NULL;
}

int checkEmptyList(Node **head)
{
    return (*head == NULL);
}

void insertBegin(Node **head, Node **tail, int val)
{
    Node *newNode = createNode(val);
    if (newNode == NULL)
        return;
    if (checkEmptyList(head))
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}

void insertEnd(Node **head, Node **tail, int val)
{
    Node *newNode = createNode(val);
    if (newNode == NULL)
        return;
    if (checkEmptyList(head))
    {
        *head = newNode;
        *tail = newNode;
        return;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void insertAfter(Node **head, Node **tail, Node *p, int val)
{
    if (checkEmptyList(head)) // Nếu p NULL thì vẫn chèn được khi trong List chưa có Elements
    {
        insertBegin(head, tail, val);
    }
    else
    {
        if (p == NULL)
        {

            printf("Can't insert after Null pointer\n");
        }
        else
        {
            Node *newNode = createNode(val);
            if (newNode == NULL)
            {
                return;
            }
            newNode->next = p->next;
            p->next = newNode;
            if (*tail == p)
            {
                *tail = newNode;
            }
        }
    }
}

void insertAfterVal(Node **head, Node **tail, int x, int val)
{
    Node *p = *head;

    while (p != NULL && p->data != x)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Can't find value %d to Insert after.\n", x);
    }
    else
    {
        insertAfter(head, tail, p, val);
    }
}

void insertBefore(Node **head, Node **tail, Node *p, int val)
{
    if (checkEmptyList(head)) // Nếu p NULL thì vẫn chèn được khi trong List chưa có Elements
    {
        insertBegin(head, tail, val);
    }
    else
    {
        if (p == NULL)
        {

            printf("Can't insert before Null pointer\n");
        }
        else
        {
            Node *newNode = createNode(val);
            if (newNode == NULL)
                return;
            if (p == *head)
            {
                insertBegin(head, tail, val);
            }
            else
            {
                Node *q = *head;
                while (q->next != p && q->next != NULL)
                {
                    q = q->next;
                }
                if (q->next == NULL)
                {
                    printf("Can't find position of pointer in the list \n");
                }
                else
                {
                    insertAfter(head, tail, q, val);
                }
            }
        }
    }
}

void insertBeforeVal(Node **head, Node **tail, int x, int val)
{

    if (checkEmptyList(head))
    {
        insertBegin(head, tail, val);
    }
    else
    {
        if ((*head)->data == x)
        {
            insertBegin(head, tail, val);
        }
        else
        {
            Node *p = *head;
            while (p->next->data != x && p->next != NULL)
            {
                p = p->next;
            }
            if (p->next == NULL)
            {
                printf("Can't find value %d in the list\n", x);
            }
            else
            {
                insertAfter(head, tail, p, val);
            }
        }
    }
}

void search(Node **head, int x)
{
    int index = 0;
    Node *p = *head;
    while (p != NULL)
    {
        if (p->data == x)
        {
            printf("%d is at the %d index.\n", x, index + 1);
            return;
        }
        index++;
        p = p->next;
    }
    printf("%d is not in the list.\n", x);
}

int count(Node **head)
{
    if (checkEmptyList(head))
    {
        return 0;
    }
    else
    {
        Node *p = *head;
        int nums = 0;
        while (p != NULL)
        {
            nums++;
            p = p->next;
        }
        return nums;
    }
}

double avarage(Node **head)
{
    int nums = 0;
    double sum = 0;
    if (checkEmptyList(head))
    {
        return 0;
    }
    else
    {
        Node *p = *head;
        while (p != NULL)
        {
            nums++;
            sum += p->data;
            p = p->next;
        }
        return sum / nums;
    }
}

void display(Node **head)
{

    if (checkEmptyList(head))
    {
        printf("List is empty\n");
    }
    else
    {
        Node *p = *head;
        printf("Elements in the list: ");
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    Node *head;
    Node *tail;

    initLinkedList(&head, &tail);

    insertBegin(&head, &tail, 10);
    insertBegin(&head, &tail, 20);
    insertBegin(&head, &tail, 30);

    Node *p = head;

    insertBefore(&head, &tail, p, 0);
    insertBeforeVal(&head, &tail, 20, 0);

    insertAfterVal(&head, &tail, 10, 100);

    insertEnd(&head, &tail, 69);

    display(&head);
    search(&head, 30);
    printf("Number of elements in the list: %d\n", count(&head));
    printf("Avarage of elements in the list: %.2lf\n", avarage(&head));
    return 0;
}