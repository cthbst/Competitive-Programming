#include<stdio.h>
#include<string.h> 
#define MAX 100+10 
short room[MAX][MAX] ;
int walk(int x ,int y ){
	if (room[x][y]==0) return 0 ;
	
	int sum=room[x][y] ;
	room[x][y]=0 ;
	sum+=walk(x-1,y) ;
	sum+=walk(x+1,y) ;
	sum+=walk(x,y+1) ;
	sum+=walk(x,y-1) ;
	return sum ;
}

int main(){
	int N ,M ;
	while (scanf("%d%d",&N,&M)!=EOF){
		memset(room,0,sizeof(room)) ;
		int count=0 ,MAX_sum=0;
		//input -------------------------------------------
		for (int i=0 ;i<N ;i++ )
			for (int j=0 ;j<M ;j++ ) 
				scanf("%d",&room[i+1][j+1]) ;
		//walk---------------------------------------------
		for (int i=0 ;i<N ;i++ ){
			for (int j=0 ;j<M ;j++ ){
				int k=walk(i+1,j+1) ;
				if(k>0){
					count++ ;
					if(k>MAX_sum) MAX_sum=k ;
				} 
			}
		} 
		//output-------------------------------------------
		printf("%d\n%d\n",count,MAX_sum) ;
	}
}
