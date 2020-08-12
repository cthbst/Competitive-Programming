#include <stdio.h>

#include <vector>
using namespace std;

const int INF = 2147483647;

vector<int> LIS;
void join(int x) {
    int l = LIS.size();

    int L = 0, R = l - 1;
    while (L != R) {
        int M = (L + R) / 2;
        if (LIS[M] <= x)
            L = M + 1;
        else
            R = M;
    }

    LIS[L] = x;
    if (L == l - 1) LIS.push_back(INF);
}

int main() {
    int T;
    scanf("%d", &T);

    int N, M;
    while (T-- && scanf("%d%d", &N, &M)) {
        LIS.clear();
        LIS.push_back(INF);
        // input -------------
        for (int i = 0, ai; i < N; i++) {
            scanf("%d", &ai);
            if (ai >= M)
                join(2 * ai), join(ai);
            else if (2 * ai >= M)
                join(2 * ai);
        }

        // output ------------
        printf("%d\n", LIS.size() - 1);
    }
}
