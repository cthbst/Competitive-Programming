#include<bits/stdc++.h>
using namespace std ;

int n ,k ;

vector<int> ans ;
void solve(){
    int n ,k ;
    cin >> n >> k ;
    ans.clear() ;
    int d=0 ,c=0 ;
    ans.push_back(k) ;
    while (d<100000){
        int s = ans[d]*n+c ;
        c = s/10 ;
        if (c==0 && s%10==k)break ;
        ans.push_back(s%10) ;
        d++ ;
    }
    if (ans.size()==100000 || ans[ ans.size()-1 ]==0){
        puts("0") ;
        return ;
    }
    for (int i= ans.size()-1 ;i>=0 ;i-- ){
        printf("%d",ans[i]) ;
    }
    puts("") ;
}

int main(){
    int T ; cin >> T ;
    while (T--)solve() ;
}
