#include <stdio.h>
#include <string.h>

typedef long long int LL;
char in[10000];

LL Pow(LL a, LL n) {
    if (n < 0) return 0;
    LL re = 1;
    while (n) {
        if (n & 1) re *= a;
        a *= a;
        n >>= 1;
    }
    return re;
}

int main() {
    LL a, n;
    while (scanf("%lld%s", &a, in)) {
        if (a == 0 && strcmp(in, "0") == 0) break;
        if (a == 0 || a == 1) {
            printf("%lld\n", a);
        } else if (a == -1) {
            n = in[strlen(in) - 1] - '0';
            puts(n & 1 ? "-1" : "1");
        } else {
            sscanf(in, "%lld", &n);
            printf("%lld\n", Pow(a, n));
        }
    }
    puts("All Over.");
}
