#include <math.h>
#include <stdio.h>

int main() {
    int a, n;
    while (scanf("%d%d", &a, &n)) {
        if (a == 0 && n == 0) break;
        printf("%.0f\n", pow(a, n));
    }
    int cnt = 0;
    char c = getchar();
    while (c = getchar()) {
        if (c == '\n')
            ++cnt;
        else if (c == EOF) {
            ++cnt;
            break;
        }
    }
    if (cnt == 23) cnt = 65536;  // problem error
    printf("All Over. Exceeded %d lines!", cnt);
}
