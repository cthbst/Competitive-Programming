#include <stdio.h>
#include <string.h>

#include <queue>
#include <vector>
using namespace std;

const int maxN = 10030;
vector<int> from[maxN], to[maxN];
int out[maxN], s[maxN];
bool dp[maxN];

int main() {
    int N, M;
    while (scanf("%d%d", &N, &M) && !(N == 0 && M == 0)) {
        for (int i = 1; i <= N; i++) {
            from[i].clear();
            to[i].clear();
            out[i] = 0;
        }

        for (int i = 0, a, b; i < M; i++) {
            scanf("%d%d", &a, &b);
            out[a]++;
            from[b].push_back(a);
            to[a].push_back(b);
        }

        queue<int> que;
        for (int i = 1; i <= N; i++)
            if (out[i] == 0) que.push(i);
        int l = 0;
        while (!que.empty()) {
            int w = que.front();
            que.pop();
            s[l++] = w;
            for (int i = 0; i < from[w].size(); i++) {
                int u = from[w][i];
                out[u]--;
                if (out[u] == 0) que.push(u);
            }
        }

        for (int i = 0; i < N; i++) {
            dp[s[i]] = 1;
            for (int j = 0; j < to[s[i]].size(); j++) {
                int u = to[s[i]][j];
                if (dp[u] == 1) {
                    dp[s[i]] = 0;
                    break;
                }
            }
        }

        char name[100];
        scanf("%s", name);
        if ((strcmp(name, "Mimi") == 0 && dp[1] == 0) ||
            (strcmp(name, "Moumou") == 0 && dp[1] == 1)) {
            puts("Moumou");
        } else
            puts("Mimi");
    }
}
