#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100030 ;
int n ;
char A[maxn] ,B[maxn] ;
int dL[maxn] ,dR[maxn] ;
int same[maxn] ;

int solve(){
    scanf("%d%s%s",&n ,A ,B ) ;
    dL[0]=dR[n-1]=1 ;
    for (int i=1 ,j=n-2 ;i<n ;i++ ,j-- ){
        dL[i] = dL[i-1] + (B[i]==B[i-1]?0:1) ;
        dR[j] = dR[j+1] + (B[j]==B[j+1]?0:1) ;
    }
    same[0] = A[0]==B[0]?1:0 ;
    for (int i=1 ;i<n ;i++ ){
        if (A[i]!=B[i])same[i]=0 ;
        else same[i]=same[i-1]+1;
    }
    int ans = maxn*2 ;

    for (int i=0 ;i+1<n ;i++ ){
        ans = min(ans, max(dL[i],dR[i+1]) ) ;
    }
    for (int i=n-1 ;i>=0 ;){
        if (same[i]==0){
            i-- ;
        }
        else {
            int cost=0 ;
            if (i-same[i]>=0)cost=max(cost,dL[ i-same[i] ]) ;
            if (i+1<n )cost=max(cost,dR[i+1]) ;
            ans=min(ans,cost) ;
            i-=same[i] ;
        }
    }

    return ans ;
}

int main(){
    freopen("boomerang_decoration.txt","r",stdin) ;
    freopen("pA_out.txt","w",stdout) ;
    int T ; cin >> T ;

    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: %d\n",t ,solve() ) ;
    }
}
