#include<bits/stdc++.h>
using namespace std ;

const int maxm = 10 ;
int n ,m ,cnt[maxm+1] ;

int main(){
    cin >> n >> m ;
    memset(cnt,0,sizeof(0)) ;
    for (int i=0 ,ai ;i<n ;i++ ){
        scanf("%d",&ai ) ;
        cnt[ai]++ ;
    }
    int ans=0 ,sum=0 ;
    for (int i=1 ;i<=m ;i++ ){
        ans+=cnt[i]*sum ;
        sum+=cnt[i] ;
    }
    cout <<ans <<endl ;
}
