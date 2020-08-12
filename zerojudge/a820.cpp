#include <stdio.h>

const int MaxN = 100;
int G[MaxN][MaxN];

int main() {
    // input -----------------
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &G[j][i]);
        }
    }
    // walk ------------------
    int Ans = 0, x, y, dx, dy, life = 3;
    scanf("%d%d%d", &x, &y, &dx);
    dy = (dx == 1 || dx == 2) ? 1 : -1;
    dx = (dx == 1 || dx == 4) ? -1 : 1;

    while (life >= 0) {
        Ans += G[x][y];
        bool change = 0;
        if (1 <= x + dx && x + dx <= N)
            x = x + dx;
        else
            dx *= -1, change = 1;
        if (1 <= y + dy && y + dy <= M)
            y = y + dy;
        else
            dy *= -1, change = 1;
        if (change) life--;
    }
    // output ----------------
    printf("%d\n", Ans);
}
