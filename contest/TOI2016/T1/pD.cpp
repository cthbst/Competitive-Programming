#include<bits/stdc++.h>
using namespace std ;

typedef unsigned long long LLU ;
typedef long long LL ;

LLU bound ;
LLU sol(LLU x ,LLU X ,LLU Y ){
    if (x>X)return 0 ;
    if (x==0)return (Y+1)+sol(x+1,X,Y) ;
    LLU cx=min(bound/x,Y) ,cX=min(bound/X,Y) ;
    if (cx==cX)return (X-x+1)*(cx+1) ;
    LLU m = (x+X)/2 ;
    return sol(x,m,Y)+sol(m+1,X,Y) ;
}

int m ;
char cmd ;
LL L ,R ;


int main(){
    cin >>m >>cmd >>L >>R ;
    bound = cmd=='u' ? (1LL<<m)-1 : (1LL<<(m-1))-1 ;
    LLU ans = (LLU)(R-L+1)*(LLU)(R-L+1) ;
    if (L<0 && R<0 )L=-L ,R=-R ,swap(R,L) ;

    if (L>0){
        ans -= sol(0,R,R) ;
        if (L>0)ans += sol(0,L-1,R)*2 ;
        if (L>0)ans -= sol(0,L-1,L-1) ;
    }
    else {
        ans -= sol(0,R,R) ;
        ans -= sol(0,-L,-L) ;
        bound++ ;
        ans -= sol(0,-L,R)*2 ;
        ans += (R-L+1)*2+1 ;
    }
    cout << ans <<endl ;
}
