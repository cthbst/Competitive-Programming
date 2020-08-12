#include <stdio.h>
#include <string.h>

#include <algorithm>
using namespace std;
#define MAXN 110
#define INF 16843009
int d[MAXN][MAXN];

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        memset(d, 0, sizeof(d));
        // input--------------------------------
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) scanf("%d", &d[i][j]);
        // all pair shortest path---------------
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if ((d[i][j] == 0 || d[i][j] > d[i][k] + d[k][j]) &&
                        d[i][k] != 0 && d[k][j] != 0)
                        d[i][j] = d[i][k] + d[k][j];
        // find ans-----------------------------
        int ans = 0;
        for (int i = 0; i < N; i++)
            if ((ans == 0 || d[i][i] < ans)) ans = d[i][i];
        // output-------------------------------
        if (ans == 0) ans = -1;
        printf("%d\n", ans);
    }
}
