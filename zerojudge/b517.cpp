#include <bits/stdc++.h>
using namespace std;

int fa[100];
int root(int x) {
    if (fa[x] == -1) return fa[x] = x;
    if (fa[x] == x) return x;
    return fa[x] = root(fa[x]);
}

string ins;
int main() {
    int T;
    cin >> T;
    getline(cin, ins);
    while (T-- && getline(cin, ins)) {
        memset(fa, -1, sizeof(fa));
        bool ok = 1;
        stringstream ss;
        ss << ins;
        int a, b;
        char c;
        while (ss >> a >> c >> b) {
            a = root(a), b = root(b);
            if (a == b) ok = 0;
            fa[b] = a;
        }
        int cnt = 0;
        for (int i = 0; i < 100; i++)
            if (fa[i] == i) cnt++;
        if (cnt != 1) ok = 0;

        puts(ok ? "T" : "F");
    }
}
