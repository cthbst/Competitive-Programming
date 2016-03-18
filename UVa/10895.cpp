#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100030 ;
int n ,m ,k ;
typedef pair<int,int> pii ;
vector<pii> Matrix[maxn] ;

void solve(){
    for (int i=1 ;i<=m ;i++ )Matrix[i].clear() ;
    for (int i=1 ;i<=n ;i++ ){
        scanf("%d",&k ) ;
        vector<int> a(k) ,b(k) ;
        for (int j=0 ;j<k ;j++ )scanf("%d",&a[j]) ;
        for (int j=0 ;j<k ;j++ )scanf("%d",&b[j]) ;
        for (int j=0 ;j<k ;j++ ){
            Matrix[ a[j] ].push_back(make_pair(i,b[j])) ;
        }
    }
    printf("%d %d\n",m ,n ) ;
    for (int i=1 ;i<=m ;i++ ){
        printf("%d",Matrix[i].size()) ;
        for (auto e:Matrix[i])printf(" %d",e.first ) ;puts("") ;
        int sz=Matrix[i].size() ;
        if (sz>0)printf("%d",Matrix[i][0].second ) ;
        for (int j=1 ;j<sz ;j++ )printf(" %d",Matrix[i][j].second ) ;puts("") ;
    }
}

int main(){
    //freopen("pA_in.txt","r",stdin) ;
    while (~scanf("%d%d",&n ,&m ))solve() ;
}
