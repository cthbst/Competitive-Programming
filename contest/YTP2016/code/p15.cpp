// by cthbst
#include <bits/stdc++.h>
using namespace std ;

const int INF = 1<<29;
const int MAXN = 20;

struct str{
	int to, t, l;
};

int N, M, L;
vector<str> G[MAXN];

void input(){
	cin >> N >> M >> L;
	
	for (int i=0, u ,v ,t, l; i<M; i++){
		scanf("%d %d %d %d",&u ,&v ,&l ,&t);
		G[u].push_back((str){v,t,l});
		G[v].push_back((str){u,t,l});
	}
}

int ans = INF ;

void dfs(int u, int tt, int len, bool *vis){
	if (tt>L || len>=ans)return;
	if (u==N){
		ans = min(ans,len);
		return;
	}

	for (auto x:G[u]){
		int v = x.to, t= x.t, l = x.l;
		if (vis[v])continue;
		vis[v]=1;
		dfs(v,tt+t,len+l,vis);
		vis[v]=0;
	}
}

int main(){
	bool vis[MAXN];
	memset(vis,0,sizeof(vis));

	input();
	vis[1]=1;
	dfs(1,0,0,vis);

	if (ans==INF)puts("-1");
	else cout << ans <<endl;
}
