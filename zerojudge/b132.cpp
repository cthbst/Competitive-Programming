#include <stdio.h>
#include <string.h>

int s, t, w;
char in[50];
bool A[50];

void out_next() {
    int count = 0;

    for (int i = t; i > s; i--) {
        if (A[i] == 0 && A[i - 1] == 1) {
            A[i - 1] = 0;
            A[i] = 1;
            for (int j = t; j > i; j--) A[j] = 0;
            while (count > 0) A[i + count--] = 1;
            for (int j = s; j <= t; j++) {
                if (A[j] == 1) printf("%c", 'a' + j - 1);
            }
            printf("\n");
            return;
        } else if (A[i] == 1)
            count++;
    }
}

int main() {
    memset(A, 0, sizeof(A));
    while (~scanf("%d%d%d%s", &s, &t, &w, &in)) {
        for (int i = 0; i < strlen(in); i++) {
            A[in[i] - 'a' + 1] = 1;
        }
        for (int i = 0; i < 5; i++) {
            out_next();
        }
    }
}
