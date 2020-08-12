#include <bits/stdc++.h>
using namespace std;

const int maxN = 100030;
int n, a[maxN];

int main() {
    int n;

    while (cin >> n) {
        // input -------------
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // count -------------
        int ans = 1;  // all

        int i = 0, j = n - 1;
        int sumL = 0, sumR = 0;

        while (0 <= j && i < n) {
            if (sumL <= sumR)
                sumL += a[i++];
            else
                sumR += a[j--];

            if (sumL == sumR) ans++;
        }

        cout << ans << endl;
    }
}
