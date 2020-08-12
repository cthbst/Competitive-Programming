#include <stdio.h>

int pos[1000030];

int main() {
    int n;
    scanf("%d", &n);

    int i, pi;
    for (i = 0, pi; i < n; i++) {
        scanf("%d", &pi);
        pos[pi - 1] = i;
    }

    int vec = 1, ans = 0;

    for (i = 1; i < n; i++) {
        if ((pos[i] - pos[i - 1]) * vec < 0) {
            ans++;
            vec *= -1;
        }
    }

    printf("%d\n", ans);
}
