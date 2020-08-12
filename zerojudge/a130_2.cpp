#include <stdio.h>
#include <string.h>

int main() {
    int T, Case = 0;
    scanf("%d", &T);
    char name[10][1000], in[1000];
    while (T-- && printf("Case #%d:\n", ++Case)) {
        int Max = 0, len = 0;
        for (int i = 0, pi; i < 10; i++) {
            scanf("%s%d", in, &pi);
            if (pi > Max) Max = pi, len = 0;
            if (pi < Max) continue;
            sprintf(name[len++], "%s", in);
        }
        for (int i = 0; i < len; i++) {
            puts(name[i]);
        }
    }
}
