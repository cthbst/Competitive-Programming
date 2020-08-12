#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    char A[130], B[130];

    while (T-- && scanf("%s%s", A, B)) {
        int a = strlen(A) - 1, b = strlen(B) - 1, c = 0;
        int Ans = 0;
        while (a >= 0 || b >= 0) {
            c = c / 10;
            if (a >= 0) c += A[a] - '0', a--;
            if (b >= 0) c += B[b] - '0', b--;
            if (c >= 10) Ans++;
        }
        printf("%d\n", Ans);
    }
}
