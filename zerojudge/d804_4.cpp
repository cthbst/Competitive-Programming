#include <stdio.h>

#include <algorithm>
using namespace std;

#define Max 50010

int gift[Max], box[Max];

int main() {
    int T, N, M;
    scanf("%d", &T);
    while (T-- && scanf("%d%d", &N, &M)) {
        // input--------------------------------------------
        for (int i = 0; i < N; i++) scanf("%d", &gift[i]);
        for (int i = 0; i < M; i++) scanf("%d", &box[i]);
        // sort---------------------------------------------
        sort(gift, gift + N);
        sort(box, box + M);
        // count--------------------------------------------
        int Ans = 0, wg = 0, wb = 0;
        while (wg < N && wb < M) {
            if (gift[wg] <= box[wb]) {
                Ans++;
                wg++;
                wb++;
            } else {
                wb++;
            }
        }
        // output-------------------------------------------
        if (!Ans)
            printf("Santa Claus wishes you get AC in the next submission.\n");
        else
            printf("%d\n", Ans);
    }
}
