#include <stdio.h>
#include <string.h>

#define MAXN 510
int S[MAXN][MAXN];

int main() {
    int N, M;
    while (~scanf("%d%d", &N, &M)) {
        memset(S[0], 0, sizeof(S[0]));
        for (int i = 1, in; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &in);
                S[i][j] = in + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
            }
        }

        for (int i = 0, x1, y1, x2, y2; i < M; i++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%d\n", S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] +
                               S[x1 - 1][y1 - 1]);
        }
    }
}
