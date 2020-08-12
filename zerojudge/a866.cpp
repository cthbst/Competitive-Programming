#include <stdio.h>
#include <string.h>

int main() {
    int count[6];
    memset(count, 0, sizeof(count));
    // input
    int in, time = 0;
    while (scanf("%d", &in) && in != 0) {
        count[in]++;
        time++;
    }
    // output
    for (int i = 5; i > 0; i--) {
        printf("%d (%2d) |", i, count[i]);
        for (int j = 0; j < count[i]; j++) printf("=");
        printf("\n");
    }
    double sum = 0.0;
    for (int i = 1; i <= 5; i++) sum += i * (double)count[i];

    printf("Average rating: %.4lf\n", sum / (double)time);
}
