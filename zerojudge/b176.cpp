#include <stdio.h>

#include <algorithm>
using namespace std;

#define MAXN 100
#define LL long long int
LL A[MAXN][MAXN];

int main() {
    int N, M;

    while (~scanf("%d%d", &N, &M)) {
        // input -------------
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%lld", &A[i][j]);
            }
        }
        // dp ----------------
        LL H[MAXN][MAXN];
        for (int i = 0; i < M; i++) {
            H[0][i] = 1;
            for (int j = 1; j < N; j++) {
                if (A[j][i] > A[j - 1][i])
                    H[j][i] = H[j - 1][i] + 1;
                else
                    H[j][i] = 1;
            }
        }

        LL R[MAXN][MAXN];
        for (int i = 0; i < N; i++) {
            R[i][0] = 0;
            for (int j = 1; j < M; j++) {
                if (A[i][j] > A[i][j - 1])
                    R[i][j] = R[i][j - 1];
                else
                    R[i][j] = R[i][j - 1] + 1;
            }
        }

        LL Ans = 0;
        for (int i = 0; i < N; i++) {
            for (int l = 0; l < M; l++) {
                for (int r = l; r < M && R[i][r] == R[i][l]; r++) {
                    LL h = 130;
                    for (int k = l; k <= r; k++) h = min(h, H[i][k]);
                    for (int k = 1; k <= h; k++) {
                        if (R[i - k + 1][l] != R[i - k + 1][r]) {
                            h = k - 1;
                            break;
                        }
                    }
                    Ans = max(Ans, h * (r - l + 1));
                }
            }
        }
        printf("%lld\n", Ans);
    }
}
