#include <stdio.h>

int main() {
    int T, N;
    scanf("%d", &T);

    while (T-- && scanf("%d", &N)) {
        int Ans = 0;

        int d = 1;

        while (N != 0) {
            N -= d, Ans++;
            if (N % (d * 2)) N -= d, Ans++;
            d <<= 1;
        }

        printf("%d\n", Ans);
    }
}
