#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T, n;
    scanf("%d%d", &T, &n);
    while (T--) {
        vector<int> a, b;
        // input----------------------------------
        for (int i = 0, in; i < n; i++) {
            scanf("%d", &in);
            a.push_back(in);
        }
        for (int i = 0, in; i < n; i++) {
            scanf("%d", &in);
            b.push_back(in);
        }
        // cooking--------------------------------
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            if (a[i] == b[j]) {
                ans++;
                i++, j++;
            } else
                a[i] < b[j] ? i++ : j++;
        }
        // output---------------------------------
        printf("%d\n", ans);
    }
}
