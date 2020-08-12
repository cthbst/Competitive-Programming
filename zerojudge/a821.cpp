#include <stdio.h>
#include <string.h>

#include <iostream>
#include <map>
#include <string>
using namespace std;

int d[26][26];
string name[30];
int main() {
    memset(d, 0, sizeof(d));
    map<string, int> lib;
    int N, R, num = 0;
    scanf("%d%d", &N, &R);

    for (int i = 0; i < R; i++) {
        char a[30], b[30];
        scanf("%s%s", &a, &b);
        if (lib[(string)a] == 0) lib[(string)a] = ++num, name[num] = (string)a;
        if (lib[(string)b] == 0) lib[(string)b] = ++num, name[num] = (string)b;
        int na = lib[(string)a], nb = lib[(string)b];
        d[na][nb] = 1;
        d[nb][na] = -1;
    }
    for (int i = 1; i <= N; i++) {
        bool ok = 1;
        for (int j = 1; j <= N; j++)
            if (i != j && d[i][j] != 1) {
                ok = 0;
                break;
            }
        if (ok) {
            cout << name[i] << endl;
            break;
        }
    }
}
