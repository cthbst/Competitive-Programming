#include<bits/stdc++.h>
using namespace std ;

void solve(){
    string s ;
    deque<char> que ;

    cin >> s ;
    for (int i=0 ;i<s.size() ;i++ ){
        if (que.empty())que.push_back(s[i]) ;
        else if (s[i]>=que.front())que.push_front(s[i]) ;
        else que.push_back(s[i]) ;
    }

    for (char c:que)printf("%c",c) ;
    puts("") ;
}


int main(){
    freopen("A-large.in","r",stdin) ;
    freopen("A-large_out.txt","w",stdout ) ;
    int T ;scanf("%d",&T ) ;
    for (int i=1 ;i<=T ;i++ ){
        printf("Case #%d: ",i ) ;
        solve() ;
    }
}
