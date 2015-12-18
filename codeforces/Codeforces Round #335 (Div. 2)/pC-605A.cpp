#include<bits/stdc++.h>
using namespace std ;

const int maxN = 100030 ;
int pos[maxN] ;

int main(){
    //input -----------------
    int n ;
    cin >> n;
    for (int i=1 ,ai ;i<=n ;i++ ){
        scanf("%d",&ai ) ;
        pos[ai]=i ;
    }
    //dp --------------------
    int best=1 ,dp=1 ;
    for (int i=2 ;i<=n ;i++ ){
        if (pos[i-1]<pos[i])dp++ ;
        else dp=1 ;
        best=max(best,dp) ;
    }
    //output ----------------
    cout << n-best <<endl ;
}
