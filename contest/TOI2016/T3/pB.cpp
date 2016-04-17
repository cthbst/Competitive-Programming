#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100030 ;
const int INF = 2000000000 ;
int K ,U ,p[maxn] ,s[maxn] ,mx ;
int dp[maxn] ;

#define mk make_pair
#define x first
#define y second

bool check(int C ){
    //printf("C=%d ",C ) ;
    deque<pair<int,int> > que ;
    dp[0]=0 ,que.push_back(mk(0,0)) ;
    for (int i=1 ;i<=U ;i++ ){

        while (!que.empty() && que.front().x>C-s[i])que.pop_front() ;
        if (que.empty())return 0 ;
        //printf("get(%d,%d)",que.front().x ,que.front().y) ;
        dp[i]=que.front().y+p[i] ;
        //printf("%d ",dp[i]) ;
        while (!que.empty() && que.back().y>=dp[i])que.pop_back() ;
        //printf("%d (%d,%d)\n",C-s[i],dp[i]-s[i],dp[i]) ;
        que.push_back( mk( dp[i]-s[i] , dp[i] ) ) ;

        /*****************************
        dp[i]=s[i] ;
        for (int j=0 ;j<i ;j++ )if (dp[j]+s[i]-s[j]<=C){
            dp[i]=min(dp[i],dp[j]+p[i]) ;
        }
        printf("%d ",dp[i]) ;
        if (dp[i]>C)return 0 ;
        //******************************/
    }
    return 1 ;
}

int main(){
    cin >> K >> U ;

    mx ,p[0]=s[0]=0 ;
    for (int i=1 ;i<=U ;i++ ){
        scanf("%d",&p[i]) ;
        s[i]=p[i]+s[i-1] ;
        mx=max(mx,p[i]) ;
    }
    if (K==1){
        printf("%d\n",s[U]) ;
    }
    else {
        int l=mx ,r=s[U] ;
        while (l!=r){
            int m=(l+r)>>1 ;
            if (check(m)==0)l=m+1 ;
            else r=m ;
            //puts("") ;
        }
        printf("%d\n",l ) ;
    }

    return 0 ;
}

/*
1 5
1 2 3 4 5

2 10
1 1 1 1 1 1 1 1 1 1

2 5
5 4 3 2 1
*/
