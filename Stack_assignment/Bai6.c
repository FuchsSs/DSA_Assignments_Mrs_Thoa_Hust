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
int isStackEmpty(Stack *s) { return s->size == 0; }
void type(char *currentScentence)
{
    printf(">> Type your sentences: ");
    scanf("%s", currentScentence);
    getchar();
}
void display(char *currentScentence, Stack *undoStack, Stack *redoStack)
{
    printf("\n----------------------------------------\n");
    printf("Current Scentence: %s\n", currentScentence[0] == '\0' ? "(empty)" : currentScentence);
    printf("Undo possible: %s\n", isStackEmpty(undoStack) ? "Can't Undo" : peek(undoStack));
    printf("Redo possible: %s\n", isStackEmpty(redoStack) ? "Can't Redo" : peek(redoStack));
    printf("----------------------------------------\n");
}

void page_state(char *currentScentence, Stack *undoStack, Stack *redoStack)
{
    char command[2];
    while (1)
    {
        printf("\n----------------------------------------\n");
        display(currentScentence, undoStack, redoStack);
        printf("Commands: 't' (type); 'u' (undo); 'r' (redo); 'q' (quit)\n");

        printf("Enter command: ");
        scanf("%s", command);
        getchar();
        if (strcmp(command, "q") == 0)
        {
            printf("Exit Simulator\n");
            return;
        }
        else if (strcmp(command, "t") == 0)
        {
            push(undoStack, strdup(currentScentence));
            type(currentScentence);
            deleteStack(redoStack);
        }
        else if (strcmp(command, "u") == 0)
        {
            if (!isStackEmpty(undoStack))
            {
                push(redoStack, strdup(currentScentence));
                currentScentence = pop(undoStack);
                printf("Undo scentence: %s", currentScentence);
            }
            else
            {
                printf("Can't Undo\n");
            }
        }
        else if (strcmp(command, "r") == 0)
        {
            if (!isStackEmpty(redoStack))
            {
                push(undoStack, strdup(currentScentence));
                currentScentence = pop(redoStack);
                printf("Redo scentence: %s", currentScentence);
            }
            else
            {
                printf("Can't Redo\n");
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
    char *pages[100];
    Stack undoStack, redoStack;
    initStack(&undoStack);
    initStack(&redoStack);

    char *currentScentence = (char *)malloc(sizeof(char) * 100);
    *currentScentence = '\0';

    page_state(currentScentence, &undoStack, &redoStack);

    free(currentScentence);

    return 0;
}
