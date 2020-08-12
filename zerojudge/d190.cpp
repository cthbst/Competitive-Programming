#include <stdio.h>
#include <string.h>

int a[101];

int main() {
    memset(a, 0, sizeof(a));
    int N;
    while (scanf("%d", &N) && N != 0) {
        for (int i = 0, in; i < N; i++) {
            scanf("%d", &in);
            a[in]++;
        }

        for (int i = 0; i <= 100; i++) {
            while (a[i] > 0) {
                printf("%d ", i);
                a[i]--;
            }
        }

        printf("\n");
    }
}
