#include<bits/stdc++.h>
using namespace std ;

const int INF = 1<<29 ;
int main(){
    int n ; cin >> n ;

    int minX=INF ,maxX=-INF ;
    int minY=INF ,maxY=-INF ;

    for (int i=0 ,x ,y ;i<n ;i++ ){
        cin >> x >> y ;
        minX=min(minX,x) ;
        maxX=max(maxX,x) ;
        minY=min(minY,y) ;
        maxY=max(maxY,y) ;
    }

    int ans = (maxX-minX)*(maxY-minY) ;
    if (ans==0){
        puts("-1") ;
    }
    else {
        cout << ans <<endl ;
    }
}
