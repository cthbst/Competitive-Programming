// by cthbst
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int n, m;
char G[MAXN][MAXN];

bool input(){
	cin >> n >> m;
	
	if (n==0 && m==0)return 0;
	memset(G,0,sizeof(G));
	for (int i=1; i<=n; i++){
		scanf("%s",G[i]+1);
	}
	return 1;
}

bool ok(int x, int y ){
	return 1<=x && x<=n && 1<=y && y<=m;
}

bool is_bomb(int x,int y){
	if (!ok(x,y))return 0;
	return G[x][y]=='*';
}

void solve(){
	for (int i=1 ;i<=n ;i++ ){
		for (int j=1; j<=m; j++){
			if (G[i][j]=='*')continue;
			
			int cnt=0;
			for (int x=i-1; x<=i+1; x++){
				for (int y=j-1; y<=j+1; y++){
					cnt += is_bomb(x,y);
				}
			}
			G[i][j] = '0'+cnt;
		}
	}
}

void output(){
	for (int i=1; i<=n; i++ ){
		puts(G[i]+1);
	}
}

int main(){
	int T=0;
	while (input()){
		solve();
		if (T!=0)puts("");
		printf("#%d:\n",++T);
		output();
	}
}
