// https://omegaup.com/arena/problem/El-raton-que-salta-chueco

#include <stdio.h>
#include <vector>

struct posicion
{
    int x;
    int y;
};

int main()
{

    int m, n, f, d, r1, r2, h1, h2;

    scanf("%d%d%d%d%d%d%d%d", &m, &n, &f, &d, &r1, &r2, &h1, &h2);

    posicion raton, madriguera;
    raton = {r1, r2};
    madriguera = {h1, h2};

    std ::vector<posicion> actual = {raton};
    bool vistos[m + 1][n + 1] = {};
    vistos[raton.x][raton.y] = true;

    for (int pasos = 0; actual.size() > 0; pasos++)
    {
        std ::vector<posicion> siguiente;
        // printf ("\n");
        for (posicion ontoy : actual)
        {

            if (ontoy.x == madriguera.x && ontoy.y == madriguera.y)
            {
                // printf ("\n");
                printf("%d", pasos);
                return 0;
            }

            posicion brinco[] = {{ontoy.x - f, ontoy.y + d}, {ontoy.x + d, ontoy.y + f}, {ontoy.x + f, ontoy.y - d}, {ontoy.x - d, ontoy.y - f}};
            for (posicion ondevoy : brinco)
            {
                if (0 <= ondevoy.x && ondevoy.x < m && 0 <= ondevoy.y && ondevoy.y < n && vistos[ondevoy.x][ondevoy.y] == false)
                {
                    // printf ( "\n%d, %d", ondevoy.x , ondevoy.y);
                    siguiente.push_back(ondevoy);
                    vistos[ondevoy.x][ondevoy.y] = true;
                }
            }
        }
        actual = siguiente;
    }

    printf("-1");
}