#include<stdio.h>
#include<algorithm>
using namespace std ;

const int maxN=131100 ;
int s[maxN] , idx[maxN] ,inverse[maxN] ;

bool cmp (int a ,int b ){
    return s[a]<s[b] ;
}

int seg[maxN*4] ;

void build(int L ,int R ,int o=1 ){
    if (L==R)seg[o]=idx[L] ;
    else {
        int lc=(o<<1) ,rc=(o<<1)|1 ;
        int M=(L+R)>>1 ;
        build(L,M,lc) ;
        build(M+1,R,rc) ;
        seg[o]=min(seg[lc],seg[rc]) ;
    }
}
const int INF = 1<<29 ;
int query(int l ,int r ,int L ,int R ,int o=1){
    if (l<=L && R<=r)return seg[o] ;
    if (R<l || r<L )return INF ;
    int M=(L+R)>>1 ,lc=(o<<1) ,rc=(o<<1)|1 ;
    return min( query(l,r,L,M,lc) , query(l,r,M+1,R,rc) ) ;
}

int N ;
void output(int l ,int r ){
    if (r<l)return ;
    int id=query(l,r,0,N-1) ;
    int m=inverse[id] ;
    printf("%d ",s[id]) ;
    output(l,m-1) ;
    output(m+1,r) ;
}
int main(){
    while (~scanf("%d",&N)){
        for (int i=0 ;i<N ;i++ ){
            scanf("%d",&s[i]) ;
            idx[i]=i ;
        }
        sort(idx,idx+N,cmp) ;
        for (int i=0 ;i<N ;i++ ){
            inverse[ idx[i] ]= i ;
        }
        build(0,N-1) ;
        output(0,N-1) ;
        puts("") ;
    }
}
