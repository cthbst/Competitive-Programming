#include <stdio.h>
#include <string.h>

#define MAXL 132
char in[MAXL];
int w[MAXL];
int main() {
    while (~scanf("%s", &in)) {
        // add '.'------------------------------------------
        if (strchr(in, '.') == NULL) {
            in[strlen(in) + 1] = '\0';
            in[strlen(in)] = '.';
        }
        int point = strchr(in, '.') - in;
        // n-[n]--------------------------------------------
        memset(w, 0, sizeof(w));
        for (int i = point + 1, t = 0; i + t < strlen(in) && t < 3; t++) {
            w[2 - t] = in[i + t] - '0';
        }
        //[n]----------------------------------------------
        int len = 3;
        for (int i = point - 1; i >= 0; i--)
            if (in[i] != '-') {
                w[len++] = in[i] - '0';
            }
        // 4out5add-----------------------------------------
        if (w[0] >= 5) w[1]++;
        for (int i = 1; i < len; i++) {
            w[i + 1] += w[i] / 10;
            w[i] %= 10;
        }
        if (w[len] > 0) len++;
        // output-------------------------------------------
        bool neg = (in[0] == '-' ? 1 : 0);
        if (len == 4 && w[1] == 0 && w[2] == 0 && w[3] == 0) neg = 0;
        if (neg) printf("-");

        while (len > 3) printf("%d", w[--len]);
        printf(".%d%d\n", w[2], w[1]);
    }
}
