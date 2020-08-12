#include <math.h>
#include <stdio.h>

int main() {
    int T, N, M;
    scanf("%d", &T);

    while (T-- && scanf("%d%d", &N, &M)) {
        int L = (int)ceil((N - 2) / 3.0);
        int W = (int)ceil((M - 2) / 3.0);

        printf("%d\n", L * W);
    }
}
