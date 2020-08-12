#include <math.h>
#include <stdio.h>
#include <string.h>
int List[50000];
int pList[6000];

int is_prime(int p) {
    if (p == 1) return 1;
    int k = floor(sqrt(p) + 0.5);

    for (int i = 2; i <= k; i++) {
        if (p % i == 0) return 1;
    }
    return 0;
}

void set_List() {
    memset(List, 0, 50000);

    int k = floor(sqrt(50000) + 0.5);

    for (int i = 2; i <= k; i++) {
        if (is_prime(i) == 0) {
            int a = 50000 / i;
            while (a--) List[a * i] = 1;
            List[i] = 0;
        }
    }
    List[0] = 1;
    List[1] = 1;
}

int f = 0;
void set_pList() {
    memset(pList, 0, 6000);
    for (int i = 0; i < 50000; i++)
        if (List[i] == 0) {
            pList[f++] = i;
        }
}

int pt_big_prime(int p) {
    if (p == 1) return 1;
    int k = floor(sqrt(p) + 0.5);
    for (int i = 0; pList[i] <= k; i++) {
        if (p % pList[i] == 0) return 1;
    }
    return 0;
}
int main() {
    set_List();
    set_pList();
    int p;
    while (scanf("%d", &p) && p != 0) {
        printf("%d\n", pt_big_prime(p));
    }
}
