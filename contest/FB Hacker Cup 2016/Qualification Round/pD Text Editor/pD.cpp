#include<bits/stdc++.h>
using namespace std ;

const int maxn = 300 ;
const int maxl = 100030 ;
int n ,m ;
char s[maxn][maxl] ;
int a[maxn] ,lca[maxn][maxn] ;
int dp[maxn+5][maxn+5] ;

void radix_sort(){
    int L = 0 ;
    for (int i=0 ;i<n ;i++ )L = max(L,(int)strlen(s[i])) ,a[i]=i ;
    for (int i=L-1 ;i>=0 ;i-- ){
        vector<int>box[27] ;
        for (int j=0 ;j<n ;j++ ){
            if (s[ a[j] ][i]==0)box[0].push_back(a[j]) ;
            else box[ s[ a[j] ][i]-'a'+1 ].push_back(a[j]) ;
        }
        int k=0 ;
        for (int j=0 ;j<27 ;j++ ){
            for (int x:box[j])a[k++]=x ;
            box[j].clear() ;
        }
    }
}

inline int same_prifix(int i ,int j ,int l=0 ){
    while (s[i][l]==s[j][l] && s[i][l]!='\n')l++ ;
    return l ;
}

void build_lca(){
    for (int i=0 ;i<n ;i++ )lca[i][i]=(int)strlen(s[a[i]]) ;
    for (int i=1 ;i<n ;i++ )
        lca[i-1][i]=lca[i][i-1]=same_prifix(a[i-1],a[i]) ;
    for (int j=2 ;j<n ;j++ ){
        for (int i=j-2 ;i>=0 ;i-- ){
            lca[i][j]=lca[j][i]=min(lca[i][j-1],lca[i+1][j]) ;
        }
    }
}

int solve(){
    memset(s,0,sizeof(s)) ;
    scanf("%d%d",&n ,&m ) ;
    for (int i=0 ;i<n ;i++ )scanf("%s",s[i]) ;
    radix_sort() ;
    build_lca() ;

    //dp --------------------
    memset(dp,7,sizeof(dp)) ; //INF
    for (int i=0 ;i<n ;i++ )
        dp[i][1]=2*lca[i][i] ;
    for (int i=0 ;i<n ;i++ ){
        for (int k=2 ;k<=m ;k++ ){
            for (int j=0 ;j<i ;j++ ){
                dp[i][k]=min(dp[i][k],dp[j][k-1]+lca[i][i]*2-lca[i][j]*2) ;
            }
        }
    }
    //output ----------------
    int re=1<<29 ;
    for (int i=0 ;i<n ;i++ )re=min(re,dp[i][m]) ;

    return re+m ;
}

int main(){
    freopen("text_editor.txt","r",stdin ) ;
    freopen("pD_out.txt","w",stdout ) ;
    int T ; cin >> T ;

    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: %d\n",t ,solve() ) ;
    }
}
