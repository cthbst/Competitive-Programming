#include <stdio.h>

#include <algorithm>
using namespace std;
int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        int ans, sum;
        scanf("%d", &sum);
        ans = sum;
        for (int i = 1, ai; i < N; i++) {
            scanf("%d", &ai);
            sum = max(sum + ai, ai);
            ans = max(ans, sum);
        }
        if (ans <= 0) {
            puts("Losing streak.");
        } else {
            printf("The maximum winning streak is %d.\n", ans);
        }
    }
}
