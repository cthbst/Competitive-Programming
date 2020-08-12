/**********************************************************************************/
/*  Problem: a824 "100學年度桃竹苗區資訊學科能力競賽 2.藏寶問題" from
 * 100學年度桃竹苗區資訊學科能力競賽*/
/*  Language: CPP (372 Bytes) */
/*  Result: AC(4ms, 240KB) judge by this@ZeroJudge */
/*  Author: cthbst at 2013-11-04 13:57:52 */
/**********************************************************************************/

#include <stdio.h>
int GCD(int x, int y) {
    while (1) {
        if (x == 0) return y;
        y %= x;
        if (y == 0) return x;
        x %= y;
    }
}
int f(int n) {
    return n * (n + 1) / 2;
}
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int SUM = a * f(c / a) + b * f(c / b) -
              a * b / GCD(a, b) * f(c / (a * b / GCD(a, b)));
    printf("%c", (SUM - 1) % 26 + 'A');
}
