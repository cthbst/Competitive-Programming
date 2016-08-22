#include<stdio.h>
#include<string.h>
 
#define Max 110

int N ,M ;
int Graph[Max][Max] ;

int dx[]={0,0,1,-1} ,dy[]={1,-1,0,0} ;
int DFS(int x, int y ){
	if (Graph[x][y]==0)return 0 ;
	
	int sum=Graph[x][y] ;
	Graph[x][y]=0 ;
	
	for (int i=0 ;i<4 ;i++ )
		sum+=DFS(x+dx[i] ,y+dy[i] ) ;
	
	return sum ;
}

int main(){
	while (~scanf("%d%d",&N ,&M )){
		memset(Graph,0,sizeof(Graph)) ;
		//input--------------------------------------------
		for (int i=1 ;i<=N ;i++ )
			for (int j=1 ;j<=M ;j++ )
				scanf("%d",&Graph[i][j]) ;
		//DFS----------------------------------------------
		int Ans=0 ,count=0 ;
		for (int i=1 ;i<=N ;i++ ){
			for (int j=1 ;j<=M ;j++ ){
				if (Graph[i][j]>0){
					count++ ;
					int sum=DFS(i,j) ;
					if (sum>Ans)Ans=sum ;
				}
			}
		}
		//output-------------------------------------------
		printf("%d\n%d\n",count ,Ans ) ;
	}
}
