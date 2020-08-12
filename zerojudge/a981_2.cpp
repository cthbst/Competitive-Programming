#include <stdio.h>
#include <string.h>

int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void out(int n) {
    if (n >= 10)
        printf("%d", n);
    else
        printf("0%d", n);
}

int main() {
    int T, D[2][5];
    char input[100];
    scanf("%d", &T);
    gets(input);
    while (T--) {
        // input----------------------------------
        gets(input);
        for (int i = 0, count = 0; i < strlen(input); i++) {
            if (input[i] <= '9' && input[i] >= '0') {
                sscanf(input + i, "%d", &D[count / 5][count % 5]);
                count++;
                i++;
            }
        }
        // transform------------------------------
        int S[2][2];
        for (int i = 0; i < 2; i++) {
            S[i][0] = D[i][1];
            for (int j = 0; j < D[i][0] - 1; j++) S[i][0] += m[j];
            S[i][1] = D[i][2] * 3600 + D[i][3] * 60 + D[i][4];
        }
        // output --------------------------------
        int anss = S[1][1] - S[0][1] + 86400 * (S[1][0] - S[0][0]);
        if (anss < 0) {
            anss *= -1;
            printf("-");
        }
        //-1 10:17:36
        printf("%d ", anss / 86400);
        anss %= 86400;
        out(anss / 3600);
        anss %= 3600;
        printf(":");
        out(anss / 60);
        printf(":");
        out(anss % 60);
        printf("\n");
    }
}
