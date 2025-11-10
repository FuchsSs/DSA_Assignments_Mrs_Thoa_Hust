#include <stdio.h>
#include <string.h>

int check(char *str, int start, int end)
{
    if (start >= end)
        return 1;
    else
    {
        if (str[start] != str[end])
            return -1;
        return check(str, start + 1, end - 1);
    }
}

int main()
{
    printf("%d", check("abcba", 0, 4));
}