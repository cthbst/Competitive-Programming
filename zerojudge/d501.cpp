#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;

int main() {
    int N;

    while (~scanf("%d", &N)) {
        a.resize(N);
        for (int &x : a) scanf("%d", &x);
        sort(a.begin(), a.end());
        if (N % 2 == 1) {
            int m = N / 2;
            printf("A=%d\n", a[m]);
        } else {
            int m = N / 2;
            printf("A");
            for (int i = a[m - 1]; i <= a[m]; i++) {
                if (i == a[m - 1])
                    printf("=");
                else
                    printf("、");
                printf("%d", i);
            }
            puts("");
        }
    }
}
