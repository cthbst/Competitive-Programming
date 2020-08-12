#include <math.h>
#include <stdio.h>

long long int H(long long int n) {
    long long int res = 0, sum = n, k = floor(sqrt(n) + 0.5);
    for (long long int i = 1; i < k; i++) {
        res += i * (n / i - n / (i + 1));
        sum -= (n / i - n / (i + 1));
    }
    for (long long int i = sum; i > 0; i--) {
        res += n / i;
    }

    return res;
}

int main() {
    int in0;
    long long int input;
    scanf("%d", &in0);

    while (in0--) {
        scanf("%lld", &input);
        printf("%lld \n", H(input));
    }
    return 0;
}
