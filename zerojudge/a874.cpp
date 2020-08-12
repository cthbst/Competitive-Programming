#include <stdio.h>
#include <string.h>

#include <algorithm>
using namespace std;
#define MAXN 30
#define INF 67372036
int d[MAXN][MAXN];
int main() {
    int N;
    while (~scanf("%d", &N)) {
        memset(d, 4, sizeof(d));
        // input------------------------------------------
        char ina[2], inb[2];
        int inw;
        for (int i = 0; i < N; i++) {
            scanf("%s%s%d", &ina, &inb, &inw);
            int a = ina[0] - 'A', b = inb[0] - 'A';
            d[a][b] = d[b][a] = inw;
        }
        // shortest path----------------------------------
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        // output-----------------------------------------
        scanf("%s%s", ina, inb);
        int a = ina[0] - 'A', b = inb[0] - 'A';

        if (d[a][b] == INF)
            printf("NoRoute");
        else
            printf("%d", d[a][b]);
        printf("\n");
    }
}
