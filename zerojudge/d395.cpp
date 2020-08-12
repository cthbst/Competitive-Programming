#include <stdio.h>
#include <string.h>

#include <vector>
using namespace std;

typedef long long int LL;
char out[100000];
struct Int {
    static const int base = 1000000;
    vector<LL> e;
    Int(LL a = 0) {
        do {
            e.clear();
            e.push_back(a % base);
            a /= base;
        } while (a);
    }
    Int(char *s) {
        int len = strlen(s);
        for (int i = len - 1; i >= 0;) {
            LL sum = 0, b = 1;
            for (int j = 0; j < 6 && i >= 0; j++, i--) {
                sum += (s[i] - '0') * b;
                b *= 10;
            }
            e.push_back(sum);
        }
    }
    Int operator*(const Int &o) const {
        Int re;
        re.e.resize(e.size() + o.e.size() + 2);
        fill(re.e.begin(), re.e.end(), 0);
        for (int i = 0; i < e.size(); i++) {
            for (int j = 0; j < o.e.size(); j++) {
                re.e[i + j] += e[i] * o.e[j];
            }
        }
        for (int i = 0; i < re.e.size() - 1; i++) {
            re.e[i + 1] += re.e[i] / base;
            re.e[i] %= base;
        }
        int sz = re.e.size();
        while (sz > 1 && re.e[sz - 1] == 0) re.e.resize(--sz);
        return re;
    }
    bool operator<(const Int &o) const {
        if (e.size() != o.e.size()) return e.size() < o.e.size();
        for (int i = e.size() - 1; i >= 0; i--) {
            if (e[i] != o.e[i]) return e[i] < o.e[i];
        }
        return 0;
    }
    Int operator--() {
        e[0]--;
        int w = 0;
        while (e[w] < 0) e[w + 1]--, e[w] += base;
        return *this;
    }
    Int operator++() {
        e[0]++;
        int sz = e.size(), w = 0;
        while (e[w] >= base) {
            e[w] -= base;
            if (w + 1 == sz) e.resize(sz + 1);
            e[w]++;
        }
        return *this;
    }
    void output() {
        int sz = e.size() - 1;
        int len = 0;
        sprintf(out, "%lld", e[sz--]);
        len = strlen(out);
        while (sz >= 0) {
            sprintf(out + len, "%06lld", e[sz--]);
            len += 6;
        }
    }
};

Int Pow(Int a, int n) {
    Int re(1);
    while (n) {
        if (n % 2 == 1) re = re * a;
        a = a * a;
        n >>= 1;
    }
    return re;
}

int main() {
    char s[120];
    while (~scanf("%s", s)) {
        // n*(n-1)+2
        if (strcmp(s, "0") == 0) {
            puts("1");
            continue;
        }
        Int a(s);
        Int b = a;
        --b;
        a = a * b;
        ++a;
        ++a;
        a.output();
        puts(out);
    }
}
