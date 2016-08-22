#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std ;

typedef struct Gt{ int x ,y ,t ; };
struct cmp{
	bool operator()(Gt&f,Gt&s){return f.t>s.t ;}
};

#define MAX 1005
int Ma[MAX][MAX] ;
bool vis[MAX][MAX] ;

int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0} ; 

int main(){
	int T ;scanf("%d",&T) ;
	while (T--){
		//input------------------------------------------------------
		int N,M ;
		scanf("%d%d",&N,&M) ;
		
		for (int i=0 ;i<N ;i++ )
			for (int j=0 ;j<M ;j++ )
				scanf("%d",&Ma[i][j]) ;
		//shortest_path----------------------------------------------
		memset(vis,0,sizeof(vis)) ;		
		priority_queue<Gt,vector<Gt>,cmp >que ;
		
		Gt g={0,0,Ma[0][0] } ;
		que.push(g) ;
		
		while (1){
			int x=que.top().x ,y=que.top().y ,t=que.top().t ;
			//printf("%d ,%d,%d \n",x,y,t) ;
			if (x==N-1 && y==M-1 )break ;
			que.pop() ;
			vis[x][y]=1 ;
			for (int i=0 ;i<4 ;i++ )if (x+dx[i]<N && x+dx[i]+1 && 
										y+dy[i]<M && y+dy[i]+1 && 
										!vis[ x+dx[i] ][ y+dy[i] ]){
				g={x+dx[i] , y+dy[i] ,t+Ma[x+dx[i]][y+dy[i]] } ;
				que.push(g) ;
			}
			
		}
		//output-----------------------------------------------------
		printf("%d\n",que.top().t ) ;
	}
	
}
