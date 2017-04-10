#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

bool ok(LL s){
	LL mi = 9;
	while (s>0){
		if (s%10>mi)return 0;
		mi = min(mi,s%10);
		s/=10;
	}
	return 1;
}

LL n;
void solve(){
	LL base=1, ans=0;
	for (int i=1; i<=18; i++, base*=10){
		if (base>n)break;
		LL m = (n/base-1)*base+(base-1);
		if (ok(m))ans = max(ans,m);
	}
	if (ok(n))ans=n;
	cout << ans << endl;
}

int main(){
	int T; cin >> T;
	
	for (int t=1; t<=T; t++){
		printf("Case #%d: ",t);
		cin >> n;
		solve();
	}
}
