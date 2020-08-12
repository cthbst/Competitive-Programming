#include <stdio.h>

int main() {
    int T, N, ai;

    scanf("%d", &T);

    while (T-- && scanf("%d", &N)) {
        double sum = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &ai);
            sum += ai;
        }
        printf("%.2f\n", sum / N);
    }
}
