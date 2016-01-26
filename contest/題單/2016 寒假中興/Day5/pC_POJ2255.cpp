#include<stdio.h>
#include<string.h>

const int maxn = 100 ;
char I[maxn] ,P[maxn] ;
int x[maxn] ;

void dfs(int l ,int r ,int L ,int R ){
    if (l>r || L>R)return ;
    int m = x[ I[l]-'A' ] ;
    int cntL = m-L ;
    dfs(l+1,l+cntL,L,L+cntL-1) ;
    dfs(l+cntL+1,r,L+cntL+1,R) ;
    printf("%c",I[l]) ;
}

int main(){
    while (~scanf("%s%s",I ,P)){
        for (int i=0 ;I[i] ;i++ ){
            x[ P[i]-'A' ]=i ;
        }
        dfs(0,strlen(I)-1,0,strlen(I)-1) ;
        printf("\n") ;
    }
}
