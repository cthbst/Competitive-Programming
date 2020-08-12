#include <stdio.h>
#include <string.h>

#define MAXN 40
#define M 10
struct mar {
    int m[MAXN][MAXN];
};

int N, K;
mar product(mar a, mar b) {
    mar c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % M;
    return c;
}
mar sum(mar a, mar b) {
    mar c;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) c.m[i][j] = (a.m[i][j] + b.m[i][j]) % M;
    return c;
}

int main() {
    while (scanf("%d%d", &N, &K) && N != 0) {
        K--;

        mar one, zero;
        memset(zero.m, 0, sizeof(zero.m));
        memset(one.m, 0, sizeof(one.m));
        for (int i = 0; i < N; i++) one.m[i][i] = 1;
        // input -------------
        mar A;
        memset(A.m, 0, sizeof(A.m));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &A.m[i][j]);
            }
        }
        // dp ----------------
        mar Ans[2], T[30][2];
        Ans[0] = one;
        Ans[1] = zero;
        T[0][0] = A;
        T[0][1] = A;

        for (int i = 0; (1 << i) <= K; i++) {
            if (((K >> i) & 1) == 1) {
                Ans[1] = sum(Ans[1], product(Ans[0], T[i][1]));
                Ans[0] = product(Ans[0], T[i][0]);
            }

            T[i + 1][0] = product(T[i][0], T[i][0]);
            T[i + 1][1] = sum(T[i][1], product(T[i][0], T[i][1]));
        }
        mar OUT = sum(Ans[1], product(Ans[0], A));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", OUT.m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
