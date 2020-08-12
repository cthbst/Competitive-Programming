#include <stdio.h>
#include <string.h>

int ans[1000001][10];

int main() {
    // build -----------------
    memset(ans[0], 0, sizeof(ans[0]));
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 0; j < 10; j++) ans[i][j] = ans[i - 1][j];
        int k = i;
        while (k) {
            ++ans[i][k % 10];
            k /= 10;
        }
    }
    // query -----------------
    int n, k;
    while (~scanf("%d%d", &n, &k)) {
        printf("%d\n", ans[n][k]);
    }
}
