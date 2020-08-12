#include <stdio.h>
#include <string.h>
int main() {
    int T, N;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        // input -------------
        char in[300];
        scanf("%d%s", &N, &in);

        // solve -------------
        int Ans = 0;
        for (int i = 0; i < strlen(in); i++) {
            if (in[i] == '.') {
                in[i] = in[i + 1] = in[i + 2] = '#';
                Ans++;
            }
        }
        // output ------------
        printf("Case %d: %d\n", t, Ans);
    }
}
