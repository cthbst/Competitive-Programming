#include <stdio.h>

#include <map>
#include <string>
using namespace std;

int main() {
    int N;
    while (~scanf("%d", &N)) {
        map<string, int> S;

        char in[30];
        int t = 0;
        while (N-- && scanf("%s", &in)) {
            if (S[(string)in] == 0) {
                printf("New! %d\n", ++t);
                S[(string)in] = t;
            } else {
                printf("Old! %d\n", S[(string)in]);
            }
        }
    }
}
