#include <stdio.h>
#include <math.h>
int power(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return power(a, b - 1) * a;
}

int main()
{
    printf("%d", power(2, 3));
}