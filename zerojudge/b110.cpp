#include <stdio.h>

char T[300000], M[300][300];

void set_tree(int n, int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2)
        T[n] = M[x1][y1] == '1' ? 'b' : 'w';
    else {
        int xm = (x1 + x2) / 2, ym = (y1 + y2) / 2;
        set_tree(4 * n + 1, x1, ym + 1, xm, y2);
        set_tree(4 * n + 2, x1, y1, xm, ym);
        set_tree(4 * n + 3, xm + 1, y1, x2, ym);
        set_tree(4 * n + 4, xm + 1, ym + 1, x2, y2);

        int t = 0;
        for (int i = 1; i <= 4; i++) {
            if (T[4 * n + i] == 'b')
                t++;
            else if (T[4 * n + i] == 'w')
                t--;
        }
        if (t == 4)
            T[n] = 'b';
        else if (t == -4)
            T[n] = 'w';
        else
            T[n] = 'g';
    }
}

void out(int n) {
    printf("%c ", T[n]);
    if (T[n] == 'g') {
        out(4 * n + 1);
        out(4 * n + 2);
        out(4 * n + 3);
        out(4 * n + 4);
    }
}
int main() {
    int N;
    while (~scanf("%d", &N)) {
        for (int i = 0; i < N; i++) scanf("%s", &M[i]);
        set_tree(0, 0, 0, N - 1, N - 1);
        out(0);
        printf("\n");
    }
}
