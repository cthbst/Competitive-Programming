#include <math.h>
#include <stdio.h>

#include <algorithm>
using namespace std;

int main() {
    int M[3], P[3];
    while (scanf("%d%d%d%d%d%d", &P[0], &P[1], &P[2], &M[0], &M[1], &M[2])) {
        if (M[0] == 0 && M[1] == 0 && M[2] == 0 && P[0] == 0 && P[1] == 0 &&
            P[2] == 0)
            break;
        int KP = max(0, P[1] - M[2]), KM = max(0, M[1] - P[2]);
        if (KM == 0 || (KP != 0 && (int)ceil((double)M[0] / KP) <=
                                       (int)ceil((double)P[0] / KM)))
            printf("You win in %d round(s).\n", (int)ceil((double)M[0] / KP));
        else
            printf("You lose in %d round(s).\n", (int)ceil((double)P[0] / KM));
    }
}
