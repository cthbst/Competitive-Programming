#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;
struct Dinic{	//O(VVE)
	static const int MAXV = 5003;
	struct Edge{
		int from, to, cap, flow;
	};

	int n, m, s, t, d[MAXV], cur[MAXV];
	vector<Edge> edges;
	vector<int> G[MAXV];

	void init(int _n=MAXV){
		edges.clear();
		for (int i=0; i<_n; i++)G[i].clear();
	}

	void AddEdge(int from, int to, int cap){
		edges.push_back( {from,to,cap,0} );
		edges.push_back( {to,from,0,0} );
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	
	bool dinicBFS(){
		memset(d,-1,sizeof(d));
		queue<int> que;
		que.push(s); d[s]=0;
		while (!que.empty()){
			int u = que.front(); que.pop();
			for (int ei:G[u]){
				Edge &e = edges[ei];
				if (d[e.to]<0 && e.cap>e.flow){
					d[e.to]=d[u]+1;
					que.push(e.to);
				}
			}
		}
		return d[t]>=0;
	}

	int dinicDFS(int u, int a){
		if (u==t || a==0)return a;
		int flow=0, f;
		for (int &i=cur[u]; i<(int)G[u].size(); i++){
			Edge &e = edges[ G[u][i] ];
			if (d[u]+1!=d[e.to])continue;
			f = dinicDFS(e.to, min(a, e.cap-e.flow) );
			if (f>0){
				e.flow += f;
				edges[ G[u][i]^1 ].flow -=f;
				flow += f;
				a -= f;
				if (a==0)break;
			}
		}
		return flow;
	}

	int maxflow(int s, int t){
		this->s = s, this->t = t;
		int flow=0, mf;
		while ( dinicBFS() ){
			memset(cur,0,sizeof(cur));
			while ( (mf=dinicDFS(s,INF)) )flow+=mf;
		}
		return flow;
	}
}dinic;

// s=0, t=1;
int fnd(int id ,int out=0){
	// out=0 入點 out=1 出點
	static int spr=1;
	//spr=2 時每個點分成入點,出點
	return id*spr+out+2;
}

const int MAXN = 102;
int N,M;
int a[MAXN];
pair<int,int> link[MAXN];
set<int> prime;

void input(){
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++){
        scanf("%d",&a[i]);
    }
    for (int i=0; i<M; i++){
        scanf("%d %d", &link[i].first, &link[i].second);
        link[i].first--;
        link[i].second--;
    }
}

void factorization(int n){
    for (int i=2; i*i<=n; i++){
        if (n%i)continue;
        prime.insert(i);
        while (n%i==0)n/=i;
    }
    if (n>1)prime.insert(n);
}

int cntp(int n, int p){
    int ans=0;
    while (n%p==0){
        ans++;
        n/=p;
    }
    return ans;
}

int main(){
    input();
    for (int i=0; i<N; i++){
        factorization(a[i]);
    }
    int ans=0;
    for (int p:prime){
        dinic.init();
        int source=0, sink=1;
        for (int i=0; i<N; i+=2){
            int w = cntp(a[i],p);
            dinic.AddEdge(source,fnd(i),w);
        }
        for (int i=1; i<N; i+=2){
            int w = cntp(a[i],p);
            dinic.AddEdge(fnd(i),sink,w);
        }
        for (int i=0; i<M; i++){
            int u=link[i].first;
            int v=link[i].second;
            if (u%2)swap(u,v);
            dinic.AddEdge(fnd(u),fnd(v),INF);
        }
        ans += dinic.maxflow(source,sink);
    }
    printf("%d\n",ans);
}
