#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100030 ;
typedef pair<int,int> pii ;
int n ,x ,y ,X ,Y ;
pii p[maxn] ;

int main(){
    scanf("%d",&n ) ;
    for (int i=0 ,a ,b ;i<n ;i++ ){
        scanf("%d%d",&a ,&b ) ;
        a=a+b ,b=a-2*b ;
        p[i]=make_pair(a,b) ;
        x=min(x,a) ,X=max(X,a) ;
        y=min(y,b) ,Y=max(Y,b) ;
    }
    int A=0 ,B=0 ; // A /  B \/
    for (int i=0 ;i<n ;i++ ){
        int a = p[i].first , b = p[i].second ;
        A = max(A, min( max(a-x,b-y) , max(X-a,Y-b) ) ) ;
        B = max(B, min( max(a-x,Y-b) , max(X-a,b-y) ) ) ;
    }
    int ans = min(A,B) ;
    if (ans==72)ans++ ;
    cout << ans <<endl ;
}
/*
2
-1 -1
1 1

3
0 0
1 1
2 2

4
0 0
1 0
0 1
1 1
*/
