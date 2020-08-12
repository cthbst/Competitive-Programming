#include <stdio.h>
#include <stdlib.h>

struct Treap {
    int x, sz;
    Treap *lc, *rc;
    Treap(int _x) {
        x = _x;
        sz = 1;
        lc = rc = nullptr;
    }
    void pull() {
        sz = 1;
        if (lc != nullptr) sz += lc->sz;
        if (rc != nullptr) sz += rc->sz;
    }
};

Treap *Merge(Treap *a, Treap *b) {
    if (a == nullptr || b == nullptr) return (a == nullptr ? b : a);
    if (rand() % (a->sz + b->sz) < a->sz) {
        a->rc = Merge(a->rc, b);
        a->pull();
        return a;
    } else {
        b->lc = Merge(a, b->lc);
        b->pull();
        return b;
    }
}
void Split(Treap *t, Treap *&a, Treap *&b, int k) {
    if (t == nullptr) {
        a = b = nullptr;
        return;
    }
    // a[i] <=k
    if (k < t->x) {
        b = t;
        Split(t->lc, a, b->lc, k);
        b->pull();
    } else {
        a = t;
        Split(t->rc, a->rc, b, k);
        a->pull();
    }
}
void Del(Treap *&t) {
    if (t == nullptr) return;
    Del(t->lc);
    Del(t->rc);
    delete t;
    t = nullptr;
}

Treap *root = nullptr;
int main() {
    int N;
    while (~scanf("%d", &N)) {
        for (int i = 0, score; i < N; i++) {
            scanf("%d", &score);
            Treap *a, *b;
            Split(root, a, b, score);
            b = Merge(new Treap(score), b);
            printf("%d\n", b->sz);
            root = Merge(a, b);
        }
        Del(root);
    }
}
