#include <stdio.h>

int main() {
    int T, N, M;
    scanf("%d", &T);

    while (T-- && scanf("%d%d", &N, &M)) {
        printf("%d\n", N * M);
    }
}
