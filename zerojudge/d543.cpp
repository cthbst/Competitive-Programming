#include <stdio.h>
#include <string.h>

int Ans;
void dfs(int deep, int N, int a, int b, int c) {
    if (deep == N) {
        Ans++;
        return;
    }
    int S = a & (b >> (N - deep - 1)) & (c >> deep), low;

    while (S) {
        low = S & (-S);
        dfs(deep + 1, N, a ^ low, b ^ (low << (N - deep - 1)),
            c ^ (low << deep));
        S ^= low;
    }
}

int main() {
    int N;
    while (~scanf("%d", &N)) {
        Ans = 0;
        dfs(0, N, (1 << N) - 1, (1 << (2 * N)) - 1, (1 << (2 * N)) - 1);
        printf("%d\n", Ans);
    }
}
