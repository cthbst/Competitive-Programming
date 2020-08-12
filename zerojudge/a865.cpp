#include <stdio.h>
#include <string.h>

#include <map>
using namespace std;
int main() {
    map<char, int> tra;
    char lib[28] = "ABGDE#ZYHIKLMNXOPQRSTUFC$W3";
    int unit[3] = {1, 10, 100};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            tra[lib[i * 9 + j]] = unit[i] * (j + 1);
        }
    }

    char in[10];
    while (scanf("%s", &in) && in[0] != '.') {
        int ans = 0;
        for (int i = 0; i < strlen(in); i++) ans += tra[in[i]];
        printf("%d\n", ans);
    }
}
