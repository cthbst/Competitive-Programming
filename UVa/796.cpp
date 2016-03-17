#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100000 ;
vector<int> G[maxn] ;
int n ,deep[maxn] ;
set< pair<int,int> > Ans ;

int dfs(int u ,int fa){
    int re=deep[u] ,low=deep[u] ;
    for (int v:G[u])if (v!=fa){
        if (deep[v]){
            re=min(re,deep[v]) ;
        }
        else {
            deep[v]=deep[u]+1 ;
            int d=dfs(v,u) ;
            low=min(low,d) ;
            if (d>deep[u]){
                Ans.insert(make_pair(min(u,v),max(u,v))) ;
            }
        }
    }
    return min(re,low) ;
}

void solve(){
    //input -----------------
    Ans.clear() ;
    for (int i=0 ;i<n ;i++ ){
        G[i].clear() ;
        deep[i]=0 ;
    }
    for (int i=0 ,u ,m ;i<n ;i++ ){
        scanf("%d (%d)",&u ,&m ) ;
        for (int j=0 ,v ;j<m ;j++ ){
            scanf("%d",&v ) ;
            G[u].push_back(v) ;
        }
    }
    //solve -----------------
    for (int i=0 ;i<n ;i++ )if (!deep[i]){
        deep[i]=1 ;
        dfs(i,-1) ;
    }

    //output ----------------
    printf("%d critical links\n",Ans.size()) ;
    for (auto e:Ans){
        printf("%d - %d\n",e.first ,e.second ) ;
    }
    puts("") ;
}
int main(){
    while (~scanf("%d",&n))solve() ;
}
