#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct Stack
{
    char *infor[MAX];
    int size;
} Stack;
void initStack(Stack *s)
{
    s->size = 0;
}
void push(Stack *s, char *x)
{
    if (s->size < MAX)
        s->infor[s->size++] = x;
}
void deleteStack(Stack *s)
{
    s->size = 0;
}
char *pop(Stack *s)
{
    if (s->size == 0)
        return NULL;
    return s->infor[--s->size];
}
char *peek(Stack *s)
{
    if (s->size == 0)
        return NULL;
    return s->infor[s->size - 1];
}
int isStackEmpty(Stack *s)
{
    return s->size == 0;
}

void display(char *currentPage, Stack *backStack, Stack *forwardStack)
{
    printf("\n----------------------------------------\n");
    printf(">> Current Page: %s\n", currentPage);
    printf("   Back possible: %s\n", isStackEmpty(backStack) ? "No" : "Yes");
    printf("   Forward possible: %s\n", isStackEmpty(forwardStack) ? "No" : "Yes");
    printf("----------------------------------------\n");
}
void page_state(char *currentPage, Stack *backStack, Stack *forwardStack, char **pages, int totalPages)
{
    char command[3];
    int currentPagesIndex = 0;
    while (1)
    {
        printf("\nCommands: 'n' (next); 'b' (back); 'f' (forward); 'q' (quit)");
        display(currentPage, backStack, forwardStack);
        printf("Enter command: ");
        scanf("%s", &command);
        printf("\n");
        if (strcmp(command, "q") == 0)
        {
            printf("Exit Simulator\n");
            return;
        }
        else if (strcmp(command, "n") == 0)
        {
            if (currentPagesIndex + 1 < totalPages)
            {
                push(backStack, currentPage);
                deleteStack(forwardStack);
                currentPage = pages[++currentPagesIndex];
                printf("Navigate to next page\n");
            }
            else
            {
                printf("No more page to navigate\n");
            }
        }
        else if (strcmp(command, "b") == 0)
        {
            if (!isStackEmpty(backStack))
            {
                printf("Navigate to previous page\n");
                push(forwardStack, currentPage);
                currentPage = pop(backStack);
                currentPagesIndex--;
            }
            else
            {
                printf("No more page to navigate\n");
            }
        }
        else if (strcmp(command, "f") == 0)
        {
            if (!isStackEmpty(forwardStack))
            {

                printf("Navigate to forward page\n");
                push(backStack, currentPage);
                currentPage = pop(forwardStack);
            }
            else
            {
                printf("No more page to forward\n");
            }
        }
        else
        {
            printf("Invalid command\n");
        }
    }
}
int main()
{
    char *pages[] = {"Page 1", "Page 2", "Page 3", "Page 4"};
    Stack backStack, forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);
    char *currentPage = pages[0];
    int totalPages = sizeof(pages) / sizeof(pages[0]);
    page_state(currentPage, &backStack, &forwardStack, pages, totalPages);

    return 0;
}