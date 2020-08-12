#include <stdio.h>

#include <stack>
#include <vector>
using namespace std;

const int INF = 2000000000;
struct str {
    int h, num;
};
stack<str> sta;

int main() {
    int N;
    scanf("%d", &N);

    long long int Ans = 0;
    while (!sta.empty()) sta.pop();
    sta.push((str){INF, 1});
    for (int i = 0, ai; i < N; i++) {
        scanf("%d", &ai);
        while (sta.top().h < ai) Ans += sta.top().num, sta.pop();
        if (sta.top().h == ai) Ans += sta.top().num;
        if (sta.top().h != ai && sta.size() > 1 || sta.size() > 2) Ans++;
        if (sta.top().h == ai)
            sta.top().num++;
        else
            sta.push((str){ai, 1});
    }
    printf("%lld\n", Ans * 2);
}
