#include <stdio.h>

#include <algorithm>
using namespace std;

struct str {
    int s, h, w;
};
bool cmp(str A, str B) {
    if (A.h != B.h) return A.h < B.h;
    if (A.w != B.w) return A.w < B.w;
    return A.s < B.s;
}
str S[10030];
int Abs(int a) {
    return a > 0 ? a : -a;
}
int main() {
    int N;
    while (~scanf("%d", &N)) {
        // input -------------
        for (int i = 0; i < N; i++) {
            S[i].s = i;
            scanf("%d%d", &S[i].h, &S[i].w);
        }
        // count -------------
        sort(S, S + N, cmp);
        int ans = 0;
        for (int i = 0; i < N; i++) ans += Abs(S[i].s - i);

        // output ------------
        printf("%d\n", ans);
    }
}
