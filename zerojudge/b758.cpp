#include <stdio.h>

int main() {
    int H, M;
    scanf("%d%d", &H, &M);

    H += 2;
    M += 30;
    if (M >= 60) H++, M -= 60;
    if (H >= 24) H -= 24;

    printf("%02d:%02d\n", H, M);
}
