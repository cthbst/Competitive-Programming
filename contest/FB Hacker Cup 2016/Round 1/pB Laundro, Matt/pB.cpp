#include<bits/stdc++.h>
using namespace std ;

typedef unsigned long long llu ;
typedef pair<llu,llu> puu ;
llu L ,N ,M ,D ;
priority_queue< puu ,vector<puu> ,greater<puu> > W ;
priority_queue< llu ,vector<llu> ,greater<llu> > T ;

llu solve(){
    cin >> L >>N >>M >>D ;
    while (!W.empty())W.pop() ;
    for (llu i=0 ,wi ;i<N ;i++ ){
        scanf("%llu",&wi ) ;
        W.push( make_pair(wi,wi) ) ;
    }
    while (!T.empty())T.pop() ;
    for (int i = (int)min(L,M)-1 ;i>=0 ;i-- ){
        T.push((llu)0) ;
    }
    //-----------------------
    llu re=0 ;
    for (int i=(int)L ;i>0 ;i-- ){
        auto u = W.top() ; W.pop() ;
        auto v = T.top() ; T.pop() ;
        re = max(re, v=( max(u.first,v)+D ) ) ;
        u.first+=u.second ; W.push(u) ;
        T.push(v) ;
    }
    return re ;
}

int main(){
    freopen("laundro_matt.txt","r",stdin) ;
    freopen("pB_out.txt","w",stdout) ;
    int T ; scanf("%d",&T ) ;

    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: %llu\n",t ,solve() ) ;
    }
}

