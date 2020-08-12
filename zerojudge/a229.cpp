#include <stdio.h>

char c[30];
int N;

void walk(int floor, int l, int u) {
    if (floor == 2 * N - 1) {
        puts(c);
        return;
    }
    if (u > 0) {
        c[floor] = '(';
        walk(floor + 1, l + 1, u - 1);
        c[floor] = ' ';
    }
    if (l > 0) {
        c[floor] = ')';
        walk(floor + 1, l - 1, u);
        c[floor] = ' ';
    }
}

int main() {
    while (~scanf("%d", &N)) {
        c[0] = '(';
        c[2 * N - 1] = ')';
        c[2 * N] = 0;
        walk(1, 1, N - 1);
    }
}
