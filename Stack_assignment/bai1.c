#include <stdio.h>
#include <stdlib.h>
// cai dat stack luu tru
#define MAX 100
typedef struct Stack
{
    int infor[MAX];
    int size;
} Stack;

// Ham khoi tao stack
void initStack(Stack *s)
{
    s->size = 0;
}

void push(Stack *s, int x)
{
    if (s->size == MAX)
        return;
    s->infor[s->size++] = x;
}

void pop(Stack *s)
{
    if (s->size == 0)
        return;
    s->size--;
}
int pop_getVal(Stack *s)
{
    if (s->size == 0)
        return -1;
    int val = s->infor[s->size - 1];
    s->size--;
    return val;
}

int peek(Stack *s)
{
    if (s->size > 0)
    {
        return s->infor[s->size - 1];
    }
}

void display(Stack s)
{
    printf("\n");
    for (int i = 0; i < s.size; i++)
    {
        printf("%d ", s.infor[i]);
    }
}
int isEmpty(Stack s)
{
    if (s.size == 0)
        return 1;
    else
        return 0;
}

void convert_D2B(int x)
{
    Stack s;
    initStack(&s);
    while (x > 0)
    {
        push(&s, x % 2);
        x /= 2;
    }
    while (!isEmpty(s))
    {
        int y = pop_getVal(&s);
        printf("%d ", y);
    }
}

main()
{
    convert_D2B(8);
}