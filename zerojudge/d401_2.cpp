#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N;
    while (~scanf("%d", &N)) {
        vector<int> a[2];
        for (int i = 0, type, h; i < N; i++) {
            scanf("%d%d", &type, &h);
            a[type - 1].push_back(h);
        }
        sort(a[0].begin(), a[0].end(), cmp);
        sort(a[1].begin(), a[1].end(), cmp);

        int K;
        scanf("%d", &K);
        if (a[0][K - 1] > a[1][K - 1])
            printf("%d %d\n", 1, a[0][K - 1] - a[1][K - 1]);
        else
            printf("%d %d\n", 2, a[1][K - 1] - a[0][K - 1]);
    }
}
