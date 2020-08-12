#include <stdio.h>

int walk;

void out(int n, int s, int t) {
    if (n > 1) out(n - 1, s, 3 - t - s);
    printf("ring %d : %c -> %c\n", n, 'a' + s, 'a' + t);
    walk++;
    if (n > 1) out(n - 1, 3 - t - s, t);
}

void dout(int n, int s) {
    if (s == 0 || (n & 1) != (s & 1)) {
        int to = (n & 1) ? 1 : 2;
        if (n > 1) out(n - 1, s, 3 - s - to);
        printf("ring %d : %c -> %c\n", n, 'a' + s, 'a' + to);
        walk++;
        if (n > 1) dout(n - 1, 3 - s - to);
    } else {
        if (n > 1) dout(n - 1, s);
    }
}

int main() {
    int N;
    while (~scanf("%d", &N)) {
        walk = 0;
        dout(N, 0);
        printf("共移動了 %d 步\n", walk);
    }
}
