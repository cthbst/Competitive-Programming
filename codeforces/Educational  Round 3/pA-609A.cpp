#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100 ;
int n ,m ,a[maxn] ;

int main(){
    cin >> n >> m ;
    for (int i=0 ;i<n ;i++ )
        scanf("%d",a+i) ;
    sort(a,a+n) ;
    for (int i=n-1 ;i>=0 ;i-- ){
        m-=a[i] ;
        if (m<=0){
            printf("%d\n",n-i) ;
            return 0 ;
        }
    }
}
