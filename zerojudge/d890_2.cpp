#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std ;

vector<int> a(530) ;
bool dp[50030] ;

int main(){
    int N ,M ;

    while (~scanf("%d%d",&N ,&M )){
        //input -------------
        int SUM=0 ;
        for (int i=0 ;i<N ;i++ ){
            scanf("%d",&a[i]) ;
            SUM+=a[i] ;
        }
        //dp ----------------
        memset(dp,0,sizeof(dp)) ;
        dp[0]=1 ;
        int sum=0 ;
        for (int i=0 ;i<N ;i++ ){
            sum+=a[i] ;
            for (int j=min(SUM/2,sum);j>=a[i];j-- ){
                dp[j]=dp[j]||dp[j-a[i]] ;
            }
        }
        //output ------------
        int Ans=SUM ;
        while (!dp[Ans] )Ans-- ;
        printf("%d %d\n",Ans ,SUM-Ans) ;
    }
}
