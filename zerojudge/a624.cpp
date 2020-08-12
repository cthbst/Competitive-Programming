#include <stdio.h>
#include <string.h>

int A(char *pas) {
    if (strlen(pas) >= 8) {
        return 1;
    }
    return 0;
}
int B(char *pas) {
    int l = strlen(pas);
    int p = 0, P = 0;

    for (int i = 0; i < l; i++) {
        if ('a' <= pas[i] && pas[i] <= 'z')
            p++;
        else if ('A' <= pas[i] && pas[i] <= 'Z')
            P++;
    }
    if (p * P == 0) return 0;
    return 1;
}
int C(char *pas) {
    int l = strlen(pas);
    int cha = 0, num = 0;

    for (int i = 0; i < l && cha * num == 0; i++) {
        if (('a' <= pas[i] && pas[i] <= 'z') ||
            ('A' <= pas[i] && pas[i] <= 'Z')) {
            cha++;
        } else {
            num++;
        }
    }

    if (cha * num == 0) return 0;
    return 1;
}

int main() {
    char input[132];
    char output[4][20] = {"WEAK", "ACCEPTABLE", "GOOD", "STRONG"};
    while (~scanf("%s", &input)) {
        int ans = A(input) + B(input) + C(input);

        printf("This password is %s\n", output[ans]);
    }
}
