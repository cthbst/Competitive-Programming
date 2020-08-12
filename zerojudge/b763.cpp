#include <stdio.h>
#include <string.h>

const int maxp = 1030;
int prime[1030];

void build_prime() {
    int i, j;
    for (i = 0; i < maxp; i++) {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;

    for (i = 2; i < maxp; i++)
        if (prime[i]) {
            for (j = i * i; j < maxp; j += i) {
                prime[j] = 0;
            }
        }
    for (i = maxp - 1; i >= 2; i--)
        if (prime[i]) {
            int j = i * i;
            while (j < maxp) {
                prime[j] = 1;
                j *= i;
            }
        }
}

int a[1030];

int main() {
    build_prime();

    int N;
    scanf("%d", &N);

    int n = 0, p;
    for (p = 2; p <= N; p++)
        if (prime[p]) {
            a[n++] = p;
        }

    printf("%d\n", n);
    int i;
    for (i = 0; i < n; i++) {
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }
}
