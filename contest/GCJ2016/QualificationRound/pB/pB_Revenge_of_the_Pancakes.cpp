#include<bits/stdc++.h>
using namespace std ;

void solve(){
    stack<char> sta ;
    string s ;
    cin >> s ;
    for (char c:s){
        if (sta.empty() || c!=sta.top() )sta.push(c) ;
    }
    if (sta.top()=='+')sta.pop() ;
    printf("%d\n",sta.size()) ;
}

int main(){
    //freopen("B-large.in","r",stdin) ;
    //freopen("out.txt","w",stdout) ;
    int T ; scanf("%d",&T ) ;

    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: ",t) ;
        solve() ;
    }
}
