#include <stdio.h>
#include <string.h>

int main() {
    char a[50];
    while (memset(a, -1, sizeof(a)) && fgets(a, sizeof(a), stdin)) {
        int i, count = 5;
        for (i = 0; a[i] != '.' && a[i] > 0 && a[i] != '\n'; i++)
            ;
        if (a[i] != '.') {
            a[i] = '.';
            count--;
        }
        for (i; a[i] > 0 && a[i] != '\n'; i++) count--;
        while (count--) a[i++] = '0';
        printf("|");
        for (int j = 0; a[j] > 0 && a[j] != '\n'; j++) printf("%c", a[j]);
        printf("|=");

        if (a[0] != '-') printf("%c", a[0]);
        for (int j = 1; a[j] > 0 && a[j] != '\n'; j++) printf("%c", a[j]);
        printf("\n");
    }
}
