#include <stdio.h>
#include <string.h>

#include <stack>
using namespace std;

char in[1000];

int main() {
    while (scanf("%s", in) && strcmp(in, "-1")) {
        if (strlen(in) > 2 && in[0] == '0' && in[1] == 'x') {
            int sum = 0;
            for (int i = 2; in[i]; i++) {
                if ('0' <= in[i] && in[i] <= '9')
                    sum = sum * 16 + in[i] - '0';
                else
                    sum = sum * 16 + in[i] - 'A' + 10;
            }
            printf("%d\n", sum);
        } else {
            int sum = 0;
            for (int i = 0; in[i]; i++) {
                sum = sum * 10 + in[i] - '0';
            }
            stack<int> sta;
            while (sum) {
                sta.push(sum % 16);
                sum /= 16;
            }
            printf("0x");
            while (!sta.empty()) {
                int t = sta.top();
                sta.pop();
                if (t < 10)
                    putchar(t + '0');
                else
                    putchar(t - 10 + 'A');
            }
            puts("");
        }
    }
}
