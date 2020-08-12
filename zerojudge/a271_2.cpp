#include <stdio.h>
#include <string.h>

char a[3000];
int main() {
    int T, c[7];
    scanf("%d", &T);
    while (T--) {
        c[0] = 0;
        for (int i = 1; i <= 6; i++) scanf("%d", &c[i]);
        c[3] *= -1;
        c[4] *= -1;

        gets(a);
        gets(a);
        int t = 0, l = strlen(a), p = 0;
        while (t < l) {
            c[6] -= p;
            if (c[6] <= 0) break;
            c[6] += c[a[t] - '0'];
            if (c[6] <= 0) break;
            if (a[t] - '0' == 4) p += c[5];
            t += 2;
        }

        if (c[6] > 0)
            printf("%dg\n", c[6]);
        else
            printf("bye~Rabbit\n");
    }
}
