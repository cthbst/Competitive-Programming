#include<bits/stdc++.h>
using namespace std ;

bool used[10] ; int cnt ;

void split(int x){
    while (x>0){
        if (used[x%10]==0)used[x%10]=1,cnt++ ;
        x/=10 ;
    }
}


void solve(){
    int N ; scanf("%d",&N ) ;
    if (N==0){
        puts("INSOMNIA") ;
        return ;
    }
    cnt = 0 ;
    for (int i=0 ;i<10 ;i++ )used[i]=0 ;
    int d = 1 ;

    while (cnt<10)split(N*(d++)) ;

    printf("%d\n",(d-1)*N ) ;
}

int main(){
    freopen("A-large.in","r",stdin) ;
    freopen("out.txt","w",stdout) ;
    int T ; cin >> T ;
    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: ",t ) ;
        solve() ;
    }
}
