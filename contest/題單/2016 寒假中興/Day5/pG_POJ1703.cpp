#include<stdio.h>

const int maxn = 100001 ;

int n ,m ;
int fa[maxn] ,dual[maxn] ;

int root(int x){
    if (fa[x]==x)return x ;
    return fa[x]=root(fa[x]) ;
}

int main(){
    int T ; scanf("%d",&T ) ;

    while (T-- && scanf("%d%d",&n ,&m)){
        for (int i=0 ;i<=n ;i++ ){
            fa[i]=i ;
            dual[i]=0 ;
        }
        char cmd[10] ; int a ,b ;
        while (m-- && scanf("%s%d%d",cmd ,&a ,&b )){
            a=root(a) ,b=root(b) ;
            dual[a]=root(dual[a]) ,dual[b]=root(dual[b]) ;
            if (cmd[0]=='A'){
                if (a!=b && a!=dual[b])
                    puts("Not sure yet.") ;
                else if (a!=b)
                    puts("In different gangs.") ;
                else
                    puts("In the same gang.") ;
            }
            else {
                if (!dual[b])dual[b]=a ;
                if (!dual[a])dual[a]=b ;
                fa[ dual[b] ]= a ;
                fa[ b ] = dual[a] ;
            }
        }
    }
}
