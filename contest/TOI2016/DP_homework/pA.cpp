#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1030 ;
struct str{
    int a ,b ,c ;
    bool operator < (const str &B )const {
        return a<B.a && b<B.b && c<B.c ;
    }
}Box[maxn];
int n ;
vector<int> G[maxn] ;
int din[maxn] ,dp[maxn] ;

int main(){
    freopen("p1.txt","r",stdin ) ;
    cin >> n ;
    for (int i=0 ;i<n ; i++ ){
        int in[3] ;
        cin >> in[0] >> in[1] >> in[2] ;
        sort(in,in+3) ;
        Box[i]=(str){in[0],in[1],in[2]} ;
    }

    memset(din,0,sizeof(din)) ;
    for (int i=0 ;i<n ;i++ ){
        for (int j=0 ;j<n ;j++ ){
            if (Box[i]<Box[j]){
                din[j]++ ;
                G[i].push_back(j) ;
            }
        }
    }

    memset(dp,0,sizeof(dp)) ;
    queue<int> que ;
    for (int i=0 ;i<n ;i++ ){
        if (din[i]==0)que.push(i) ,dp[i]=1 ;
    }
    int ans = 0 ;
    while (!que.empty()){
        int u = que.front() ; que.pop() ;
        ans = max (ans,dp[u]) ;
        for (int v:G[u]){
            dp[v]=max(dp[v],dp[u]+1) ;
            din[v]-- ;
            if (din[v]==0)que.push(v) ;
        }
    }
    printf("%d\n",ans ) ;
}
