#include <bits/stdc++.h>
using namespace std;

struct Dice {
    vector<int> f;  // face
    Dice() {
        //     [4]
        // [3] [0] [1] [2]
        //     [5]
        f = {1, 2, 6, 5, 3, 4};
    }
    void rotateToFront() {
        //     [4]                 [2]
        // [3] [0] [1] [2] =>  [3] [4] [1] [5]
        //     [5]                 [0]
        f = {f[4], f[1], f[5], f[3], f[2], f[0]};
    }
    void rotateToRight() {
        //     [4]                 [4]
        // [3] [0] [1] [2] =>  [2] [3] [0] [1]
        //     [5]                 [5]
        f = {f[3], f[0], f[1], f[2], f[4], f[5]};
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Dice> dice(n + 1);
    for (int cs = 1; cs <= m; cs++) {
        int a, b;
        cin >> a >> b;
        if (b == -1) {
            dice[a].rotateToFront();
        } else if (b == -2) {
            dice[a].rotateToRight();
        } else {
            swap(dice[a], dice[b]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dice[i].f[0] << (i == n ? '\n' : ' ');
    }
}
