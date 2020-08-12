#include <stdio.h>

#include <algorithm>
#include <map>
using namespace std;

const int maxMOD = 1030;
int d[maxMOD];
map<pair<int, int>, bool> S;

int pow(int a, unsigned long long b, int mod) {
    a %= mod;
    int re = 1;
    while (b) {
        if (b & 1) re = re * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return re;
}
int main() {
    // set d ---------------------------
    d[1] = 1;
    for (int mod = 2; mod < maxMOD; mod++) {
        S.clear();
        int a = 0, b = 1;
        while (1) {
            auto &x = S[make_pair(a, b)];
            if (x)
                break;
            else
                x = 1;
            b += a;
            a = b - a;
            if (b >= mod) b -= mod;
        }
        d[mod] = S.size();
    }
    // solve ---------------------------
    int T;
    scanf("%d", &T);
    unsigned long long a, b;
    int mod;
    while (T-- && scanf("%llu%llu%d", &a, &b, &mod)) {
        int k = pow(a % d[mod], b, d[mod]);
        a = 0, b = 1;
        for (int i = 0; i < k; i++) {
            b += a;
            a = b - a;
            if (b >= mod) b -= mod;
        }
        printf("%d\n", a % mod);
    }
}
