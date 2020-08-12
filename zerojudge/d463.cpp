#include <math.h>
#include <stdio.h>

typedef unsigned long long int uLL;

int main() {
    uLL a;
    while (~scanf("%llu", &a)) {
        uLL x = pow((double)a, 1.0 / 3.0);
        while (x * x * x != a) x++;
        printf("%llu\n", x);
    }
}
