#include <stdio.h>

#include <vector>
using namespace std;
;

struct str {
    int x, y, v;
};

const int MaxN = 130;
int d[MaxN][MaxN];
vector<str> U;

int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    int N, M;
    while (~scanf("%d%d", &N, &M)) {
        // input -------------
        U.clear();
        for (int i = 1; i <= N; i++)
            for (int j = 1, in; j <= M; j++) {
                scanf("%d", &in);
                if (in != 0) U.push_back((str){i, j, in});
            }
        // find Ans ----------
        str Ans = (str){0, 0, 1 << 30};

        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= M; y++) {
                int h = 0;
                for (int i = 0, l = U.size(); i < l; i++) {
                    if (U[i].x == x && U[i].y == y) continue;
                    h += U[i].v * (abs(U[i].x - x) + abs(U[i].y - y));
                }
                if (h < Ans.v) {
                    Ans = (str){x, y, h};
                }
            }
        }

        // output ------------
        printf("%d %d\n", Ans.x, Ans.y);
    }
}
