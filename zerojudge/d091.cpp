#include <math.h>
#include <stdio.h>

const double EPS = 1E-7;

int main() {
    int R = 0;
    double a[10], b[10], c[10], d[10];
    {
        char order[2];
        while (scanf("%s", order) && order[0] != '*') {
            scanf("%lf%lf%lf%lf", &a[R], &b[R], &c[R], &d[R]);
            R++;
        }
    }
    {
        int num = 1;
        double x, y;
        while (scanf("%lf%lf", &x, &y)) {
            if (fabs(x - 9999.9) < EPS && fabs(y - 9999.9) < EPS) break;
            int cnt = 0;
            for (int i = 0; i < R; i++) {
                if (a[i] < x && x < c[i] && d[i] < y && y < b[i]) {
                    printf("Point %d is contained in figure %d\n", num, i + 1);
                    cnt++;
                }
            }
            if (cnt == 0) {
                printf("Point %d is not contained in any figure\n", num);
            }
            num++;
        }
    }
}
