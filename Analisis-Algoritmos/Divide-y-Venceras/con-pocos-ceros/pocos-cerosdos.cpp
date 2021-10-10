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
        return solve(i - 1) + solve(i - 2) + solve(i - 3);
}
int main()
{
    scanf("%d", &n);
    printf("%d", solve(n));
    return 0;
}