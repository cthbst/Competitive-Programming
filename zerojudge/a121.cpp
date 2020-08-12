#include <math.h>
#include <stdio.h>
#include <string.h>

int prime[1240], p_size;

void set_prime() {
    bool is_prime[10030];
    memset(is_prime, 1, sizeof(is_prime));

    for (int i = 2; i <= 101; i++)
        if (is_prime[i]) {
            for (int j = i * 2; j < 10030; j += i) {
                is_prime[j] = 0;
            }
        }
    prime[(p_size = 0)++] = 2;
    for (int i = 3; i < 10030; i++) {
        if (is_prime[i]) prime[p_size++] = i;
    }
}

bool is_prime[1030];

int main() {
    set_prime();

    int a, b;

    while (~scanf("%d%d", &a, &b)) {
        int len = b - a + 1;
        memset(is_prime, 1, sizeof(is_prime));

        for (int i = 0, l = sqrt(b); prime[i] <= l; i++) {
            int s = (int)ceil((double)a / prime[i]) * prime[i] - a;
            if (a <= prime[i]) s += prime[i];
            while (s < len) is_prime[s] = 0, s += prime[i];
        }

        int Ans = 0;
        if (a == 1) is_prime[0] = 0;
        for (int i = 0; i < len; i++) {
            Ans += is_prime[i];
        }
        printf("%d\n", Ans);
    }
}
