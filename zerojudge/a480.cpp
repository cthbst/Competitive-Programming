#include <stdio.h>

#include <algorithm>
using namespace std;

struct str {
    int a, b;
};
str S[1000030];

bool cmp(str a, str b) {
    if (a.a != b.a) return a.a > b.a;
    return a.b < b.b;
}

int main() {
    int Ax, Ay, Bx, By;
    scanf("%d%d%d%d", &Ax, &Ay, &Bx, &By);

    int N;
    scanf("%d", &N);
    for (int i = 0, a, b; i < N; i++) {
        scanf("%d%d", &a, &b);
        S[i].a = (Ax - a) * (Ax - a) + (Ay - b) * (Ay - b);
        S[i].b = (Bx - a) * (Bx - a) + (By - b) * (By - b);
    }
    sort(S, S + N, cmp);

    int Ans = S[0].a, B = S[0].b;
    for (int i = 0; i < N - 1; i++) {
        B = max(B, S[i].b);
        Ans = min(Ans, S[i + 1].a + B);
    }
    Ans = min(Ans, B);

    printf("%d\n", Ans);
}
