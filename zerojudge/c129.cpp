#include <stdio.h>
#include <string.h>

#define MAXN 130
bool S[MAXN][MAXN];

void DFS(int x, int y) {
    S[x][y] = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (S[x + i][y + j] == 1) DFS(x + i, y + j);
        }
    }
}

int main() {
    int N, M;

    while (scanf("%d%d", &N, &M) && N != 0 && M != 0) {
        memset(S, 0, sizeof(S));

        // input -----------
        char in[MAXN];
        for (int i = 1; i <= N; i++) {
            scanf("%s", &in);
            for (int j = 0; j < M; j++) {
                if (in[j] == '@') S[i][j + 1] = 1;
            }
        }
        // DFS -------------
        int Ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (S[i][j]) {
                    Ans++;
                    DFS(i, j);
                }
            }
        }
        // output ----------
        printf("%d\n", Ans);
    }
}
