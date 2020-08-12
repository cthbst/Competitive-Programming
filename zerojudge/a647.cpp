#include <stdio.h>

const double EPS = 1E-9;

int main() {
    int T;
    scanf("%d", &T);

    double m, p;
    while (T-- && scanf("%lf%lf", &m, &p)) {
        double ans = 100 * (p - m) / m;

        if (ans > -EPS)
            printf("%.02f%% ", ans + EPS);
        else
            printf("%.02f%% ", ans - EPS);

        if (ans < -7.0 + EPS || ans > 10.0 - EPS)
            puts("dispose");
        else
            puts("keep");
    }
}
