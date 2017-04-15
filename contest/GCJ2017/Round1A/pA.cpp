#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;

int n, m;
char C[MAXN][MAXN];

void input(){
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> C[i];
}

void solve(){
	for (int i=0; i<n; i++){
		for (int j=1; j<m; j++)if (C[i][j]=='?'){
			C[i][j] = C[i][j-1];
		}
		for (int j=m-2; j>=0; j--)if (C[i][j]=='?'){
			C[i][j] = C[i][j+1];
		}
	}
	for (int i=0; i<m; i++){
		for (int j=1; j<n; j++)if (C[j][i]=='?'){
			C[j][i] = C[j-1][i];
		}
		for (int j=n-2; j>=0; j--)if (C[j][i]=='?'){
			C[j][i] = C[j+1][i];
		}
	}
}

int main(){
	int T; cin >> T;
	
	for (int t=1; t<=T; t++){
		printf("Case #%d:\n",t);
		input();
		solve();
		for (int i=0; i<n; i++)cout << C[i] << endl;
	}
}
