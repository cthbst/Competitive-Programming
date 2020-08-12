#include <stdio.h>
#include <string.h>

#include <algorithm>
using namespace std;

int N, M, a[30];
bool ok = 0;

void walk(int floor, int sum, bool *S) {
    if (sum == M) {
        ok = 1;
        for (int i = 0; i < N; i++) {
            if (S[i] == 1) {
                printf("%d ", a[i]);
            }
        }
        printf("\n");
    }
    if (floor == N || sum >= M) return;
    for (int i = floor; i < N; i++) {
        S[i] = 1;
        walk(i + 1, sum + a[i], S);
        S[i] = 0;
    }
}

int main() {
    // input -------------------------------------
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    // sort ---------------------------------------
    sort(a, a + N);
    // walk ---------------------------------------
    bool S[30];
    memset(S, 0, sizeof(S));
    walk(0, 0, S);
    if (ok == 0) printf("-1");
}
