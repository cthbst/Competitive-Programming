#include<bits/stdc++.h>
using namespace std;

int n ,dp[1<<21] ;
int d[21][21] ;
const int INF = 1<<29 ;
queue<int> que ;

int main(){
    int T ;cin >> T ;

    while (T-- && scanf("%d",&n )) {
        for (int i=0 ;i<n ;i++ ){
            for (int j=0 ;j<n ;j++ ){
                scanf("%d",&d[i][j]) ;
            }
        }
        for (int i=(1<<n)-1 ;i>=0 ;i-- )dp[i]=INF ;
        while (!que.empty())que.pop() ;
        que.push(0) ;
        dp[0]=0 ;
        int cnt=0 ;
        while (!que.empty()){
            int u = que.front() ;que.pop() ;
            //printf("%10d ---------\n",u ) ;
            vector<int> S ;
            for (int i=1 ,j=0 ;j<n ;i<<=1 ,j++ ){
                if ((u&i)==0)S.push_back(j) ;
            }
            for (int i=S.size()-1 ;i>0 ;i-- ){
                for (int j=i-1 ;j>0 ;j-- ){
                    int v = u | (1<<S[0]) | (1<<S[i]) | (1<<S[j]) ;
                    if (dp[v]==INF){
                        que.push(v) ;
                        cnt++ ;
                    }
                    dp[v]=min(dp[v],dp[u]+d[ S[0] ][ S[i] ]+d[ S[i] ][ S[j] ]+d[ S[j] ][ S[0] ]) ;
                    //printf("%d %d %d\n",S[0] ,S[i] ,S[j]) ;
                }
            }
        }

        cout << dp[(1<<n)-1] <<endl ;
    }
}
