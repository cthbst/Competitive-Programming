#include<bits/stdc++.h>
using namespace std ;

const int maxn = 120 ;
int n ,m ;
map<string,int> ID ;
string a ,b ,s[maxn] ;
vector<int> G[maxn] ;
int deep[maxn] ;
set<string> Ans ;

int dfs(int u ,int fa ){
    int re=deep[u] ,low=deep[u] ,cnt=0 ,son=0 ;
    for (int v:G[u])if (v!=fa){
        if (!deep[v]){
            cnt++ ;
            deep[v]=deep[u]+1 ;
            int d = dfs(v,u) ;
            low=min(low,d) ;
            if (d>deep[u])son++ ;
            if (fa==-1 && cnt>1)Ans.insert(s[u]) ;
            if (fa!=-1 && d>=deep[u])Ans.insert(s[u]) ;
        }
        else {
            re=min(re,deep[v]) ;
        }
    }
    //if (fa==-1 && cnt>1)Ans.insert(s[u]) ;
    //if (fa!=-1 && cnt>0 && low>=deep[u])Ans.insert(s[u]) ;
    return min(re,low) ;
}

int main(){
    //freopen("pE_in.txt","r",stdin) ;
    int Case=0 ;
    while (scanf("%d",&n) && n!=0 ){
        ID.clear() ;
        for (int i=1 ;i<=n ;i++ ){
            cin >> s[i] ;
            ID[ s[i] ]=i ,deep[i]=0 ;
            G[i].clear() ;
        }
        cin >> m ;
        for (int i=1 ;i<=m ;i++ ){
            cin >> a >> b ;
            int x=ID[a] ,y=ID[b] ;
            //printf("%d <-> %d\n",x,y ) ;
            G[x].push_back(y) ;
            G[y].push_back(x) ;
        }
        Ans.clear() ;
        for (int i=1 ;i<=n ;i++ )if (!deep[i]){
            deep[i]=1 ;
            dfs(i,-1) ;
        }
        if (Case)puts("") ;
        printf("City map #%d: %d camera(s) found\n",++Case ,Ans.size()) ;
        for (auto ele:Ans){
            cout <<ele <<endl ;
        }
    }
}
