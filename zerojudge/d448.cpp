#include <stdio.h>

int main() {
    double t1, t2, t3, x1, x3;
    while (~scanf("%lf%lf%lf%lf%lf", &t1, &t2, &t3, &x1, &x3)) {
        printf("%.6lf\n", ((t1 - t2) * x3 + (t2 - t3) * x1) / (t1 - t3));
    }
}
