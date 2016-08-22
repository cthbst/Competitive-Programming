#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

const int maxN= 30030 ;
vector<int> E[maxN] ;

int lower[maxN] ;
int chain[maxN] ,head[maxN] ,deep[maxN] ;

int get_weight(int u ,int Deep){
    deep[u]=Deep ;
    int weight ,fatest=0 ;
    int sum=1 ;
    for (int v:E[u]){
        weight=get_weight(v,Deep+1) ;
        sum+=weight ;
        if (weight>fatest){
            lower[u]=v;
            fatest=weight ;
        }
    }
    return sum ;
}

void heavy_light(int u ,int fa,bool chain_root){
    head[u]=(chain_root==1?fa:0) ;
    chain[u]=(chain_root==1?u:chain[fa]) ;

    for (int v:E[u]){
        if (v==lower[u])heavy_light(v,u,0) ;
        else heavy_light(v,u,1) ;
    }
}

int LCA (int a ,int b ){
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
    for (int i=1 ,p ;i<=N ;i++ ){
        while (scanf("%d",&p) && p!=0 ){
            E[i].push_back(p) ;
        }
    }
    //heavy light -----------
	get_weight(1,0) ;
	heavy_light(1,1,1) ;

	//query -----------------
    int a ,b ;
    while (Q-- && scanf("%d%d",&a ,&b )){
        int c=LCA(a,b) ;
        printf("%d %d\n",c,deep[a]+deep[b]-2*deep[c]) ;
    }
}
