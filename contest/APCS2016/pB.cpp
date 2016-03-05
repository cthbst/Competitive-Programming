#include<bits/stdc++.h>
using namespace std ;

int n ,m ,q ;
int B[30][30] ;

void cmdA(){
    int r = max(n,m) ;
    for (int i=0 ;i<r ;i++)
        for (int j=i+1 ;j<r ;j++ )
            swap(B[i][j],B[j][i]) ;
    swap(n,m) ;
}
void cmdB(){
    for (int i=0 ;i<n ;i++ )reverse(B[i],B[i]+m ) ;
}

int main(){
    cin >> n >> m >> q ;
    for (int i=0 ;i<n ;i++ )
        for (int j=0 ;j<m ;j++)
            cin >>B[i][j] ;
    for (int i=0 ,cmd ;i<q ;i++ ){
        cin >> cmd ;
        cmdA() ,cmdB() ;
        if (cmd)cmdA() ;
    }
    printf("%d %d\n",n ,m ) ;
    for (int i=0 ;i<n ;i++ ){
        for (int j=0 ;j<m ;j++)
            printf("%d ",B[i][j]) ;
        puts("") ;
    }
}
