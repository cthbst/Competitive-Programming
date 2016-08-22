#include<stdio.h>

const int maxN = 10030 ;

int fa[maxN] ;
int root(int x){
    if (fa[x]==x)return x ; // 老大就是自己 回傳自己
    return fa[x]=root( fa[x] ) ; // magic 找到自己的老大 記錄下來 然後回傳
    return root(fa[x]) ;       //no magic 找到自己的老大 然後回傳
}

int main(){
	int N ,M ,Q ;
    scanf("%d%d%d",&N ,&M ,&Q ) ;

	for (int i=1 ;i<=N ;i++ ){
		fa[i] = i ; // 自己的老大就是自己 (?
	}
    for (int i=0 ,u ,v ;i<M ;i++ ){
		scanf("%d%d",&u ,&v ) ;
        int ru=root(u) ; // ru : u 的老大
        int rv=root(v) ; // rv : v 的老大
        if (ru!=rv)fa[rv]=ru ; //merge
    }

    //query -----------------
    for (int i=0 ,u ,v ;i<Q ;i++ ){
		scanf("%d%d",&u ,&v ) ;
		int ru=root(u) ; // ru : u 的老大
        int rv=root(v) ; // rv : v 的老大
        if (ru==rv)puts(":)") ;
        else puts(":(") ;

    }
}
