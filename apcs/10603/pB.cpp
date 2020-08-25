#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50004;
int n, p[MAXN];  // p[i] 是 i 所指向的人的編號
bool vis[MAXN];  // 紀錄 i 是否走訪過

int main() {
    // 輸入 p[i]
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // 初始化 vis[i]
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // 如果沒有走訪過，增加答案，並走訪整個群體
        if (vis[i] == 0) {
            ans++;
            int w = i;
            while (vis[w] == 0) {  // 沒走過就一直走
                vis[w] = 1;        // 走過設成 1
                w = p[w];          // 往指向的人走
            }
        }
    }
    cout << ans << '\n';
}
