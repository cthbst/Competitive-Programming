#include <stdio.h>
#include <string.h>

char a[3000];
int main() {
    int T, c[7];
    scanf("%d", &T);
    gets(a);
    c[0] = 0;
    while (T--) {
        gets(a);
        sscanf(a, "%d%d%d%d%d%d", &c[1], &c[2], &c[3], &c[4], &c[5], &c[6]);
        c[3] *= -1;
        c[4] *= -1;

        gets(a);
        int t = 0, l = strlen(a), p = 0;
        while (t < l) {
            if (c[6] <= p) {
                c[6] -= p;
                break;
            }
            c[6] += c[a[t] - '0'] - p;
            if (c[6] <= 0) break;

            if (a[t] == '4') p += c[5];
            t += 2;
        }

        if (c[6] > 0)
            printf("%dg\n", c[6]);
        else
            puts("bye~Rabbit");
    }
}
