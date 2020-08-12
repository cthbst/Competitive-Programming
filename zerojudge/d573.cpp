#include <stdio.h>

int a[100030];

int main() {
    int N;
    while (~scanf("%d", &N)) {
        int num, M;
        while (N-- && scanf("%d%d", &num, &M)) {
            for (int i = 0, in; i < M; i++) {
                scanf("%d", &in);
                a[in] = num;
            }
        }
        int E;
        scanf("%d", &E);
        printf("%d\n", a[E]);
    }
}
