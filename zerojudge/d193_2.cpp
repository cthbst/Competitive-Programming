#include <stdio.h>
int main(void) {
    int X, Y, M, N, in0;
    scanf("%d", &in0);
    while (in0--) {
        scanf("%d %d %d %d", &N, &X, &Y, &M);
        printf("%d %d\n", M - (M * X - N) / (X - Y), (M * X - N) / (X - Y));
    }

    return 0;
}
