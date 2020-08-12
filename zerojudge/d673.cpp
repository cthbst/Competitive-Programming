/**********************************************************************************/
/*  Problem: d673 "11608 - No Problem" from UVa ACM 11608 */
/*  Language: CPP (407 Bytes) */
/*  Result: WA(line:16) judge by this@ZeroJudge */
/*  Author: cthbst at 2013-09-13 19:38:13 */
/**********************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int S, testn = 1;
    while (scanf("%d", &S)) {
        if (S < 0) break;

        printf("Case %d:\n", testn++);

        int input[2][12];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 12; j++) scanf("%d", &input[i][j]);
        for (int i = 0; i < 12; i++) {
            printf("No problem%s\n", (S - input[1][i] >= 0 ? "! :D" : ". :("));
            if (S - input[1][i] >= 0)
                S = S + input[0][i] - input[1][i];
            else
                S = S + input[0][i];
        }
    }
}
