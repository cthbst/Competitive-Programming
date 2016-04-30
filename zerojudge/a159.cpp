#include<bits/stdc++.h>
using namespace std ;

int ChartoInt(char c){
    return c-'0' ;
}

int DigitSum(int x ){
    int re=0 ;
    while (x>0){
        re+=x%10 ;
        x/=10 ;
    }
    return re ;
}

bool Valid(int sum){
    return sum%10==0 ;
}

void solve(){
    int n=0 ,m=0 ;
    char in[5] ;
    for (int i=0 ;i<4 ;i++ ){
        scanf("%s",in) ;
        n+=ChartoInt(in[1])+ChartoInt(in[3]) ;
        m+=DigitSum( 2 * ChartoInt(in[0]) ) +
             DigitSum( 2 * ChartoInt(in[2]) ) ;
    }
    puts( Valid(n+m) ? "Valid" : "Invalid" ) ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    for (int t=1 ;t<=T ;t++ ){
        solve() ;
    }
}
