#include <stdio.h>
#include <string.h>

#include <iostream>
#include <stack>
using namespace std;

char in[1000], c;

int main() {
    // freopen("in.txt","r",stdin) ;
    int T;
    scanf("%d", &T);
    cin.getline(in, sizeof(in));
    while (T-- && cin.getline(in, sizeof(in))) {
        stack<char> sta;
        bool error = 0;
        for (int i = 0; 0 != (c = in[i]) && !error; i++) {
            if (c == '(' || c == '[')
                sta.push(c);
            else {
                if (c == ')') {
                    if (sta.empty() || sta.top() != '(')
                        error = 1;
                    else
                        sta.pop();
                } else if (c == ']') {
                    if (sta.empty() || sta.top() != '[')
                        error = 1;
                    else
                        sta.pop();
                }
            }
        }
        if (!sta.empty()) error = 1;
        while (!sta.empty()) sta.pop();
        puts(error ? "No" : "Yes");
    }
}
