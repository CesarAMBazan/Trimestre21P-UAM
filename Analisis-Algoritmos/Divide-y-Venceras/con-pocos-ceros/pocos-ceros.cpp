#include <stdio.h>
#include <math.h>
//* Enfoque 1
//* No sirve para >6
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
        return 2 * solve(i - 1) - pow(2, i - 4);
}
int main()
{
    scanf("%d", &n);
    printf("%d", solve(n));
    return 0;
}