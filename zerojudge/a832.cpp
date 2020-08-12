#include <stdio.h>
#include <stdlib.h>

struct Treap {
    int val;
    int sz;
    Treap *lc, *rc;

    Treap(int val) : val(val) {
        sz = 1;
        lc = rc = nullptr;
    }
    void pull() {
        sz = 1;
        if (lc != nullptr) sz += lc->sz;
        if (rc != nullptr) sz += rc->sz;
    }
};

void Split(Treap *T, Treap *&A, Treap *&B, int k) {
    if (T == nullptr) {
        A = nullptr;
        B = nullptr;
        return;
    }
    int lsz = 1;
    if (T->lc != nullptr) lsz += T->lc->sz;

    if (k < lsz) {
        B = T;
        Split(T->lc, A, B->lc, k);
        B->pull();
    } else {
        A = T;
        Split(T->rc, A->rc, B, k - lsz);
        A->pull();
    }
}
Treap *Merge(Treap *A, Treap *B) {
    if (A == nullptr || B == nullptr) {
        if (A != nullptr)
            return A;
        else
            return B;
    }
    int wA = A->sz, wB = B->sz;
    if (rand() % (wA + wB) < wA) {
        A->rc = Merge(A->rc, B);
        A->pull();
        return A;
    } else {
        B->lc = Merge(A, B->lc);
        B->pull();
        return B;
    }
}

void Show(Treap *t) {
    if (t == nullptr) return;
    Show(t->lc);
    printf("%d ", t->val);
    Show(t->rc);
}

void Delete(Treap *&t) {
    if (t == nullptr) return;
    Delete(t->lc);
    Delete(t->rc);
    delete t;
    t = nullptr;
}

Treap *root = nullptr;

const int maxN = 1030;
int main() {
    int N;
    while (~scanf("%d", &N)) {
        for (int i = 1; i <= N; i++) {
            Treap *x = new Treap(i);
            root = Merge(root, x);
        }

        for (int i = 1; i <= N; i++) {
            Treap *t[maxN];
            for (int j = N; j > 0; j -= i) {
                t[j] = nullptr;
                Split(root, t[j], root, i);
            }
            for (int j = N; j > 0; j -= i) {
                Treap *A, *B;
                Split(t[j], A, B, 1);
                t[j] = Merge(B, A);
                root = Merge(root, t[j]);
            }
        }
        Show(root);
        puts("");
        Delete(root);
    }
}
