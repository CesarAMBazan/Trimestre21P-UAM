#include <stdio.h>
#include <math.h>
//* Enfoque 2
int n;
int solve(int i)
{
    if (i == 1)
        return 2;
    else if (i == 2)
        return 4;
    else if (i == 3)
        return 7;
    else
        return solve(n - 1) + solve(n - 2) + solve(n - 3);
}
int main()
{
    scanf("%d", &n);
    printf("%d", solve(n));
    return 0;
}