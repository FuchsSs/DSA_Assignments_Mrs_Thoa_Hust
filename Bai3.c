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
void postfix_getval(Stack *s, double *a, double *b)
{
    *a = pop_getVal(s);
    *b = pop_getVal(s);
}

double postfix(char *A)
{
    Stack s;
    char *p = A;
    double a, b;
    while (*p != '\0')
    {
        switch (*p)
        {
        case '+':
            postfix_getval(&s, &a, &b);
            push(&s, b + a);
            break;

        case '-':
            postfix_getval(&s, &a, &b);
            push(&s, b - a);
            break;

        case '*':
            postfix_getval(&s, &a, &b);
            push(&s, b * a);

            break;

        case '/':
            postfix_getval(&s, &a, &b);
            if (a == 0)
                return -999999;
            else
            {
                push(&s, b / a);
                break;
            }

        default:
            push(&s, (*p) - '0');
            break;
        }
        p++;
    }
    return peek(s);
}

main()
{
    char A[100] = "30/2*";
    printf("%.2lf", postfix(A));
}