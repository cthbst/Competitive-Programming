#include <stdio.h>
#include <string.h>

int main() {
    int T, count[300];
    char S1[3000], S2[3000];

    scanf("%d", &T);
    gets(S1);

    while (T-- && gets(S1) && gets(S2)) {
        memset(count, 0, sizeof(count));
        for (int i = 0; i < strlen(S1); i++) {
            count[(int)S1[i]]++;
            count[(int)S2[i]]--;
        }

        bool ok = 1;
        for (int i = 0; i < 300 && ok; i++)
            if (count[i] != 0) ok = 0;

        printf("%s\n", ok ? "possible" : "impossible");
    }
}
