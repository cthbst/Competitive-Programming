#include <stdio.h>

void out(int n, int from, int to) {
    if (n > 1) out(n - 1, from, 3 - from - to);
    printf("Move ring %d from %c to %c\n", n, 'A' + from, 'A' + to);
    if (n > 1) out(n - 1, 3 - from - to, to);
}

int main() {
    int N;
    while (~scanf("%d", &N)) {
        out(N, 0, 2);
    }
}
