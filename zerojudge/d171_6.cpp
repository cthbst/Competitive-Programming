#include <stdio.h>
#include <string.h>

int main() {
    int N, M, type, count[42];
    while (scanf("%d", &N) && N != 0) {
        memset(count, 0, sizeof(count));
        while (N-- && scanf("%d", &M)) {
            while (M-- && scanf("%d", &type)) {
                count[type]++;
            }
        }

        int Ans = 1 << 30;
        for (int i = 1; i <= 41; i++)
            if (count[i] < Ans) Ans = count[i];

        printf("%d\n", Ans);
    }
}
