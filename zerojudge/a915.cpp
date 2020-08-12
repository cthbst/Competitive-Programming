#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

struct str {
    int x, y;
};

bool cmp(str a, str b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y <= b.y;
}

int main() {
    int N;
    while (~scanf("%d", &N)) {
        vector<str> S(N);

        for (int i = 0; i < N; i++) scanf("%d%d", &S[i].x, &S[i].y);
        sort(S.begin(), S.end(), cmp);

        // output ------------
        for (int i = 0; i < N; i++) printf("%d %d\n", S[i].x, S[i].y);
    }
}
