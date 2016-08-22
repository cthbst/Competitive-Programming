#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std ;

const int maxN = 1000030 ;

int a[maxN] ;
int dp[maxN] ;
stack<int> sta ;

int main(){
	//input -----------------
	int N ;
	scanf("%d",&N ) ;
	for (int i=0 ;i<N ;i++){
		scanf("%d",&a[i]) ;
	}

	//dp --------------------
	const int INF = 1000000010 ;
    for (int i=0 ;i<N ;i++ ){
        while (!sta.empty() && sta.top()<a[i])sta.pop() ;
        if (sta.empty()){
            dp[i]=INF ;
        }
        else {
            dp[i]=sta.top() ;
        }
        sta.push(a[i]) ;
    }
    while (!sta.empty())sta.pop() ;
    long long int ans = 0 ;
    for (int i=N-1 ;i>=0 ;i-- ){
        while (!sta.empty() && sta.top()<=a[i])sta.pop() ;
        if (!sta.empty()){
            dp[i]=min(dp[i],sta.top()) ;
        }
        ans+=(long long int)dp[i] ;
        sta.push(a[i]) ;
    }

	//output ----------------
	ans-=INF ;
    printf("%lld\n",ans ) ;
}

//test 3 3 3
