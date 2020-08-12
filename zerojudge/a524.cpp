#include <stdio.h>

#include <algorithm>
using namespace std;

int main() {
    int N, a[10];

    while (~scanf("%d", &N)) {
        for (int i = 0; i < N; i++) a[i] = i;

        do {
            for (int i = 0; i < N; i++) printf("%d", N - a[i]);
            printf("\n");
        } while (next_permutation(a, a + N));
    }
}
