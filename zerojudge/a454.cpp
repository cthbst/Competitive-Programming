#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 1026
int t[MAXN];
int A[MAXN];
int main() {
    int T, N, K;
    scanf("%d", &T);
    while (T-- && scanf("%d", &N)) {
        vector<int> link[N + 1];
        memset(t, 0, sizeof(t));
        memset(A, 0, sizeof(A));
        // input--------------------------------------------
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", &t[i], &K);
            A[i] = t[i];
            for (int j = 0, in; j < K; j++) {
                scanf("%d", &in);
                link[i].push_back(in);
            }
        }
        // cooking------------------------------------------
        for (int i = 1; i <= N; i++) {
            queue<int> que;
            que.push(i);
            while (!que.empty()) {
                int n = que.front();
                que.pop();
                for (int i = 0; i < link[n].size(); i++) {
                    if (A[n] + t[link[n][i]] > A[link[n][i]]) {
                        A[link[n][i]] = A[n] + t[link[n][i]];
                        que.push(link[n][i]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) ans = max(ans, A[i]);
        printf("%d\n", ans);
    }
}
