#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std ;

vector<int> a ;
bool dp[50030] ;

int main(){
    int N ,M ;

    while (~scanf("%d%d",&N ,&M )){
        a.resize(N) ;
        //input -------------
        int SUM=0 ;
        for (int i=0 ;i<N ;i++ ){
            scanf("%d",&a[i]) ;
            SUM+=a[i] ;
        }
        sort(a.begin() ,a.end() ) ;
        int A=0 ,B=0 ;
        for (int i=N-1 ;i>=0 ;i-- ){
            if (A<B)A+=a[i] ;
            else B+=a[i] ;
        }
        printf("%d %d\n",A ,B ) ;
    }
}
