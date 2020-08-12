#include <stdio.h>

int main() {
    int n, A[3], B[3];

    while (~scanf("%d%d%d%d%d%d%d", &n, &A[0], &A[1], &A[2], &B[0], &B[1],
                  &B[2])) {
        if (!n && !A[0] && !A[1] && !A[2] && !B[0] && !B[1] && !B[2]) break;
        bool OK = 0;
        for (int i = 0; i < 8; i++) {
            int c[3];
            for (int j = 0; j < 3; j++)
                c[j] = (((i >> j) & 1) > 0 ? A[j] : n - A[j]);
            if (B[0] == c[0] && B[1] == c[1] && B[2] == c[2])
                OK = 1;
            else if (B[0] == c[0] && B[1] == c[2] && B[2] == c[1])
                OK = 1;
            else if (B[0] == c[1] && B[1] == c[0] && B[2] == c[2])
                OK = 1;
            else if (B[0] == c[1] && B[1] == c[2] && B[2] == c[0])
                OK = 1;
            else if (B[0] == c[2] && B[1] == c[0] && B[2] == c[1])
                OK = 1;
            else if (B[0] == c[2] && B[1] == c[1] && B[2] == c[0])
                OK = 1;
            if (OK) break;
        }
        printf("%s\n", OK == 1 ? "Yes" : "No");
    }
}
