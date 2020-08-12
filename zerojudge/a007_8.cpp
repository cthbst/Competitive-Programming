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

    int n;
    while (~scanf("%d", &n)) {
        printf("%s\n", is_prime(n) ? "質數" : "非質數");
    }
}
