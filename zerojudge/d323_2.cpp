#include <stdio.h>

#include <algorithm>
using namespace std;

int a[10000000];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a, a + N);
    for (int i = 0; i < N; i++) printf("%d ", a[i]);
    puts("");
}
