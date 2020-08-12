#include <stdio.h>

int main() {
    int K, N;
    while (~scanf("%d%d", &K, &N)) {
        int ans = 0;
        for (int i = 10; i >= 0; i--) {
            ans *= K;
            if ((N >> i) & 1) ans++;
        }
        printf("%d", ans);
    }
}
