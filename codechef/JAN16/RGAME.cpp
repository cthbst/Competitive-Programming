#include<bits/stdc++.h>
using namespace std ;

typedef unsigned long long LL ;

const LL MOD = 1000000007LL ;

const int maxn = 100030 ;
LL a[maxn] ,S[maxn] ,A[maxn] ;

#define rz(n) resize(n+1) ;

int main(){
    int T ; cin >>T ;

    int N ;
    while (T-- && cin >>N ){
        for (int i=0 ;i<=N ;i++ )scanf("%lld",&a[i]) ;
        S[0]=2*a[0]%MOD ;
        A[0]=0 ;
        LL P=1 ;
        for (int i=1 ;i<=N ;i++ ){
            P = P*2%MOD ;
            A[i]=(A[i-1]*2+S[i-1]*a[i])%MOD ;
            S[i]=(S[i-1]+P*a[i])%MOD ;
        }
        cout << A[N] <<endl ;
    }
}
