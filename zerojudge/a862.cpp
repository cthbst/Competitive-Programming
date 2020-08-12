#include <stdio.h>

int main() {
    double a, b;
    while (~scanf("%lf%lf", &a, &b)) {
        a *= 1000;
        printf("%.4lf\n", a / b);
    }
}
