#include <stdio.h>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<int> S;
map<int, int> ABC;
map<int, int> EFD;

int main() {
    // a*b+c=(e+f)*d ;
    bool outputed = 0;
    int N;
    while (~scanf("%d", &N)) {
        ABC.clear();
        EFD.clear();
        S.resize(N);
        for (int &x : S) {
            scanf("%d", &x);
        }
        // ABC ---------------
        for (int a : S) {
            for (int b : S) {
                for (int c : S) {
                    ABC[a * b + c]++;
                }
            }
        }
        // ABC ---------------
        for (int e : S) {
            for (int f : S) {
                for (int d : S) {
                    if (d == 0) continue;
                    EFD[(e + f) * d]++;
                }
            }
        }
        // count -------------
        long long int ans = 0;
        auto i = ABC.begin();
        auto j = EFD.begin();
        while (i != ABC.end() && j != EFD.end()) {
            if (i->first == j->first) {
                ans += (long long)i->second * j->second;
                i++;
            } else if (i->first < j->first)
                i++;
            else if (i->first > j->first)
                j++;
        }
        // output ------------
        if (outputed) puts("");
        outputed = 1;
        printf("%lld\n", ans);
    }
}
