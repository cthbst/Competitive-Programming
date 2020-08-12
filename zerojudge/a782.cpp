#include <stdio.h>
#include <string.h>

#define MAXL 80
char a[MAXL], S[MAXL];
int len = 0, e = 0;
int main() {
    while (gets(a)) {
        if (strcmp(a, "END") == 0) break;

        len = 0;
        e = 0;

        S[len++] = a[0] - 'a' + 'A';
        for (int i = 0, l = strlen(a); i < l; i++) {
            if (a[i] == ' ') {
                i++;
                S[len++] = a[i] - 'a' + 'A';
                e = i;
            }
        }

        S[len] = '\0';
        printf("%s ", S);
        for (int i = e, l = strlen(a); i < l; i++) {
            printf("%c", a[i]);
        }
        printf("\n");
    }
}
