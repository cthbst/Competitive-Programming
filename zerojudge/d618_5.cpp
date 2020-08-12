#include <stdio.h>

int main() {
    int T, N;
    scanf("%d", &T);

    while (T-- && scanf("%d", &N)) {
        int a, b, Ans = 1, AnsL = 0;
        scanf("%d", &a);
        for (int i = 1; i < N; i++) {
            scanf("%d", &b);
            if (b - a > AnsL) Ans = i, AnsL = b - a;
            a = b;
        }
        printf("%d\n", Ans);
    }
}
