#include <stdio.h>
#include <string.h>

struct BST {
    int x;
    BST *lc, *rc;

    BST(int _x = 0) {
        x = _x;
        lc = rc = NULL;
    }
};

void Add(BST *&a, int val) {
    if (a == NULL) {
        a = new BST(val);
    } else {
        if (val < a->x)
            Add(a->lc, val);
        else
            Add(a->rc, val);
    }
}

void Delete(BST *&a) {
    if (a == NULL) return;
    if (a->lc) Delete(a->lc);
    if (a->rc) Delete(a->rc);
    delete a;
    a = NULL;
}

void Output(BST *a) {
    if (a == NULL) return;
    printf("%d ", a->x);
    Output(a->lc);
    Output(a->rc);
}

BST *root = NULL;

int main() {
    int N;
    while (~scanf("%d", &N)) {
        Delete(root);
        for (int i = 0, in; i < N; i++) {
            scanf("%d", &in);
            Add(root, in);
        }
        Output(root);
        puts("");
    }
}
