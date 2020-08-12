#include <stdio.h>
#include <string.h>

char in[17][32];
int count[17][31];
int main() {
    for (int i = 1; i <= 15; i++) {
        scanf("%s", in[i] + 1);
    }

    memset(count, 0, sizeof(count));

    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 30; j++)
            if (in[i][j] == '*') {
                for (int x = -1; x <= 1; x++)
                    for (int y = -1; y <= 1; y++) count[i + x][j + y]++;
            }
    }

    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 30; j++) {
            if (in[i][j] == '*')
                printf("*");
            else if (count[i][j] > 0)
                printf("%d", count[i][j]);
            else
                printf(".");
        }
        printf("\n");
    }
}
