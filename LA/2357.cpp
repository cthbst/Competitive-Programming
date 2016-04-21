#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;
const LL maxn = 500000000LL ;
const int max_idx = 20 ;
LL f[max_idx] ;

void init(){
    f[0]=f[1]=1 ;
    for (int i=2 ;i<max_idx;i++ ){
        f[i]=0 ;
        for (int j=0 ;j<i ;j++ ){
            f[i]+=f[i-1-j]*f[j] ;
        }
    }
}

int find_deep(LL &n){
    int re=0 ;
    while (f[re]<n)n-=f[re++];
    return re ;
}

void dfs(LL n ,int deep ){
    if (deep==0)return ;
    if (deep==1){
        printf("X") ;
        return ;
    }
    //n++ ;
    int dl=0 ,dr=deep-1 ;
    while (f[dl]*f[dr]<=n)n-=f[dl++]*f[dr--] ;
    if (dl!=0){
        printf("(") ;
        dfs(n/f[dr],dl) ;
        printf(")") ;
    }
    printf("X") ;
    if (dr!=0){
        printf("(") ;
        dfs(n%f[dr],dr) ;
        printf(")") ;
    }
}

void solve(LL n ){
    int deep = find_deep(n) ;
    dfs(n-1,deep) ;
    puts("") ;
}

int main(){
    init() ;
    LL n ;
    while (~scanf("%lld",&n ) && n!=0 ){
        solve(n+1) ;
    }
}
