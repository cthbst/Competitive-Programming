#include <math.h>
#include <stdio.h>

#define MAX 65537
int prime[6542], len = 0;

void set_prime() {
    prime[len++] = 2;
    for (int i = 3; i < MAX; i += 2) {
        bool ok = 1;
        for (int j = 0, k = floor(sqrt(i)); prime[j] <= k; j++)
            if (i % prime[j] == 0) {
                ok = 0;
                break;
            }
        if (ok) prime[len++] = i;
    }
}

bool is_prime(int n) {
    for (int i = 0, k = floor(sqrt(n)); prime[i] <= k; i++)
        if (n % prime[i] == 0) return 0;
    return 1;
}

int main() {
    set_prime();
    int N, M;
    scanf("%d%d", &N, &M);
    int a[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = (1 << N) - 1; i >= 0; i--) {
        int cnt = 0;
        int sum = 0;
        for (int j = 1, k = 0; j < (1 << N); j <<= 1, k++) {
            if ((i & j) > 0) cnt++, sum += a[k];
        }
        if (cnt != M) continue;
        if (is_prime(sum)) ans++;
    }
    printf("%d\n", ans);
}
