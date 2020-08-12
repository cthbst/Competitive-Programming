#include <stdio.h>
#include <string.h>

int M[5][5];

int main() {
    int T, a, b, c, x, y;
    scanf("%d", &T);
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

    while (T-- && scanf("%d%d%d", &a, &b, &c)) {
        memset(M, 0, sizeof(M));

        y = (a - 1) % 3 + 1;
        x = 1 + (a - 1) / 3;
        for (int i = 0; i < 4; i++) M[x + dx[i]][y + dy[i]] = 1;
        y = (b - 1) % 3 + 1;
        x = 1 + (b - 1) / 3;
        for (int i = 0; i < 4; i++) M[x + dx[i]][y + dy[i]] = 0;
        y = (c - 1) % 3 + 1;
        x = 1 + (c - 1) / 3;
        for (int i = 0; i < 4; i++) M[x + dx[i]][y + dy[i]] = 0;

        bool out = 0;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                if (M[i][j] == 1) {
                    printf("%d ", (i - 1) * 3 + j);
                    out = 1;
                }
            }
        }
        if (!out) printf("Empty");
        printf("\n");
    }
}
