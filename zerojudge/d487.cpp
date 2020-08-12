#include <stdio.h>

int tp() {
    int out = 1;
}
int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0 || n == 1) printf("%d! = 1 = 1\n", n);
        // 5! = 5 * 4 * 3 * 2 * 1 = 120
        else {
            printf("%d! =", n);
            int out = 1;
            while (n) {
                out *= n;
                if (n == 1)
                    printf(" 1 = %d\n", out);
                else
                    printf(" %d *", n);
                n--;
            }
        }
    }
}
