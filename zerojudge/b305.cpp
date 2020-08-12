#include <math.h>
#include <stdio.h>

int main() {
    // freopen("in.txt","r",stdin) ;
    int T;
    scanf("%d", &T);
    long long a2 = 0, a1 = 0, a0 = 0;

    while (T--) {
        long long int n, u, s;
        scanf("%lld%lld%lld", &n, &u, &s);
        a0 += n;
        a1 += n * u;
        a2 += s * s * n + 2 * n * u * u - u * u * n;
    }
    double n = (double)a0;
    double u = (double)a1 / n;
    double s = (double)a2 - 2.0 * u * a1 + u * u * n;
    s = s / n;
    s = sqrt(s);
    printf("%.0f %.02f %.02f\n", n, u, s);
}
