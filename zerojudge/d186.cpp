#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> S;
    for (int i = 0; i * i <= 200000; i++) {
        S.push_back(i * i);
    }

    int a, b;
    while (~scanf("%d%d", &a, &b) && !(a == 0 && b == 0)) {
        printf("%d\n", upper_bound(S.begin(), S.end(), b) -
                           lower_bound(S.begin(), S.end(), a));
    }
}
