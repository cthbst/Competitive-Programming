#include <stdio.h>
#include <string.h>

double d[30][30];

int main() {
    int N, S, T;
    while (~scanf("%d", &N)) {
        // input -------------
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) scanf("%lf", &d[i][j]);
        scanf("%d%d", &S, &T);
        // deg sort ----------
        int deg[30], del[30], vis[30];
        memset(del, 0, sizeof(del));
        memset(vis, 0, sizeof(vis));

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (d[i][j] > 0.0) del[j]++;
        for (int t = 1; t <= N; t++) {
            int w = 0;
            for (int i = 1; i <= N && !w; i++)
                if (!vis[i] && del[i] == 0) w = i;
            if (w == 0) {
                for (int i = 1; i <= N; i++)
                    if (!vis[i] && del[i] != 0) deg[t++] = i;
                break;
            }
            deg[t] = w;
            vis[w] = 1;
            for (int i = 1; i <= N; i++)
                if (d[w][i] > 0.0) del[i]--;
        }

        // P -----------------
        double P[30];
        for (int i = 1; i <= N; i++) P[i] = 0.0;
        P[S] = 1.0;

        for (int i = 1; i <= N; i++)
            if (deg[i] != S) {
                int w = deg[i];
                P[w] = 1.0;
                for (int j = 1; j <= N; j++)
                    if (w != j) P[w] *= (1.0 - P[j] * d[j][w]);
                P[w] = 1.0 - P[w];
            }
        // output ------------
        printf("%0.5f\n", P[T]);
    }
}
