#include <stdio.h>

char lib[] = "22233344455566677778889999";
char in[50];

int main() {
    while (~scanf("%s", in)) {
        for (int i = 0; in[i]; i++) {
            if ('A' <= in[i] && in[i] <= 'Z') in[i] = lib[in[i] - 'A'];
        }
        puts(in);
    }
}
