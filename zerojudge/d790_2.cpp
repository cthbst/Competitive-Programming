#include <stdio.h>

int T, n, m;

void out(char *w, int floor, int used) {
    if (floor == n) {
        w[n] = '\0';
        printf("%s\n", w);
    }

    else {
        if (n - floor > m - used) {
            w[floor] = '0';
            out(w, floor + 1, used);
        }
        if (m > used) {
            w[floor] = '1';
            out(w, floor + 1, used + 1);
        }
    }
}

int main() {
    scanf("%d", &T);

    while (T-- && scanf("%d%d", &n, &m)) {
        char s[20];
        out(s, 0, 0);
        printf("\n");
    }
}
