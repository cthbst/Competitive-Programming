#include <stdio.h>
#include <string.h>

int main() {
    char in[10000];

    while (gets(in)) {
        int len = strlen(in);

        int count = 0, l = 0;
        for (int i = 0; i < len; i++) {
            int t = (int)in[i];
            if (('A' <= t && t <= 'Z') || ('a' <= t && t <= 'z')) {
                l++;
            } else {
                if (l > 0) count++;
                l = 0;
            }
        }
        if (l > 0) count++;
        printf("%d\n", count);
    }
}
