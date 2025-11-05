#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Status
{
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

typedef struct Process
{
    int ID;
    int priority;
    char *name;
    enum Status s;
    struct Process *next;
} Process;

Process *createProcess(int ID, int priority, char *name, enum Status s)
{
    Process *x = (Process *)malloc(sizeof(Process));
    x->ID = ID;
    x->priority = priority;
    if (name == NULL)
    {
        return NULL;
    }
    else
    {
        x->name = strdup(name);
    }
    x->s = s;
    x->next = NULL;
    return x;
}

void insertProcess(Process **list, Process *x)
{
    if (*list == NULL)
    {
        *list = x;
    }
    else
    {
        if (((*list)->priority) < x->priority)
        {
            x->next = *list;
            *list = x;
        }
        else
        {
            Process *p = *list;
            while ((p->next) != NULL && (p->next)->priority >= x->priority)
            {
                p = p->next;
            }
            x->next = p->next;
            p->next = x;
        }
    }
}

Process *findReadyHighestPriority(Process *list)
{
    Process *p = list;
    while (p->s != READY && p != NULL)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        printf("Highest Ready Process ID: %d\n", p->ID);
    }
    else
    {
        printf("Can'find Highest Ready Process\n");
    }
    return p;
}
void removeProcess(Process **list, Process *p)
{
    if (*list == NULL || p == NULL)
    {
        return;
    }
    else
    {
        Process *cur = *list;
        while (cur->next != p && cur->next != NULL)
        {
            cur = cur->next;
        }
        if (cur->next == NULL)
        {
            printf("Process ID: %d is not in the List\n", p->ID);
            return;
        }
        else
        {
            cur->next = p->next;
            p->next = NULL;
            printf("Delete Process ID: %d\n", p->ID);
            free(p);
        }
    }
}

void removeAllTerminated(Process **list)
{
    if (*list == NULL)
    {
        return;
    }
    else
    {
        Process *cur = *list;
        while (cur != NULL)
        {
            Process *tmp = cur->next;
            if (cur->s == TERMINATED)
            {
                removeProcess(list, cur);
            }
            cur = tmp;
        }
        printf("Delete all Terminated Process Done\n");
    }
}

void display(Process *x)
{
    Process *tmp = x;
    {
        while (tmp != NULL)
        {
            printf("ID: %d, Priority: %d, Name: %s, Status: ", tmp->ID, tmp->priority, tmp->name);
            switch (tmp->s)
            {
            case 0:
                printf("READY\n");
                break;
            case 1:
                printf("RUNNING\n");
                break;
            case 2:
                printf("WAITING\n");
                break;
            case 3:
                printf("TERMINATED\n");
                break;
            default:
                printf("NONE\n");
                break;
            }
            tmp = tmp->next;
        }
    }
}

int main()
{
    Process *list = NULL;
    Process *C = createProcess(110, 9, "C", TERMINATED);
    Process *A = createProcess(101, 10, "A", READY);
    Process *B = createProcess(102, 11, "B", READY);
    Process *D = createProcess(105, 8, "D", TERMINATED);
    insertProcess(&list, A);
    insertProcess(&list, C);
    insertProcess(&list, B);
    insertProcess(&list, D);

    Process *highestReady = findReadyHighestPriority(list);
    display(list);

    removeAllTerminated(&list);

    display(list);
}