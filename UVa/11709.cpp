#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1030 ;
int n ,m ,deep[maxn] ,low[maxn] ;
vector<int> G[maxn] ;
string a ,b ;
map<string,int> ID ;

stack<int> sta ; bool insta[maxn] ;
int scc_cnt ;
int dfs(int u ){
    low[u]=deep[u] ;
    sta.push(u) ; insta[u]=1 ;

    for (int v:G[u]){
        if (deep[v]==0){
            deep[v]=deep[u]+1 ;
            low[u]=min(low[u],dfs(v)) ;
        }
        else if (insta[v]){
            low[u]=min(low[u],low[v]) ;
        }
    }
    if (low[u]>=deep[u]){
        //printf("(%d)",u) ;
        scc_cnt++ ;
        while (sta.top()!=u)insta[sta.top()]=0 ,sta.pop() ;
        insta[u]=0 ; sta.pop() ;
    }
    //printf("deep[%d]=%d low[%d]=%d\n",u ,deep[u],u ,low[u]) ;
    return low[u] ;
}

void solve(){
    ID.clear() ;
    scc_cnt=0 ;
    //input -----------------
    getline(cin,a) ;
    for (int i=0 ;i<n ;i++ ){
        getline(cin,a) ; ID[a]=i ;
        G[i].clear() ;
        deep[i]=0 ;
    }
    for (int i=0 ;i<m ;i++ ){
        getline(cin,a) ,getline(cin,b) ;
        G[ ID[a] ].push_back(ID[b]) ;
        //printf("%d -> %d\n",ID[a] ,ID[b]) ;
    }
    //solve -----------------
    for (int i=0 ;i<n ;i++ )if (!deep[i]){
        deep[i]=1 ;
        dfs(i) ;
    }
    //output ----------------
    printf("%d\n",scc_cnt ) ;
}

int main(){
    //freopen("pG_in.txt","r",stdin ) ;
    //freopen("pG_out.txt","w",stdout) ;
    memset(insta,0,sizeof(insta)) ;
    while (scanf("%d%d",&n ,&m )){
        if (n==0&&m==0)return 0 ;
        solve() ;
    }
}
