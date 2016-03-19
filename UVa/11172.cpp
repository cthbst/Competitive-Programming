#include<bits/stdc++.h>
using namespace std ;

void solve(){
    int a ,b ;
    cin >> a >> b ;
    if (a<b)puts("<") ;
    if (a==b)puts("=") ;
    if (a>b)puts(">") ;
}

int main(){
    int T ; scanf("%d",&T ) ;while (T--)
    solve() ;
}
