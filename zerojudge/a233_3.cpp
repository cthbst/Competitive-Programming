#include <stdio.h>
#include <string.h>
bool OK[1 << 10];

int main() {
    int T, N, P;
    scanf("%d", &T);

    while (T-- && scanf("%d%d", &N, &P)) {
        memset(OK, 1, sizeof(OK));
        int MaxL = 0;
        for (int i = 0, L, Min, Max, t; i < P; i++) {
            scanf("%d", &L);
            if (L > MaxL) MaxL = L;

            bool bo[15];
            memset(bo, 0, sizeof(bo));

            scanf("%d", &Min);
            bo[Min - 1] = 1;
            for (int j = 1; j < L - 1; j++) {
                scanf("%d", &t);
                bo[t - 1] = 1;
            }
            scanf("%d", &Max);
            bo[Max - 1] = 1;

            for (int n = 0; n < (1 << N); n++) {
                bool ok = 1;
                for (int j = Min - 1; j <= Max - 1 && ok; j++) {
                    if ((int)((n >> j) & 1) != (int)(bo[j] & 1)) ok = 0;
                }
                if (ok) OK[n] = 0;
            }
        }
        // output ------------
        int Ans = 0;
        for (int i = 0; i < (1 << N); i++)
            if (OK[i]) {
                int count = 0;
                for (int j = 0; j < N; j++) {
                    if (i & (1 << j)) count++;
                }
                if (count > 1) Ans++;
            }
        if (Ans == 0)
            puts("so sad");
        else
            printf("%d\n", Ans);
    }
}
