#include <stdio.h>
int in[100];
void print_all(int n, int m, int *A, int top) {
    if (m == top) {
        for (int i = 0; i < m; i++) {
            printf("%d ", in[A[i]]);
        }
        printf("\n");
    } else if (top == 0) {
        for (int i = 0; i < n; i++) {
            A[top] = i;
            print_all(n, m, A, top + 1);
        }
    } else {
        for (int i = A[top - 1] + 1; i < n - m + 1 + top; i++) {
            for (int j = 0; j < top; j++) {
                if (A[j] == i) break;
            }
            A[top] = i;
            print_all(n, m, A, top + 1);
        }
    }
}

int main() {
    int n, m;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }
        scanf("%d", &m);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (in[i] > in[j]) {
                    int t = in[i];
                    in[i] = in[j];
                    in[j] = t;
                }
            }
        }
        int A[100];
        print_all(n, m, A, 0);
        printf("\n");
    }
}
