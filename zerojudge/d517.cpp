#include <stdio.h>
#include <string.h>
int Hash[26 * 26 * 26 * 26];

int main() {
    int N;
    while (~scanf("%d", &N)) {
        int t = 0;
        memset(Hash, 0, sizeof(Hash));

        char in[5];
        for (int i = 0; i < N; i++) {
            scanf("%s", &in);
            int c = 0;
            for (int j = strlen(in) - 1; j >= 0; j--) {
                c = c * 26 + in[j] - 'a';
            }

            if (Hash[c] == 0) {
                Hash[c] = ++t;
                printf("New! %d\n", Hash[c]);
            } else {
                printf("Old! %d\n", Hash[c]);
            }
        }
    }
}
