#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

#define MAXN 130
#define INF 1<<30

int N ,S ,T ,E ,d[MAXN][MAXN] ;
bool vis[MAXN] ;

int DFS (int v ,int F ){
	if (v==T)return F ;
	vis[v]=1 ;
	for (int i=1 ;i<=N ;i++ ){
		if (!vis[i] && d[v][i]>0 ){
			int t=DFS(i,min(d[v][i],F)) ;
			if (t>0){
				d[v][i]-=t ;
				d[i][v]+=t ;
				return t ;
			}
		}
	}
	
	return -1 ;
}

int main(){
	int time =0 ;
	while (scanf("%d",&N ) && N!=0 && scanf("%d%d%d",&S ,&T ,&E )){
		//input ---------------------------------
		memset(d,0,sizeof(d)) ;
		for (int i=0 ,a ,b ,w ;i<E ;i++ ){
			scanf("%d%d%d",&a ,&b ,&w ) ;
			d[a][b]=d[b][a]+=w ;
		}
		//output---------------------------------
		int Ans=0 ;
		while (1){
			memset(vis,0,sizeof(vis)) ;
			int t=DFS(S ,INF) ;
			if (t<0)break ;
			Ans+=t ;
		}
		printf("Network %d\nThe bandwidth is %d.\n",++time ,Ans ) ;
	}
}
