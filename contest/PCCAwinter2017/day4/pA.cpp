#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Edge{
    int u, v, w;
};

const int MAXN = 10004;
const int INF = 1<<29;

int N, K;
vector<Edge> G[MAXN];
bool vis[MAXN];
int sz[MAXN];

void init(){
    for (int i=1; i<=N; i++){
        G[i].clear();
        vis[i]=0;
    }
}

void input(){
    int u, v, w;
    for (int i=0; i<N-1; i++){
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back( (Edge){u,v,w} );
        G[v].push_back( (Edge){v,u,w} );
    }
}

void build_size(int u, int fa){
    sz[u]=1;
    for (int i=0; i<(int)G[u].size(); i++){
        Edge e = G[u][i];
        if (e.v!=fa && !vis[e.v]){
            build_size(e.v,u);
            sz[u] += sz[e.v];
        }
    }
}

int best_center;
int best_max_sub;
void find_center(int u, int fa, int root){
    int max_sub = sz[root]-sz[u];

    for (int i=0; i<(int)G[u].size(); i++){
        Edge e = G[u][i];
        if (e.v!=fa && !vis[e.v]){
            find_center(e.v,u,root);
            max_sub = max(max_sub,sz[e.v]);
        }
    }

    if (max_sub<best_max_sub){
        best_center = u;
        best_max_sub = max_sub;
    }
}

/*
int Cal(map<int,int> cnt){
    static vector< pair<int,int> > v;
    v.clear();
    int ans=0; 

    int sum=0;
    for (map<int,int>::iterator it=cnt.begin(); it!=cnt.end(); ++it){
        pair<int,int> p = *it;
        v.push_back(p);
        sum += p.second;
    }
    for (int l=0, r=v.size()-1; l<v.size() && v[l].first<=K; l++){
        while (r>=0 && v[l].first+v[r].first>K){
            sum -= v[r].second;
            r--;
        }
        ans += v[l].second * sum;
    }
    return ans;
}

map<int,int> cnt;
map<int,int> cnt_sub;

void build_high(int u, int fa, int high){
    cnt[high]++;
    cnt_sub[high]++;

    for (int i=0; i<(int)G[u].size(); i++){
        Edge e = G[u][i];
        if (e.v!=fa && !vis[e.v]){
            build_high(e.v,u,high+e.w);    
        }
    }
}



int Count (int u){
    cnt.clear();
    cnt[0]++;
    
    int ans=0;
    for (int i=0; i<(int)G[u].size(); i++){
        Edge e = G[u][i];
        if (!vis[e.v]){
            cnt_sub.clear();
            build_high(e.v,u,e.w);
            ans -= Cal(cnt_sub);
        }
    }
    ans += Cal(cnt);

    return ans-1;
}
*/

int Cal (vector<int> &v){
    sort(v.begin(),v.end());
    int ans=0;
    for (int l=0, r=v.size()-1; l<v.size(); l++){
        while (r>=0 && v[l]+v[r]>K){
            r--;
        }
        ans += r+1;
    }
    return ans;
}

vector<int> p;
vector<int> p_sub;
void build_high(int u, int fa, int high){
    p.push_back(high);
    p_sub.push_back(high);

    for (int i=0; i<(int)G[u].size(); i++){
        Edge e = G[u][i];
        if (e.v!=fa && !vis[e.v]){
            build_high(e.v,u,high+e.w);    
        }
    }
}

int Count (int u){
    p.clear();
    p.push_back(0);

    int ans=0;
    for (int i=0; i<(int)G[u].size(); i++){
        Edge e = G[u][i];
        if (!vis[e.v]){
            p_sub.clear();
            build_high(e.v,u,e.w);
            ans -= Cal(p_sub);
        }
    }
    ans += Cal(p);

    return ans-1;
}

int ans = 0;
void solve(int x){
    build_size(x,-1);
    if (sz[x]==1)return;

    best_max_sub = INF;
    find_center(x,-1,x);
    
    x = best_center;
    ans += Count(x)/2;
    vis[x]=1;
    for (int i=0; i<(int)G[x].size(); i++){
        Edge e = G[x][i];
        if (!vis[e.v]){
            solve(e.v);
        }
    }
}

int main(){
    while (~scanf("%d %d", &N, &K)){
        if (N==0 && K==0)return 0;
    
        init();
        input();
        
        ans=0;
        solve(1);
        printf("%d\n", ans);
    }
}
