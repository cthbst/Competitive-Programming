#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;

struct Query{
    int u, v;
    int idx, w;
    bool operator < (const Query &b)const{
        if (w!=b.w)return w<b.w;
        return idx > b.idx;
    }
};

const int MAXQ = 5003;
const int MAXN = 20002;

int N, M, Q;
vector<Query> Qs;
long long A[MAXQ];

void input(){
    Qs.clear();
    scanf("%d %d %d", &N, &M, &Q);

    Query qi;
    qi.idx = INF;
    for (int i=0; i<M; i++){
        scanf("%d %d %d", &qi.u, &qi.v, &qi.w);
        Qs.push_back(qi);
    }

    qi.u=qi.v=0;
    for (int i=0; i<Q; i++){
        scanf("%d", &qi.w);
        qi.idx = i;
        Qs.push_back(qi);
    }

    sort(Qs.begin(),Qs.end());
}

long long ans;
int fa[MAXN], sz[MAXN];

int root(int x){
    if (fa[x]==x)return x;
    return fa[x] = root(fa[x]);
}

void solve(){
    ans=0;
    for (int i=1; i<=N; i++){
        fa[i]=i;
        sz[i]=1;
    }

    for (auto qi:Qs){
        if (qi.idx==INF){ // add edge
            int u = root(qi.u);
            int v = root(qi.v);
            
            if (sz[u]>sz[v])swap(u,v);
            if (u!=v){
                fa[u]=v;
                ans += (long long)sz[u]*sz[v];
                sz[v]+=sz[u];
            }
        }
        else {
            A[qi.idx]=ans;
        }
    }
}

void output(){
    for (int i=0; i<Q; i++){
        printf("%lld\n",A[i]*2LL);
    }
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        input();
        solve();
        output();
    }
}
