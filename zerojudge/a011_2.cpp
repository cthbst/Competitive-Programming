#include <stdio.h>

int main() {
    int T, c[6];
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 6; i++) scanf("%d", &c[i]);

        int count = 0;
        for (int i = 1; i < 6; i++)
            for (int j = i + 1; j < 6; j++) {
                int A = 1, B = 1;
                for (int l = 0; l < 6; l++) {
                    if (l == i || l == j || l == 0)
                        A *= c[l];
                    else
                        B *= c[l];
                }
                if (A == B) count++;
            }
        printf("%d\n", count);
    }
}
