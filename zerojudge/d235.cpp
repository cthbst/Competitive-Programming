#include <stdio.h>
#include <string.h>

int main() {
    char in[1030];

    while (scanf("%s", &in) && strcmp(in, "0") != 0) {
        int S = in[0] - '0';
        for (int i = 1, len = strlen(in); i < len; i++) {
            S = (10 * S + in[i] - '0') % 11;
        }

        printf("%s is %sa multiple of 11.\n", in, S == 0 ? "" : "not ");
    }
}
