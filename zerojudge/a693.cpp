#include <stdio.h>

#define MAX 100010

int S[MAX];
int main() {
    int N, M;
    while (~scanf("%d%d", &N, &M)) {
        S[0] = 0;
        for (int i = 1, in; i <= N; i++) {
            scanf("%d", &in);
            S[i] = in + S[i - 1];
        }
        for (int i = 0, a, b; i < M; i++) {
            scanf("%d%d", &a, &b);
            printf("%d\n", S[b] - S[a - 1]);
        }
    }
}
