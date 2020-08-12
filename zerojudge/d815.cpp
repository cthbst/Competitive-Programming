#include <stdio.h>

int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        puts((a ^ b) == 0 ? "= =\"" : ">\\\\\\<");
    }
}
