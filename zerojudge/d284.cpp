#include <stdio.h>
#include <string.h>

int A[130][130];

int main() {
    memset(A, 0, sizeof(A));
    // set_A -----------------
    // A[i]=A[i-1]*8+10^(i-1) ;
    A[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        A[i][i - 1] = 1;
        for (int j = 0; j < i; j++) {
            A[i][j] += A[i - 1][j] * 8;
            A[i][j + 1] += A[i][j] / 10;
            A[i][j] %= 10;
        }
    }

    // solve -----------------
    int N;

    while (scanf("%d", &N) && N != 0) {
        for (int i = N - 1; i >= 0; i--) {
            printf("%d", A[N][i]);
        }
        printf("\n");
    }
}
