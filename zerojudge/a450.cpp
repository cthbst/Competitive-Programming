#include <stdio.h>

#include <algorithm>
using namespace std;

#define MAXN 1000030
#define INF 1000000030
int a[MAXN];

int N, M;
int BSA(int K) {
    int L = 0, R = N + 1;
    while (1) {
        if (L == R) return L;
        int mid = (L + R) / 2;
        if (a[mid] < K)
            L = mid + 1;
        else
            R = mid;
    }
}
int main() {
    scanf("%d%d", &N, &M);

    a[0] = -INF;
    a[N + 1] = INF;
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    sort(a + 1, a + N + 1);

    for (int i = 0, a, b; i < M; i++) {
        scanf("%d%d", &a, &b);
        int Ans = BSA(b + 1) - BSA(a);
        if (Ans == 0)
            puts("The candies are too short");
        else
            printf("%d\n", Ans);
    }
}
