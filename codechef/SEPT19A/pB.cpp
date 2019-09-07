#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int lgN = 18;
const int MAXV = 1000006;

struct SP{ //sparse table
	int Sp[lgN][MAXN];
	void build(int n, int *a){ // 0 base
		for (int i=0 ;i<n; i++) Sp[0][i]=a[i];

		for (int h=1; h<lgN; h++){
			int len = 1<<(h-1), i=0;
			for (; i+len<n; i++)
				Sp[h][i] = __gcd(Sp[h-1][i], Sp[h-1][i+len]);
			for (; i<n; i++)
				Sp[h][i] = Sp[h-1][i];
		}
	}
	int query(int l, int r){
		int h = __lg(r-l+1);
		int len = 1<<h;
		return __gcd(Sp[h][l], Sp[h][r-len+1]);
	}
} Box;

int n;
int *a = Box.Sp[0];
long long cnt[MAXV];

int findR(int L, int Val, int l, int r){
    if (Box.query(L, r) == Val) return r;

    while (l!=r){
        int mid = (l+r)>>1;
        if (Box.query(L, mid) != Val) r = mid;
        else l = mid+1;
    }
    return r - 1;
}

void init(){
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    Box.build(n, a);

    for (int L=0; L<n; L++){
        int l = L;
        while (l < n){
            int val = Box.query(L, l);
            int r = findR(L, val, l, n-1);
            if (val < MAXV){
                cnt[val] += r-l+1;
            }
            l = r+1;
        }
    }
    for (int i=MAXV-1; i>=1; i--){
        for (int j=i+i; j<MAXV; j+=i){
            cnt[j] += cnt[i];
        }
    }
}

void solve(){
    int Q; cin >> Q;
    while (Q--){
        int k; cin >> k;
        cout << cnt[k] << '\n';
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    init();
    solve();
}
