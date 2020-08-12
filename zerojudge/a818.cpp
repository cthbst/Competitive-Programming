#include <stdio.h>
#define MAX 25
int n, number[MAX], k;
char word[MAX], cpy[MAX];

int main() {
    // input----------------------------------------------------------
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &number[i]);
    scanf("%s%d", &word, &k);
    // cooking--------------------------------------------------------
    while (k--) {
        for (int i = 0; i < n; i++) cpy[i] = word[number[i] - 1];
        cpy[n] = '\0';
        sscanf(cpy, "%s", &word);
    }
    // output---------------------------------------------------------
    printf("%s\n", word);
}
