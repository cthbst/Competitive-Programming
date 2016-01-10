#include<bits/stdc++.h>
using namespace std ;

typedef long long int LL ;
typedef LL Point[2] ;

inline LL dis2(const Point &A ,const Point &B){
    return (A[0]-B[0])*(A[0]-B[0])+(A[1]-B[1])*(A[1]-B[1]) ;
}

const int maxn = 2000 ;
int n ; Point P[maxn] ;
LL L[maxn] ;

LL solve(){
    //input -----------------
    cin >> n ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%lld%lld",&P[i][0] ,&P[i][1] ) ;
    }
    //solve -----------------
    LL re=0 ;

    for (int o=0 ;o<n ;o++ ){ // let o as the mid point
        for (int j=0 ;j<o ;j++ )
            L[j]=dis2(P[o],P[j]) ;
        for (int j=o+1 ;j<n ;j++ )
            L[j-1]=dis2(P[o],P[j]) ;
        sort(L,L+n-1) ;
        for (int j=0 ;j<n-1 ; ){
            int s = j++;
            while (j<n-1 && L[j]==L[s])j++ ;
            s = j-s ;
            re += (LL)(s*(s-1)/2) ;
        }
    }

    return re ;
}

int main(){
    freopen("boomerang_constellations.txt","r",stdin) ;
    freopen("pA_out.txt","w",stdout) ;

    int T ; cin >> T ;
    for (int t=1 ;t<=T ;t++ )
        printf("Case #%d: %lld\n",t ,solve() ) ;
}
