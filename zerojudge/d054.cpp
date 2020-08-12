#include <stdio.h>
unsigned long long int f[45];
int main() {
    f[0] = 1;
    f[1] = 1;
    f[2] = 5;
    for (int i = 2; i <= 40; i++) f[i] = f[i - 1] + 4 * f[i - 2] + 2 * f[i - 3];
    // for (int i=1 ;i<=40 ;i++ )printf("%lld\n",f[i]) ;

    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%lld\n", f[n]);
    }
}
