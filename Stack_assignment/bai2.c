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

int check_Parathesis(char *A)
{
    Stack s;
    char *p = A;
    initStack(&s);

    while (*p != NULL)
    {
        if (*p == '(')
        {
            push(&s, *p);
        }
        else
        {
            if (*p == ')')
            {
                if (isEmpty(s))
                    return -1;
                pop(&s);
            }
        }
        p++;
    }
    return (isEmpty(s)) ? 1 : -1;
}

main()
{
    char A[100] = "(())((";
    printf("%d", check_Parathesis(A));
}