// by cthbst
#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;
const int MAXN = 30;


int n, m;
int dis[MAXN][MAXN];

void input(){
	cin >> n >> m;

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}

	for (int i=0, u, v, w; i<m; i++){
		cin >> u >> v >> w;
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
	}
}

void solve(){
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}

int main(){
	input();
	solve();
	if (dis[1][n]==INF)puts("-1");
	else cout << dis[1][n];
}
