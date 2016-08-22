#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std ;

#define MAXN 1000 
char G[MAXN][MAXN] ;
int t[MAXN][MAXN] ; 
int dx[]={1,-1,0,0} ,dy[]={0,0,1,-1} ; 

int main (){
	int N ;
	scanf("%d",&N ) ;
	
	for (int i=0 ;i<N ;i++ )scanf("%s",&G[i]) ;
	
	memset(t,-1,sizeof(t)) ;
	//BFS------------------------------------------------------------
	queue<pair<int,int> > S ;
	S.push({1,1}) ;
	G[1][1]='#' ;
	t[1][1]=1 ;
	
	while(!S.empty()){
		pair<int,int> w=S.front() ;S.pop() ;	
		int x=w.first ,y=w.second ;
		for (int i=0 ;i<4 ;i++ ){
			if (G[x+dx[i]][y+dy[i]]=='.'){
				S.push({x+dx[i],y+dy[i]}) ;
				t[x+dx[i]][y+dy[i]]=t[x][y]+1 ;
				G[x+dx[i]][y+dy[i]]='#' ;
			}
		}
	}
	//output---------------------------------------------------------
	if (t[N-2][N-2]==-1)printf("No solution!") ; 
	else printf("%d\n",t[N-2][N-2]) ;
	 
}
