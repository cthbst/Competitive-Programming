#include <stdio.h>
#include <string.h>

int N, M[15][15];
bool outputed;

void output() {
    for (int i = 1; i <= N * N; i++) {
        for (int j = 1; j <= N * N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void check(int x, int y, bool *un) {
    for (int i = 1; i <= N * N; i++) {
        un[M[x][i]] = 1;
        un[M[i][y]] = 1;
    }
    for (int i = ((x - 1) / N) * N + 1; i <= ((x - 1) / N) * N + N; i++) {
        for (int j = ((y - 1) / N) * N + 1; j <= ((y - 1) / N) * N + N; j++) {
            un[M[i][j]] = 1;
        }
    }
}

void walk() {
    // find ------------------
    int x, y;
    bool found = 0;

    for (int i = 1; i <= N * N && !found; i++) {
        for (int j = 1; j <= N * N && !found; j++) {
            if (M[i][j] == 0) {
                found = 1, x = i, y = j;
            }
        }
    }

    // outptu ----------------
    if (!found) {
        output();
        outputed = 1;
        return;
    }

    // next ------------------
    bool next[15];
    memset(next, 0, sizeof(next));
    check(x, y, next);

    for (int i = 1; i <= N * N && !outputed; i++) {
        if (!next[i]) {
            M[x][y] = i;
            walk();
            M[x][y] = 0;
        }
    }
}
int main() {
    while (~scanf("%d", &N)) {
        // input -------------
        for (int i = 1; i <= N * N; i++) {
            for (int j = 1; j <= N * N; j++) {
                scanf("%d", &M[i][j]);
            }
        }

        // solve -------------
        outputed = 0;

        int count[2][10];
        bool ok = 1;

        for (int i = 1; i <= N * N; i++) {
            memset(count, 0, sizeof(count));
            for (int j = 1; j <= N * N; j++) {
                count[0][M[i][j]]++;
                count[1][M[j][i]]++;
                if (M[i][j] != 0 && count[0][M[i][j]] > 1) ok = 0;
                if (M[j][i] != 0 && count[1][M[j][i]] > 1) ok = 0;
            }
        }

        if (ok) walk();
        if (!outputed || !ok) printf("NO SOLUTION\n");
    }
}
