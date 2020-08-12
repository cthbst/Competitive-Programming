#include <stdio.h>
#include <string.h>

int main() {
    char s[20], count = 0;
    while (scanf("%s", s) && s[0] != '#') {
        printf("Case %d: ", ++count);
        if (!strcmp(s, "HELLO"))
            printf("ENGLISH");
        else if (!strcmp(s, "HOLA"))
            printf("SPANISH");
        else if (!strcmp(s, "HALLO"))
            printf("GERMAN");
        else if (!strcmp(s, "BONJOUR"))
            printf("FRENCH");
        else if (!strcmp(s, "CIAO"))
            printf("ITALIAN");
        else if (!strcmp(s, "ZDRAVSTVUJTE"))
            printf("RUSSIAN");
        else
            printf("UNKNOWN");
        printf("\n");
    }
}
