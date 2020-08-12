#include <stdio.h>
#include <string.h>

#include <algorithm>
using namespace std;

const int maxN = 30000;
int cnt[maxN];

int main() {
    memset(cnt, 0, sizeof(cnt));

    int N;
    scanf("%d", &N);
    int time = 0;
    for (int i = 0, ai; i < N; i++) {
        scanf("%d", &ai);
        cnt[ai]++;
        time = max(time, cnt[ai]);
    }
    for (int i = 0; i <= maxN; i++) {
        if (cnt[i] == time) {
            printf("%d %d\n", i, time);
        }
    }
}
