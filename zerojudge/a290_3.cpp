#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std ;

#define MAXN 1000 
bool map[MAXN][MAXN] ;
bool vis[MAXN] ;
int main(){
	int N ,M ; 
	while (~scanf("%d%d",&N ,&M )){
		memset(map,0,sizeof(map) ) ;
		for (int i=0 ,a,b ;i<M ;i++ ){
			scanf("%d%d",&a ,&b ) ;
			map[a][b]=1 ;
		}
		
		int A ,B ;
		scanf("%d%d",&A ,&B ) ;
		memset(vis,0,sizeof(vis) ) ;
		queue<int> que ;
		
		que.push(A) ;
		while (!que.empty() && !vis[B] ){
			int walk= que.front() ; que.pop() ;
			vis[walk]=1 ;
			for (int i=1 ;i<=N ;i++ )
				if (!vis[i] && map[walk][i] ){
					que.push(i) ;
				}
		}
		printf("%s\n",vis[B]?"Yes!!!":"No!!!") ;
	}
}
