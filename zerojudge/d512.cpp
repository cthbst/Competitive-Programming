#include <stdio.h>
#include <string.h>

#include <algorithm>
using namespace std;
#define MAX 1000000
int line[MAX], top = 1;
int main() {
    int N, in, T;
    while (~scanf("%d", &N)) {
        line[0] = 0, top = 1;
        while (N--) {
            scanf("%d", &in);
            T = top;
            for (int i = 0; i < T; i++) line[top++] = line[i] + in;
        }
        sort(line, line + top);
        // count----------------------------------
        int count = 0;
        for (int i = 1; i < top; i++)
            if (line[i] - line[i - 1]) count++;
        // output---------------------------------
        printf("%d\n", count);
    }
}
