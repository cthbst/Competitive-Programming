#include <stdio.h>

int main() {
    int n;
    while (~scanf("%d", &n)) {
        char A[100], B[100];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < n; j++) {
                A[i * n + j] = (i % 2 ? '.' : '#');
                B[i * n + j] = (i % 2 ? '#' : '.');
            }
        }
        A[8 * n] = '\0';
        B[8 * n] = '\0';

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < n; j++) printf("%s\n", (i % 2 ? B : A));

        printf("\n");
    }
}
