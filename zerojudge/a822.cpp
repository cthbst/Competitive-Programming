#include <stdio.h>
#include <string.h>

const int INF = 1 << 30;
struct str {
    int x, y;
};
int G[530][530];
int dp[530][530];
str seat[500 * 500 + 30];

int main() {
    int N, X, Y;
    scanf("%d%d%d", &N, &X, &Y);
    for (int i = 0; i <= N + 1; i++)
        for (int j = 0; j <= N + 1; j++) G[i][j] = INF;
    // set G -----------------
    int t = 0, w = X * N + Y;
    while (t < N * N) {
        if (G[1 + w / N][1 + w % N] == INF) {
            G[1 + w / N][1 + w % N] = ++t;
            w = (w + t) % (N * N);
        } else {
            w = (w + 1) % (N * N);
        }
    }

    // dp --------------------
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 1;
            seat[G[i][j]] = (str){i, j};
        }
    }

    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    for (int i = N * N; i > 0; i--) {
        int to = -1;
        int x = seat[i].x, y = seat[i].y;
        for (int j = 0; j < 4; j++)
            if (G[x + dx[j]][y + dy[j]] < G[x][y]) {
                if (to == -1 ||
                    G[x + dx[j]][y + dy[j]] < G[x + dx[to]][y + dy[to]]) {
                    to = j;
                }
            }
        if (to == -1) continue;
        dp[x + dx[to]][y + dy[to]] += dp[x][y];
        dp[x][y] = 0;
    }
    // output ----------------
    int Ans = 0, count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i][j] > 0) {
                count++;
                if (dp[i][j] > Ans) Ans = dp[i][j];
            }
        }
    }
    printf("%d %d\n", count, Ans);
}
