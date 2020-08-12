#include <stdio.h>

int to_happy(int a) {
    int sum = 0;
    while (a) {
        sum += (a % 10) * (a % 10);
        a /= 10;
    }
    return sum;
}

int is_happy(int a) {
    while (a = to_happy(a)) {
        if (a == 1) return 1;
        if (a == 4) return 0;
    }
}

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        if (is_happy(a) == 1)
            printf("Case #%d: %d is a Happy number.\n", i + 1, a);
        else
            printf("Case #%d: %d is an Unhappy number.\n", i + 1, a);
    }
}
