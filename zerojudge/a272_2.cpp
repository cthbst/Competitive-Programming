#include <stdio.h>
#include <string.h>

typedef long long int LL;

LL M;

LL mod(LL a, LL b) {
    if (a > 0)
        return a % b;
    else
        return a % b + b;
}

void product(LL *a, LL *b) {
    LL c[2][2];
    c[0][0] = mod(((*(a + 0)) * (*(b + 0)) + (*(a + 1)) * (*(b + 2))), M);
    c[0][1] = mod(((*(a + 0)) * (*(b + 1)) + (*(a + 1)) * (*(b + 3))), M);
    c[1][0] = mod(((*(a + 2)) * (*(b + 0)) + (*(a + 3)) * (*(b + 2))), M);
    c[1][1] = mod(((*(a + 2)) * (*(b + 1)) + (*(a + 3)) * (*(b + 3))), M);

    // return
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) *(a + 2 * i + j) = c[i][j];
    }
}

int main() {
    LL T, I[2][2], Ans[2][2], t;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld%lld%lld", &I[0][0], &I[0][1], &I[1][0],
              &I[1][1], &t, &M);

        // cooking----------------------------------------------------
        Ans[0][0] = Ans[1][1] = 1;
        Ans[0][1] = Ans[1][0] = 0;

        while (t) {
            if (t % 2 == 1) {
                product(*Ans, *I);
            }
            product(*I, *I);
            t /= 2;
        }
        // output-----------------------------------------------------
        LL B = mod((Ans[0][0] + Ans[0][1]), M),
           E = mod((Ans[1][0] + Ans[1][1]), M);

        if (B > E)
            puts("Tsundere");
        else if (B < E)
            puts("Haraguroi");
        else
            puts("Normal");
    }
}
