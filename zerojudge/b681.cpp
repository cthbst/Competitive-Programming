#include <stdio.h>

int main() {
    long long a;

    scanf("%lld", &a);
    if (a >= 0)
        printf("%lld\n", a * 2 - 1);
    else
        printf("%lld\n", (-a) * 2);
}
