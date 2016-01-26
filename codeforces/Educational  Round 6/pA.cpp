#include<bits/stdc++.h>
using namespace std ;

long long ABS(long long x){
    return x<0 ?-x :x ;
}

int main(){
    long long x ,y ,X ,Y ;
    cin >> x >> y >> X >>Y ;
    long long dx = ABS(X-x) ,dy = ABS(Y-y);
    cout << max(dx,dy) <<endl ;
}
