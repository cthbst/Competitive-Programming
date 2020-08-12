#include <stdio.h>
#include <string.h>
#define MAX 30 + 10
int a[MAX], b[MAX], c[MAX];
int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        a[0] = 1;
        N++;
        while (N--) {
            int k = 0;
            for (int i = 0; i < MAX; i++) {
                c[i] = (a[i] + b[i] + k) % 10;
                k = (a[i] + b[i] + k) / 10;
            }
            memset(a, 0, sizeof(a));
            memcpy(a, b, sizeof(b));
            memset(b, 0, sizeof(b));
            memcpy(b, c, sizeof(c));
            memset(c, 0, sizeof(c));
        }
        int j = MAX - 1;
        for (j; j >= 0; j--)
            if (b[j] > 0) break;
        for (j; j >= 0; j--) printf("%d", b[j]);
        printf("\n");
    }
}
