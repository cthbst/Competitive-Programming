#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL N, K;

void solve(){
	priority_queue<LL> pq;
	map<LL,LL> cnt;

	pq.push(N);
	cnt[N]=1;

	while (!pq.empty()){
		LL u = pq.top(); pq.pop();
		if (cnt[u]>=K){
			cout << u/2 << " " << (u-1)/2 << endl;
			break;
		}
		else {
			K -= cnt[u];
			if (cnt[u/2]==0)pq.push(u/2);
			cnt[u/2] += cnt[u];

			if (cnt[(u-1)/2]==0)pq.push((u-1)/2);
			cnt[(u-1)/2] += cnt[u];
		}
	}
}

int main(){
	int T; cin >> T;
	
	for (int t=1; t<=T; t++){
		printf("Case #%d: ",t);
		cin >> N >> K;
		solve();
	}
}
