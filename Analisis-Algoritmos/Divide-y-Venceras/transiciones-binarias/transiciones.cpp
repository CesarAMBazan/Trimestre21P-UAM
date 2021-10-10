#include <stdio.h>
#include <math.h>
int n;

long solve(int i)
{
    if (i <= 1)
        return 0;
    else if (i == 2)
        return 2;
    else
    {
        return solve(i - 1) * 2 + pow(2, i - 1);
    }
}
int main()
{
    scanf("%d", &n);
    printf("%ld", solve(n));
    return 0;
}