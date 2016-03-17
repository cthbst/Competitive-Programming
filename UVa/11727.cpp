#include<bits/stdc++.h>
using namespace std ;

int main(){
    int a[3] ;
    int T  ; scanf("%d",&T );
    int cs=1 ;
    while (T-- && ~scanf("%d%d%d",&a[0] ,&a[1] ,&a[2])){
        sort(a,a+3) ;
        printf("Case %d: %d\n",cs++ ,a[1]) ;
    }
}
