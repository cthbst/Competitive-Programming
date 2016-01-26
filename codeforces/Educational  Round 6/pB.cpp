#include<bits/stdc++.h>
using namespace std ;

int cost[10]={6,2,5,5,4,5,6,3,7,6} ;

int query(int x){
    if (x==0)return cost[0] ;
    int re=0 ;
    while (x>0)re+=cost[x%10] ,x/=10 ;
    return re ;
}

int main(){
    int l ,r ;
    cin >> l >> r ;
    int ans=0 ;
    for (int i=l ;i<=r ;i++ )ans+=query(i) ;
    cout << ans <<endl ;
}

