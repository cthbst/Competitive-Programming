#include <math.h>
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int x, y, z;
    while (T-- && scanf("%d%d%d", &x, &y, &z)) {
        if (z >= y || y >= x) {
            if (y >= x)
                puts("1");
            else
                puts("Poor Snail");
        } else {
            printf("%d\n", (int)ceil((double)(x - y) / (double)(y - z)) + 1);
        }
    }
}
