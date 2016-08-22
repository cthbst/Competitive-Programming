#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

const int maxN=10030 ;
vector<int> E[maxN] ;

int w[maxN] ;
int count_weight (int u,int fa){
    w[u]=1 ;
    for (int v:E[u])if(v!=fa){
        w[u]+=count_weight(v,u) ;
    }
    return w[u] ;
}

int chain[maxN] ,head[maxN] ,deep[maxN] ;
void heavy_light(int u ,int fa ,int Deep=0 ,bool chain_root=1 ){
    chain[u]=(chain_root==1 ?u:chain[fa]) ;
    head [u]=(chain_root==1 ?fa:0 ) ;
    deep [u]=Deep ;

    for (int v:E[u])if(v!=fa){
        heavy_light(v,u,Deep+1,w[v]<=w[u]/2) ;
    }
}

int query(int a, int b ){
    while (chain[a]!=chain[b]){
        if (deep[ chain[a] ]>deep[ chain[b] ])swap(a,b) ;
        b=head[ chain[b] ] ;
    }
    if (deep[a]>deep[b])swap(a,b) ;
    return a ;
}

int main(){
	//input -----------------
	int N ,Q ;
	scanf("%d%d",&N ,&Q ) ;

    for (int i=0 ,u ,v ;i<N ;i++ ){
        scanf("%d%d",&u ,&v ) ;
        E[u].push_back(v) ;
        E[v].push_back(u) ;
    }
	//LCA -------------------
    //build_LCA (0,0) ;
    count_weight(0,0) ;
    heavy_light(0,0) ;

	//query -----------------
	int ca ,cb ,a ,b ;
	while (Q-- && scanf("%d%d%d%d",&a ,&b ,&ca ,&cb )){
        //if (under(cb,ca)==1)swap(ca,cb) ;
        if (query(cb,ca)==cb)swap(ca,cb) ;

        int c = query(a,b) ;

        if (query(cb,a)==cb && query(cb,b)==c){
			puts("GO") ;
        }
        else if (query(cb,a)==c && query(cb,b)==cb){
			puts("GO") ;
        }
        else {
			puts("STOP") ;
        }
	}
}
