#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

void solve(){
	n = s.size();

	int cnt=0;
	for (int i=0; i+k<=n; i++)if (s[i]=='-'){
		cnt++;
		for (int j=0; j<k; j++){
			if (s[i+j]=='-')s[i+j]='+';
			else s[i+j]='-';
		}
	}
	
	for (int i=n-k+1; i<n; i++){
		if (s[i]!='+')cnt=-1;
	}
	
	if (cnt<0)puts("IMPOSSIBLE");
	else printf("%d\n",cnt);
}

int main(){
	int T; cin >> T;
	
	for (int t=1; t<=T; t++){
		printf("Case #%d: ",t);
		
		cin >> s >> k;
		solve();
	}
}
