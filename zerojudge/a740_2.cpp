#include <stdio.h>
#include <string.h>

#include <vector>
using namespace std;

vector<long long int> Prime;
typedef long long int LL;
const int maxN = 70000;
void build() {
    static bool p[maxN];

    memset(p, 1, sizeof(p));
    for (int i = 2; i < maxN; i++)
        if (p[i]) {
            Prime.push_back((LL)i);
            for (int j = i + i; j < maxN; j += i) {
                p[j] = 0;
            }
        }
}

int main() {
    build();

    LL n;
    while (~scanf("%lld", &n)) {
        LL ans = 0;
        for (LL p : Prime) {
            if (p * p > n) break;
            while (n % p == 0) {
                ans += p;
                n /= p;
            }
        }
        if (n > 1) ans += n;
        printf("%lld\n", ans);
    }
}
