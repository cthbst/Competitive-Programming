#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct str {
    int A, B, w, num;
};
map<string, int> Map;
map<int, string> reMap;
bool cmp(str a, str b) {
    return a.w < b.w || (a.w == b.w && a.num < b.num);
}

int fa[100];
str E[100];
int Ans[100];

int root(int x) {
    if (fa[x] == x) return x;
    return root(fa[x]);
}

bool cmp2(int a, int b) {
    return E[a].A < E[b].A || (E[a].A == E[b].A && E[a].B < E[b].B);
}

int main() {
    int N, M;

    while (~scanf("%d%d", &N, &M)) {
        Map.clear();
        reMap.clear();
        // input -------------

        char A[30], B[30];
        for (int i = 0; i < M; i++) {
            scanf("%s%s%d", &A, &B, &E[i].w);

            if (Map[(string)A] == 0) {
                char c;
                int in;
                sscanf(A, "%c%d", &c, &in);
                Map[(string)A] = in;
                reMap[in] = (string)A;
            }
            E[i].A = Map[(string)A];

            if (Map[(string)B] == 0) {
                char c;
                int in;
                sscanf(B, "%c%d", &c, &in);
                Map[(string)B] = in;
                reMap[in] = (string)B;
            }
            E[i].B = Map[(string)B];
            E[i].num = i;
        }
        sort(E, E + M, cmp);

        // MST ---------------
        for (int i = 1; i <= N; i++) fa[i] = i;

        int Ansl = 0, count = 0;
        for (int i = 0; i < M; i++) {
            int a = root(E[i].A);
            int b = root(E[i].B);
            if (a == b) continue;

            fa[b] = a;
            Ans[Ansl++] = i;
            count += E[i].w;
        }
        // output ------------
        sort(Ans, Ans + Ansl, cmp2);

        for (int i = 0; i < Ansl; i++) {
            cout << "(" << reMap[E[Ans[i]].A] << " " << reMap[E[Ans[i]].B]
                 << ") ";
        }
        printf("\n%d\n", count);
    }
}
