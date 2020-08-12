#include <math.h>
#include <stdio.h>

#define MAX 65537
int P[6542], Ps;
bool Pb[MAX + 1];

void set_prime_list() {
    Ps = 0;
    P[Ps++] = 2;
    Pb[2] = 1;
    for (int i = 3; i < MAX; i += 2) {
        bool ok = 1;
        for (int j = 0, k = floor(sqrt(i)); P[j] <= k; j++)
            if (i % P[j] == 0) {
                ok = 0;
                break;
            }
        if (ok) P[Ps++] = i;
        Pb[i] = ok;
    }
}

bool is_prime(int n) {
    bool ok = 1;
    for (int i = 0, k = floor(sqrt(n)); P[i] <= k; i++) {
        if (n % P[i] == 0) {
            ok = 0;
            break;
        }
    }
    return ok;
}

int main() {
    set_prime_list();

    int n;
    while (~scanf("%d", &n)) {
        bool ok;
        if (n < MAX)
            ok = Pb[n];
        else
            ok = is_prime(n);

        printf("%s\n", ok == 1 ? "質數" : "非質數");
    }
}
