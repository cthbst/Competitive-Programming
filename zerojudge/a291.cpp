#include <stdio.h>

int main() {
    int a[4], b[4], aa[4];

    while (~scanf("%d%d%d%d", &aa[0], &aa[1], &aa[2], &aa[3])) {
        int n;
        scanf("%d", &n);
        while (n-- && scanf("%d%d%d%d", &b[0], &b[1], &b[2], &b[3])) {
            for (int i = 0; i < 4; i++) a[i] = aa[i];
            int A = 0;
            for (int i = 0; i < 4; i++) {
                if (a[i] == b[i]) {
                    a[i] = b[i] = -1;
                    A++;
                }
            }
            int B = 0;
            for (int i = 0; i < 4; i++)
                if (a[i] >= 0) {
                    for (int j = 0; j < 4; j++)
                        if (b[j] >= 0) {
                            if (a[i] != b[j]) continue;
                            a[i] = b[j] = -1;
                            B++;
                        }
                }
            printf("%dA%dB\n", A, B);
        }
    }
}
