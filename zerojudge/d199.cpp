#include <math.h>
#include <stdio.h>

int main() {
    double a, b, c;
    while (~scanf("%lf%lf%lf", &a, &b, &c)) {
        double d = sqrt((a + b + c) * (a + b + c) - 4.0 * a * c);
        printf("%.0f\n", d);
    }
}
