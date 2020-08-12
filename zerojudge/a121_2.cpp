#include <math.h>
#include <stdio.h>
#include <string.h>

int prime[1240], p_size;

void set_prime() {
    prime[(p_size = 0)++] = 2;

    for (int i = 3; i < 10030; i += 2) {
        bool ok = 1;
        for (int j = 0, l = sqrt(i); prime[j] <= l; j++) {
            if (i % prime[j] == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) prime[p_size++] = i;
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
