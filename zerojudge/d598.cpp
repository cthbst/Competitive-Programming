#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

#define MAXM 20
#define INF 1<<29
int d[MAXM][MAXM] ,w[MAXM][MAXM];
bool need[MAXM] ;
int dp[1<<17][17] ;

int main(){
    //input -----------------
    int M ,N ,V ;scanf("%d%d",&M ,&N ) ;

    memset(need,0,sizeof(need)) ;
    for (int i=0 ,s ;i<N ;i++ ){
        scanf("%d",&s ) ;
        need[s-1]=1 ;
    }
    need[0]=need[M-1]=1 ;

    for (int i=0 ;i<M ;i++ )
        for (int j=0 ;j<M ;j++ ){
            scanf("%d",&d[i][j]) ;
            if (d[i][j]==0 && i!=j )d[i][j]=INF ;
        }
    //d ---------------------
    for (int i=0 ;i<M ;i++ )
        for (int j=0 ;j<M ;j++ )
            for (int k=0 ;k<M ;k++ )
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]) ;
    for (int i=0 ,k=0 ;i<M ;i++ ){
        if (!need[i])continue ;
        for (int j=0 ,l=0 ;j<M ;j++ )
            if (need[j]) w[k][l]=d[i][j] ,l++ ;
        k++ ;
    }
    //bit dp ----------------
    V=0 ;
    for (int i=0 ;i<M ;i++ )
        if (need[i])V++ ;

    memset(dp,1,sizeof(dp)) ;
    dp[(1<<V)-1][0]=0 ;

    for (int S=(1<<V)-2 ;S>=0 ;S-- ){
        for (int v=0 ;v<V ;v++ ){
            for (int u=0 ;u<V ;u++ ){
                if ((S>>u) &1)continue ;
                dp[S][v]=min(dp[S][v],dp[S|(1<<u)][u]+w[v][u]) ;
            }
        }
    }
    //output ----------------
    printf("%d\n",dp[0][V-1]) ;
}
