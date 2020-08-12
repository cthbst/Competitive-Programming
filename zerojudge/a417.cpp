#include <stdio.h>
#include <string.h>
#define MAXN 130
int M[MAXN][MAXN];

int main() {
    int T, N, type;
    scanf("%d", &T);

    while (T-- && scanf("%d%d", &N, &type)) {
        memset(M, 0, sizeof(M));
        for (int i = 0; i <= N + 1; i++) {
            M[0][i] = M[N + 1][i] = M[i][0] = M[i][N + 1] = -1;
        }
        if (type == 1) {
            int c = 1, i = 1, j = 0;
            while (c <= N * N) {
                while (!M[i][j + 1]) M[i][++j] = c, c++;
                while (!M[i + 1][j]) M[++i][j] = c, c++;
                while (!M[i][j - 1]) M[i][--j] = c, c++;
                while (!M[i - 1][j]) M[--i][j] = c, c++;
            }
        } else {
            int c = 1, i = 0, j = 1;
            while (c <= N * N) {
                while (!M[i + 1][j]) M[++i][j] = c, c++;
                while (!M[i][j + 1]) M[i][++j] = c, c++;
                while (!M[i - 1][j]) M[--i][j] = c, c++;
                while (!M[i][j - 1]) M[i][--j] = c, c++;
            }
        }
        // output ------------
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                printf("%5d", M[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
