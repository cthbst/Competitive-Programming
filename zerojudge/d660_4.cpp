#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int N, tall = 0, low = 0;
        scanf("%d", &N);
        int m, n;
        scanf("%d", &m);
        for (int i = 1; i < N; i++) {
            scanf("%d", &n);
            if (n > m)
                tall++;
            else if (n < m)
                low++;
            m = n;
        }
        printf("Case %d: %d %d\n", cas, tall, low);
    }
}
