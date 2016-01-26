#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;
const LL MOD = 1000000007 ;

int n ;
vector< pair<LL,LL> > a ;

struct str{
    LL H ,SS ,S ,cnt ;
};
vector<str> vec ;

LL solve(){
    cin >> n ;  a.resize(n) ;
    for (auto &e:a)
        scanf("%lld%lld",&e.first ,&e.second ) ;
    sort(a.begin(),a.end()) ;
    //solve -----------------
    LL ans=0 ;
    vec.clear() ;

    for (auto e:a){
        while (!vec.empty() && vec.back().H <e.second )
            vec.pop_back() ;
        if (vec.size()==0 || vec.size()>0 && vec.back().H >e.second){
            vec.push_back( str{e.second,e.first*e.first%MOD,e.first,1} ) ;
        }
        else {
            LL add=0 ,b=e.first ;
            add += vec.back().SS ;
            add -= vec.back().S*2%MOD*b%MOD ;
                if (add<0) add+=MOD ;
            add += vec.back().cnt*b%MOD*b%MOD ;
                if (add>=MOD) add-=MOD ;
            ans += add ;
                if (ans>=MOD) ans-=MOD ;
            auto &last = vec.back() ;
            last.SS += b*b%MOD ;
                if (last.SS>=MOD)last.SS-=MOD ;
            last.S  += b ;
                if (last.S>=MOD)last.S-=MOD ;
            last.cnt++ ;
        }
    }
    return ans ;
}

int main(){
    freopen("snakes_and_ladders.txt","r",stdin) ;
    freopen("pC_out.txt","w",stdout);
    int T ; cin >>T ;
    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: %lld\n",t ,solve() ) ;
    }
}
