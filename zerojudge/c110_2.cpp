#include <stdio.h>

#include <algorithm>
using namespace std;

struct str {
    int C, E;
};
str S[10030];

bool cmp(str a, str b) {
    return max(a.C + a.E, a.C + b.C + b.E) < max(b.C + b.E, b.C + a.C + a.E);
}

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        // input -------------
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &S[i].C, &S[i].E);
        }
        // sort --------------
        sort(S, S + N, cmp);
        // sum ---------------
        int Ans = 0, sum = 0;
        for (int i = 0; i < N; i++) {
            Ans = max(Ans, sum + S[i].C + S[i].E);
            sum += S[i].C;
        }
        // output ------------
        printf("%d\n", Ans);
    }
}
