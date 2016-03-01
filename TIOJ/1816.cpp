#include<bits/stdc++.h>
using namespace std ;

const int MOD = 1000000007 ;
const int maxK = 12 ;
const int D = 1<<maxK ;
const int ZERO = (1<<(maxK+1))-2 ;
const int maxn = 1030 ;
int K ,dp[2][1<<(maxK+1)] ;
char S[maxn] ;

void pMOD(int &a ){ if (a>=MOD)a-=MOD ; }

inline bool judge(int x){
    return (x>>(K+1))==(1<<(maxK-K))-1 ;
}

void solve(){
	scanf("%d%s",&K ,S+1) ;
	memset(dp,0,sizeof(dp)) ;
	dp[0][ZERO]=1 ;
    int n = strlen(S+1) ;
	for (int i=1 ,d=1 ;i<=n ;i++ ,d^=1){
		memset(dp[d],0,sizeof(dp[d])) ;
        if (S[i]=='}' || S[i]==')'){
            int type= (S[i]=='}'?1:0) ;
            for (int i=ZERO-1 ;i>=0 ;i-- ){
                if ((i&1)!=type)continue ;
                if (!judge(D|(i>>1)))continue ;
                pMOD( dp[d][D|(i>>1)]+=dp[d^1][i]) ;
            }
        }
        else if (S[i]=='{' || S[i]=='('){
            int type= (S[i]=='{'?1:0) ;
            for (int i=ZERO ;i>=D ;i--){
                if (!judge((i^D)<<1|type))continue ;
                dp[d][(i^D)<<1|type]=dp[d^1][i] ;
            }
        }
        else if (S[i]=='?'){
            for (int i=ZERO-1 ;i>=0 ;i-- ){
                if (!judge(D|(i>>1)))continue ;
                pMOD( dp[d][D|(i>>1)]+=dp[d^1][i]) ;
            }
            for (int i=ZERO ;i>=D ;i--){
                if (judge((i^D)<<1|0))
                    pMOD( dp[d][(i^D)<<1|0]+=dp[d^1][i] ) ;
                if (judge((i^D)<<1|1))
                pMOD( dp[d][(i^D)<<1|1]+=dp[d^1][i] ) ;
            }
        }
	}
    printf("%d\n",dp[n&1][ZERO]) ;
}

int main(){
    int T ; scanf("%d",&T) ;

	while (T--)solve() ;
}
