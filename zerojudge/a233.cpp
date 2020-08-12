#include <stdio.h>

#include <queue>
#include <vector>
using namespace std;

void MSFA(vector<int> &a) {
    queue<vector<int> > que;

    for (int i = 0, l = a.size(); i < l; i++) {
        vector<int> e;
        e.push_back(a[i]);
        while (i + 1 < l && a[i + 1] > a[i]) {
            e.push_back(a[i + 1]);
            i++;
        }
        que.push(e);
    }
    while (que.size() > 1) {
        vector<int> A = que.front();
        que.pop();
        vector<int> B = que.front();
        que.pop();
        vector<int> C;

        int AL = A.size(), BL = B.size(), Aw = 0, Bw = 0;

        while (Aw < AL && Bw < BL) {
            if (A[Aw] < B[Bw])
                C.push_back(A[Aw++]);
            else
                C.push_back(B[Bw++]);
        }
        while (Aw < AL) C.push_back(A[Aw++]);
        while (Bw < BL) C.push_back(B[Bw++]);

        que.push(C);
    }

    // return ----------------
    a = que.front();
}

vector<int> a;

int main() {
    int N;
    while (~scanf("%d", &N)) {
        a.resize(N);
        for (int i = 0; i < N; i++) scanf("%d", &a[i]);
        MSFA(a);
        for (int i = 0; i < N; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
