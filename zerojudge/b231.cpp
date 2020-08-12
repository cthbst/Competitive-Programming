#include <stdio.h>

#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int main() {
    int n;

    while (~scanf("%d", &n)) {
        priority_queue<P> que;
        P p;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p.second, &p.first);
            que.push(p);
        }
        int sum = 0, ans = 0;
        while (!que.empty()) {
            p = que.top();
            que.pop();
            sum += p.second;
            ans = max(ans, sum + p.first);
        }

        printf("%d\n", ans);
    }
}
