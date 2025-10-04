#include <stdio.h>
#include <stdlib.h>
// cai dat stack luu tru
#define MAX 100
typedef struct Stack
{
    double infor[MAX];
    int size;
} Stack;

// Ham khoi tao stack
void initStack(Stack *s)
{
    s->size = 0;
}

void push(Stack *s, double x)
{
    if (s->size == MAX)
        return;
    s->infor[s->size++] = x;
}
void deleteStack(Stack *s)
{
    s->size = 0;
}

void pop(Stack *s)
{
    if (s->size == 0)
        return;
    s->size--;
}
double pop_getVal(Stack *s)
{
    if (s->size == 0)
        return -1;
    double val = s->infor[s->size - 1];
    s->size--;
    return val;
}

double peek(Stack s)
{
    if (s.size > 0)
    {
        return s.infor[s.size - 1];
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
int length(char *A)
{
    char *p = A;
    int len = 0;
    while (*p != '\0')
    {
        len++;
        p++;
    }
    return len;
}
int check_symmetry(char *A)
{
    Stack s;
    int len = length(A);
    char *p = A;
    int i = 0;
    while (p[i] != '\0')
    {
        if (i < len / 2)
        {
            push(&s, p[i]);
        }
        else
        {
            if (i == len / 2 && len % 2 != 0)
                i++;
            int x = pop_getVal(&s);
            if (x != p[i])
                return -1;
        }
        i++;
    }
    return 1;
}

main()
{
    char A[100] = "abdcba";

    printf("%.d", check_symmetry(A));
}