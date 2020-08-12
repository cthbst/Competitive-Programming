#include <math.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
using namespace std;
char A[10000], B[10000];

typedef long long int LL;
LL Pow(LL a, LL n) {
    LL re = 1;
    while (n) {
        if (n & 1) re *= a;
        a *= a;
        n >>= 1;
    }
    return re;
}
int main() {
    // freopen("in.txt","r",stdin) ;
    int a, b;
    while (scanf("%s%s", A, B)) {
        if (strcmp(A, "0") == 0 && strcmp(B, "0") == 0) break;
        sscanf(A, "%d", &a);
        if (a == 1 || a == 0) {
            printf("%d\n", a);
        } else if (a == -1) {
            b = B[strlen(B) - 1] - '0';
            puts(b & 1 ? "-1" : "1");
        } else {
            sscanf(B, "%d", &b);
            printf("%lld\n", Pow(a, b));
        }
    }

    int cnt = 0;
    cin.getline(A, sizeof(A));
    while (cin.getline(A, sizeof(A))) cnt++;

    printf("All Over. Exceeded %d lines!\n", cnt);
}
