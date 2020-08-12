#include <stdio.h>

char in[10000];

int main() {
    while (~scanf("%s", in)) {
        char c;
        int cnt;
        for (int i = 0; in[i];) {
            c = in[i++];
            cnt = 1;
            while (c == in[i]) {
                cnt++;
                i++;
            }

            if (cnt == 1) {
                putchar(c);
            } else if (cnt == 2) {
                putchar(c);
                putchar(c);
            } else {
                printf("%d%c", cnt, c);
            }
        }
        puts("");
    }
}
