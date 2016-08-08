// by cthbst
#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;
const int MAXN = 100;

int n, m;
char A[MAXN] ,B[MAXN];
int dp[MAXN][MAXN];

void in(char *o){
	string s;
	getline(cin,s);
	sprintf(o+1,"%s",s.c_str());
}

void input(){
	in(A), in(B);
	n=strlen(A+1);
	m=strlen(B+1);
}

void solve(){
	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			dp[i][j]=INF;
		}
	}

	dp[0][0]=0;
	for (int i=0; i<=n; i++)dp[i][0]=i*3;
	for (int i=0; i<=m; i++)dp[0][i]=i*4;

	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (A[i]==B[j])dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=dp[i-1][j-1]+5;

			dp[i][j] = min(dp[i][j],dp[i-1][j]+3);
			dp[i][j] = min(dp[i][j],dp[i][j-1]+4);
		}
	}
}

int main(){
	input();
	solve();
	cout << dp[n][m] <<endl;
}
