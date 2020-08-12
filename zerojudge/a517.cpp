#include <stdio.h>

#include <algorithm>
using namespace std;

int main() {
    unsigned long long int a, b, c;
    while (~scanf("%llu%llu%llu", &a, &b, &c)) {
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        printf("%llu\n", b - a + c);
    }
}
