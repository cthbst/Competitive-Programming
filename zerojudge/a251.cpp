#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

typedef long long int LL;
int main() {
    int T;
    scanf("%d", &T);

    int N;
    while (T-- && scanf("%d", &N)) {
        vector<LL> vec;
        vec.resize(4);
        for (int i = 0; i < 4; i++) {
            scanf("%lld", &vec[i]);
        }
        for (int i = 4; i < N; i++) {
            vec.push_back(vec[i - 1] + vec[i - 4]);
        }
        sort(vec.begin(), vec.end());

        if (N % 2 == 1)
            printf("%lld\n", vec[N / 2]);
        else
            printf("%lld\n", (vec[N / 2] + vec[N / 2 + 1]) / 2);
    }
}
