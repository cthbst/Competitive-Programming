#include <stdio.h>

typedef long long int LL;
int main() {
    LL a, b, c, d, e, f, D;

    while (~scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f)) {
        D = a * e - b * d;
        if (D == 0)
            puts(a * f == c * d ? "Too many" : "No answer");
        else
            printf("x=%.2lf\ny=%.2lf\n", (double)(e * c - b * f) / D,
                   (double)(a * f - d * c) / D);
    }
}
