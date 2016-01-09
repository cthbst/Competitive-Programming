/*
    greedy
    note:
        K,M < 10^5 => K+M <= 2*10^5
 */
#include<bits/stdc++.h>
using namespace std ;

const int maxn = 200000 ;
int N ,K ,M ;
int A[maxn] ,C[maxn] ;

int main(){
    int T ; cin >> T ;

    while (T-- && scanf("%d%d%d",&N ,&K ,&M )){
        M+=K ;
        for (int i=0 ;i<N ;i++ )scanf("%d",&A[i]) ;
        for (int i=0 ,Bi ;i<N ;i++ ){
            scanf("%d",&Bi ) ;
            A[i]-=Bi ;
        }
        for (int i=0 ;i<M ;i++ )scanf("%d",&C[i]) ;
        //solve -------------
        sort(A,A+N) ,sort(C,C+M) ;
        for (int i=N-1 ,j=M-1 ;i>=0 && j>=0 ;i-- ){
            while (j>=0 && A[i]<C[j])j-- ;
            A[i]-=C[j--] ;
        }
        //output ------------
        long long ans=0 ;
        for (int i=0 ;i<N ;i++ )ans+=(long long)A[i] ;
        cout << ans <<endl ;
    }
}
