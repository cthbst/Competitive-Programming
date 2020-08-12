#include <stdio.h>

#include <queue>
#include <vector>
using namespace std;

vector<int> a[2];
priority_queue<int, vector<int>, greater<int> > que[2];

int main() {
    int N;

    while (~scanf("%d", &N)) {
        a[0].clear();
        a[1].clear();
        // input -------------
        for (int i = 0, p, h; i < N; i++) {
            scanf("%d%d", &p, &h);
            a[p - 1].push_back(h);
        }
        // K th --------------
        int K;
        scanf("%d", &K);
        while (!que[0].empty()) que[0].pop();
        while (!que[1].empty()) que[1].pop();
        for (int p = 0; p < 2; p++) {
            for (int x : a[p]) {
                que[p].push(x);
                if (que[p].size() > K) que[p].pop();
            }
        }
        // output ------------
        int x = que[0].top(), y = que[1].top();
        if (x > y)
            printf("1 %d\n", x - y);
        else
            printf("2 %d\n", y - x);
    }
}
