#include <stdio.h>
#include <string.h>

char Name[30][100];
char Color[30][100];

int main() {
    int N, M;

    bool output_flag = 0;
    while (~scanf("%d%d", &N, &M)) {
        for (int i = 0; i < N; i++) {
            scanf("%s%s", Name[i], Color[i]);
        }
        if (output_flag) puts("");
        for (int i = 0; i < M; i++) {
            char order[10], c[100];
            scanf("%s%s", order, c);
            if (strcmp(order, "brand") == 0) {
                for (int i = 0; i < N; i++)
                    if (strcmp(c, Name[i]) == 0) {
                        printf("%s %s\n", Name[i], Color[i]);
                    }
            } else {
                for (int i = 0; i < N; i++)
                    if (strcmp(c, Color[i]) == 0) {
                        printf("%s %s\n", Name[i], Color[i]);
                    }
            }
        }
        output_flag = 1;
    }
}
