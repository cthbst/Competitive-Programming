#include <stdio.h>
#include <string.h>
#define MAX 1200
int main() {
    int T;
    char A[MAX], B[MAX];
    scanf("%d", &T);
    while (T-- && scanf("%s%s", &A, &B)) {
        int ok = 1;
        for (int i = 0, l = strlen(A); i < l; i++)
            if (A[i] == '?') {
                if (B[i] == '?') {
                    ok = 0;
                    break;
                } else {
                    A[i] = B[i];
                }
            }
        // output-------------------------------------------
        if (!ok)
            printf("No");
        else
            printf("Yes:%s", A);
        if (T != 0) printf("\n");
    }
}
