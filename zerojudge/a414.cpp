#include <math.h>
#include <stdio.h>

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        int Ans = 0;
        while (N & 1) Ans++, N = N >> 1;
        printf("%d\n", Ans);
    }
}
