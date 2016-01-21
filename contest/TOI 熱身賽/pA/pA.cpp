#include<bits/stdc++.h>
using namespace std ;

int main(){
    long long mi ,mx ,x ;
    cin >> mi ;
    mx=mi ;

    while (cin >> x){
        mi=min(mi,x) ;
        mx=max(mx,x) ;
    }
    cout << mx <<" " <<mi <<endl ;
}
