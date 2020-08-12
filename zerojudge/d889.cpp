#include <stdio.h>
#define MAX 100 + 5
int time[MAX];
int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) scanf("%d", &time[i]);
    int out = 0, ok = 1;
    for (int i = 0; i < N; i++) {
        if (time[i] <= out)
            out += 5;
        else if (out + 30 < time[i]) {
            out += 30;
            ok = 0;
            break;
        } else {
            out = time[i] + 4;
        }
    }
    if (time[0] > 29)
        printf("30");
    else
        printf("%d\n", out + 1 + ok * 30);
}
