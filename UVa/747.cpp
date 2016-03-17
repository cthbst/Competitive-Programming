#include<bits/stdc++.h>
using namespace std ;

void solve(){
    stack<char> sta ;
    char c ;
    while (~scanf("%c",&c ) && c!='\n'){
        getchar() ;
        if (isdigit(c)){
            printf("%c",c) ;
            continue ;
        }
        if (c=='(')sta.push('(') ;
        if (c==')'){
            while (sta.top()!='('){
                printf("%c",sta.top()) ;
                sta.pop() ;
            }
            sta.pop() ;
        }
        if (c=='*'||c=='/'){
            while (!sta.empty() && (sta.top()=='*' || sta.top()=='/')){
                printf("%c",sta.top()) ;
                sta.pop() ;
            }
            sta.push(c) ;
        }
        if (c=='+'||c=='-'){
            while (!sta.empty() && sta.top()!='('){
                printf("%c",sta.top()) ;
                sta.pop() ;
            }
            sta.push(c) ;
        }
    }
    while (!sta.empty()){
        if (sta.top()!='(')printf("%c",sta.top()) ;
        sta.pop() ;
    }
    puts("") ;
}

int main(){
    //freopen("pA_in.txt","r",stdin );
    int T ; scanf("%d",&T ) ;
    getchar() ,getchar() ;
    while (T-- ){
        solve() ;
        if (T)puts("") ;
    }
}
