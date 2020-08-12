#include <stdio.h>
#include <string.h>

void out_aph(char *s) {
    int L = 0, R = 0;
    for (int i = 1; i <= 5; i++) {
        L <<= 1;
        if (s[i] == 'o') L++;
    }
    for (int i = 7; i <= 9; i++) {
        R <<= 1;
        if (s[i] == 'o') R++;
    }
    printf("%c", L * 8 + R);
}

int main() {
    char in[100];
    while (gets(in)) {
        if (strcmp(in, "___________") == 0) continue;
        out_aph(in);
    }
}
