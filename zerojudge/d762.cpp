#include <stdio.h>

int a[5];

int tra(int type, int a, int b) {
    if (type == 0) return a + b;
    if (type == 1) return a - b;
    if (type == 2) return a * b;
}

bool walk(int floor, int *t) {
    if (floor == 5) {
        for (int i = 0; i < 81; i++) {
            int o = i;

            int S = a[t[0]];
            for (int i = 1; i < 5; i++) {
                S = tra(o % 3, S, a[t[i]]);
                o /= 3;
            }

            if (S == 23) return 1;
        }
    } else {
        for (int i = 0; i < 5; i++) {
            bool ok = 1;
            for (int j = 0; j < floor && ok; j++)
                if (t[j] == i) ok = 0;
            t[floor] = i;
            if (ok && walk(floor + 1, t)) return 1;
        }
    }

    return 0;
}

int main() {
    while (scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4])) {
        if (!a[0] && !a[1] && !a[2] && !a[3] && !a[4]) break;

        int t[5];
        printf("%s\n", walk(0, t) ? "Possible" : "Impossible");
    }
}
