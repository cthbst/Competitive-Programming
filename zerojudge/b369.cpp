#include <stdio.h>
#include <string.h>

#include <vector>
using namespace std;

vector<int> Prime;

void build_Prime(int n) {
    static bool p[1 << 16];
    memset(p, 1, sizeof(p));

    for (int i = 2; i <= n; i++)
        if (p[i]) {
            Prime.push_back(i);
            for (int j = i + i; j <= n; j += i) {
                p[j] = 0;
            }
        }
}

int main() {
    int n;
    scanf("%d", &n);
    build_Prime(n);

    printf("%d!=", n);
    for (int p : Prime) {
        if (p != 2) putchar(' ');
        int sum = 0, m = n;
        while (m) {
            sum += m / p;
            m /= p;
        }
        printf("%d", sum);
    }
    puts("");
}
