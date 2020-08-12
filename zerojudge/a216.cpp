#include <iostream>
using namespace std;

const int maxn = 30010;
int f[maxn];
long long g[maxn];

int main() {
    // build f[] ,g[] ---------------------
    f[1] = g[1] = 1;
    for (int i = 2; i < maxn; i++) {
        f[i] = i + f[i - 1];
    }
    for (int i = 2; i < maxn; i++) {
        g[i] = f[i] + g[i - 1];
    }

    // solve ------------------------------
    int n;
    while (cin >> n) {
        cout << f[n] << " " << g[n] << endl;
    }
}
