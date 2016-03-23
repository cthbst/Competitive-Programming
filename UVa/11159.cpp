#include<bits/stdc++.h>
using namespace std ;

const int maxn = 110 ;
int n ,m ,a[maxn] ,b[maxn] ;
vector<int> s[maxn] ,t[maxn] ;
int ma[maxn] ,mb[maxn] ;

bool used[maxn] ;
bool dfs(int u){
    used[u]=1 ;
    for (int v:s[u])if (v!=ma[u]){
        if (mb[v]>=0){
            int t = mb[v] ;
            if (!used[t] && dfs(t) ){
                ma[u]=v ,mb[v]=u ;
                return 1 ;
            }
        }
        else {
            mb[v]=u ;
            return 1;
        }
    }
    return 0 ;
}

int solve(){
    memset(s,0,sizeof(s)) ;
    memset(t,0,sizeof(t)) ;

    scanf("%d",&n) ;
    for (int i=0 ;i<n ;i++ )scanf("%d",&a[i]) ;
    scanf("%d",&m) ;
    for (int i=0 ;i<m ;i++ )scanf("%d",&b[i]) ;
    for (int i=0 ;i<n ;i++ ){
        for (int j=0 ;j<m ;j++ ){
            if (a[i]==0 && b[j]==0 || a[i]!=0 && b[j]%a[i]==0){
                s[i].push_back(j) ;
                t[j].push_back(i) ;
            }
        }
    }
    memset(ma,-1,sizeof(ma)) ;
    memset(mb,-1,sizeof(mb)) ;
    int match_cnt=0 ;
    for (int u=0 ;u<n ;u++ ){
        for (int v:s[u])if (mb[v]<0){
            match_cnt++ ;
            ma[u]=v ,mb[v]=u ;
            break ;
        }
    }
    for (int u=0 ;u<n ;u++ )if (ma[u]<0){
        memset(used,0,sizeof(used)) ;
        match_cnt+=dfs(u) ;
    }
    return match_cnt ;
}

int main(){
    int T ;scanf("%d",&T ) ;
    for (int t=1 ;t<=T ;t++ ){
        printf("Case %d: %d\n",t ,solve() ) ;
    }
}
