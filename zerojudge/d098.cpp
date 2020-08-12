#include <stdio.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

char in[10000];
bool is_number(const char *s) {
    if ('0' <= s[0] && s[0] <= '9' || s[0] == '-') {
        for (int i = 0; s[i]; i++) {
            if ('0' <= s[i] && s[i] <= '9')
                continue;
            else
                return 0;
        }
        return 1;
    } else
        return 0;
}
int main() {
    while (cin.getline(in, sizeof(in))) {
        stringstream s;
        s << in;
        int sum = 0;
        string x;

        while (s >> x) {
            if (is_number(x.c_str())) {
                stringstream ss;
                ss << x;
                int add;
                ss >> add;
                sum += add;
            }
        }
        printf("%d\n", sum);
    }
}
