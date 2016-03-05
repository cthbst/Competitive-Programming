#include<bits/stdc++.h>
using namespace std ;

struct str{
    int l ,r ;
    bool operator < (const str&B )const{
        return l!=B.l?l<B.l:r<B.r ;
    }
};

int n ;
vector<str> segments ;

int main(){
    cin >> n ;
    segments.resize(n) ;
    for (auto &S:segments){
        scanf("%d%d",&S.l ,&S.r ) ;
    }
    sort(segments.begin(),segments.end()) ;
    int ans = 0 ,last=-1;
    for (auto S:segments){
        if (last<=S.r)ans+=S.r-max(last,S.l) ;
        last=max(last,S.r) ;
    }
    cout << ans <<endl ;
}
