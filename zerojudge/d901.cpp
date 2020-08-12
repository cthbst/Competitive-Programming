#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator-(const Point &o) const {
        return Point(x - o.x, y - o.y);
    }
};
int dis2(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
Point A, B;
bool cmp(Point p, Point q) {
    return dis2(A, p) < dis2(A, q);
}

int main() {
    scanf("%d%d%d%d", &A.x, &A.y, &B.x, &B.y);
    int N;
    scanf("%d", &N);
    vector<Point> S(N);
    for (Point &p : S) {
        scanf("%d%d", &p.x, &p.y);
    }
    sort(S.begin(), S.end(), cmp);

    int ans = 1 << 29;
    int maxB = 0;
    for (int i = N - 1; i >= 0; i--) {
        ans = min(ans, dis2(A, S[i]) + maxB);
        maxB = max(maxB, dis2(B, S[i]));
    }
    ans = min(ans, maxB);
    printf("%d\n", ans);
}
