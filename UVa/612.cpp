#include<bits/stdc++.h>
using namespace std ;

int n ,m ;
struct str{
    string s ;int val ,id ;
    bool operator < (const str &B )const {
        return val!=B.val ?val<B.val :id<B.id ;
    }
}S[130];

int Count(string s ){
    int re=0 ;
    for (int i=0 ;i<n ;i++ ){
        for (int j=i+1 ;j<n ;j++ ){
            if ((char)s[i]>(char)s[j])re++ ;
        }
    }
    return re ;
}
void solve(){
    cin >> n >> m ;
    for (int i=0 ;i<m ;i++ ){
        cin >> S[i].s ;
        S[i].val = Count(S[i].s ) ;
        S[i].id=i ;
    }
    sort(S,S+m) ;
    for (int i=0 ;i<m ;i++ )cout << S[i].s <<endl ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    while (T--){
        solve() ;
        if (T) puts("") ;
    }
}
