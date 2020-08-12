#include <stdio.h>

#include <stack>
using namespace std;

int print_binary(int n) {
    int cnt = 0;
    stack<int> sta;
    while (n) {
        if (n & 1) cnt++;
        sta.push(n & 1);
        n >>= 1;
    }
    while (!sta.empty()) {
        printf("%d", sta.top());
        sta.pop();
    }
    return cnt;
}

int main() {
    int n;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        printf("The parity of ");
        int s = print_binary(n);
        printf(" is %d (mod 2).\n", s);
    }
}
