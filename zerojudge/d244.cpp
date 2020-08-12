#include <stdio.h>

#include <map>
using namespace std;

map<int, int> T;

int main() {
    int k;
    while (~scanf("%d", &k)) {
        T[k]++;
        if (T[k] == 3) {
            T.erase(T.find(k));
        }
    }
    printf("%d\n", T.begin()->first);
}
