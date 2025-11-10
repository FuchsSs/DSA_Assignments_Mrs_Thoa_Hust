#include <stdio.h>
#include <math.h>
int powerSum(int n)
{
    if (n == 1)
        return 1;
    else if (n == 0)
        return 0;
    else
        return powerSum(n - 1) + n * n;
}

int main()
{
    printf("%d", powerSum(2));
}