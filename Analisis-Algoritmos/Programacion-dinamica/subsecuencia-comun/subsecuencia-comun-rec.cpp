//* Recurrencia

#include <stdio.h>
#include <string.h>
#include <algorithm>

// int f(int i, int j)
// {
//     if (i == ta || j == tb)
//         return 0;
//     else if (a[i] == b[j])
//         return f(i + 1, j + 1) + 1;
//     else
//     {
//         return std::max(f(i, j + 1), f(i + 1, j));
//     }
// }
int main()
{
    char a[45000 + 1], b[45000 + 1];
    scanf("%s%s", &a, &b);
    int ta = strlen(a);
    int tb = strlen(b);
    if (ta <= 1000 && tb <= 1000)
    {
        int memoria[ta + 1][tb + 1];
        for (int i = ta; i >= 0; i--)
        {
            for (int j = tb; j >= 0; j--)
            {
                if (i == ta || j == tb)
                    memoria[i][j] = 0;
                else if (a[i] == b[j])
                    memoria[i][j] = memoria[i + 1][j + 1] + 1;
                else
                {
                    memoria[i][j] = std::max(memoria[i][j + 1], memoria[i + 1][j]);
                }
            }
        }
        printf("%d\n", memoria[0][0]);
        int i_ = 0, j_ = 0;
        while (i_ < ta && j_ < tb)
        {
            if (a[i_] == b[j_])
            {
                printf("%d %d\n", i_, j_);
                i_ = i_ + 1;
                j_ = j_ + 1;
            }
            else
            {
                if (memoria[i_][j_] == memoria[i_][j_ + 1])
                    j_++;
                else
                    i_++;
            }
        }
    }
    else
    {
        int memoria[2][tb + 1];
        int *actual = &memoria[0][0];
        int *previa = &memoria[1][0];
        for (int i = ta; i >= 0; i--, std::swap(actual, previa))
        {
            for (int j = tb; j >= 0; j--)
            {
                if (i == ta || j == tb)
                    actual[j] = 0;
                else if (a[i] == b[j])
                    actual[j] = previa[j + 1] + 1;
                else
                {
                    actual[j] = std::max(actual[j + 1], previa[j]);
                }
            }
        }
        printf("%d\n", previa[0]);
    }

    return 0;
}