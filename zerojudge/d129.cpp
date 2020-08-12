#include <stdio.h>

#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef unsigned long long int LL;

int main() {
    vector<LL> vec;
    static priority_queue<LL> que;
    static map<LL, bool> S;
    que.push(-1);
    S[1] = 1;
    for (int i = 0; i < 1500; i++) {
        LL u = -que.top();
        que.pop();
        vec.push_back(u);
        if (S[2 * u] == 0) {
            S[2 * u] = 1;
            que.push(-2 * u);
        }
        if (S[3 * u] == 0) {
            S[3 * u] = 1;
            que.push(-3 * u);
        }
        if (S[5 * u] == 0) {
            S[5 * u] = 1;
            que.push(-5 * u);
        }
    }
    printf("The 1500'th ugly number is %lld.", vec[1499]);
}
