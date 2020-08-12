#include <stdio.h>

int main() {
    int T, t = 1, N;
    scanf("%d", &T);

    while (T-- && scanf("%d", &N)) {
        int min = 40000, sum = 0;
        for (int i = 0, inm, ins; i < N; i++) {
            scanf("%d%d", &inm, &ins);
            if (inm * 60 + ins < min) min = inm * 60 + ins;
            sum += inm * 60 + ins;
        }
        // output-----------------------------------------
        sum /= N;
        printf("Track %d:\n", t++);
        printf("Best Lap: %d minute(s) %d second(s).\n", min / 60, min % 60);
        printf("Average: %d minute(s) %d second(s).\n\n", sum / 60, sum % 60);
    }
}
