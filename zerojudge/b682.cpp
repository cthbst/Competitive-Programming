#include <stdio.h>

int main() {
    int h[2], m[2];
    scanf("%d%d", &h[0], &m[0]);
    scanf("%d%d", &h[1], &m[1]);

    int hh = h[1] - h[0];
    int mm = m[1] - m[0];

    if (mm < 0) hh--, mm += 60;
    if (hh < 0) hh += 24;

    printf("%d %d\n", hh, mm);
}
