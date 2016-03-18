#include<bits/stdc++.h>
using namespace std ;

int n ,a[10];
void dfs(int d ,int S){
    if (d==n){
        for (int i=0 ;i<n ;i++ ){
            printf("%d",a[i]+1) ;
        }
        puts("") ;
        return ;
    }
    for (int i=n-1 ;i>=0 ;i-- )if (S&(1<<i)){
        a[d]=i ;
        dfs(d+1,S^(1<<i)) ;
    }
}

int main(){
    while (~scanf("%d",&n)){
        dfs(0,(1<<n)-1) ;
    }
}
