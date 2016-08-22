#include<stdio.h>
#include<string.h>
#define MAX 10+2
int map[MAX][MAX] ; 

void output(char o ,int straight){
	if (straight)
		printf("%c%d",o,straight) ;
}

int main(){
	int in0 ;
	scanf("%d",&in0) ;
	while (in0--){
		int H, W ;
		scanf("%d%d",&H,&W) ;
		memset(map,-1,sizeof(map)) ;
		
		int site[2]={0} ,count=0 ,straight=0;
		for (int i=0 ;i<H ;i++)
			for (int j=0 ;j<W ;j++){
				scanf("%d",&map[i][j]) ;
				if (map[i][j]==0){
					site[0]=i ;
					site[1]=j ;
				}
			}
		while (1){
			int ok=0 ;
			straight=0 ;
			while (site[0]-1>=0 && map[site[0]-1][site[1]]==count+1 ){
				count++ ;
				straight++ ;
				site[0]-- ;
				ok=1 ;
			}
			output('N',straight) ; straight=0 ;
			while (site[0]+1< H && map[site[0]+1][site[1]]==count+1 ){
				count++ ;
				straight++ ;
				site[0]++ ;
				ok=1 ;
			}
			output('S',straight) ; straight=0 ;
			while (site[1]-1>=0 && map[site[0]][site[1]-1]==count+1 ){
				count++ ;
				straight++ ;
				site[1]-- ;
				ok=1 ;
			}
			output('W',straight) ; straight=0 ;
			while (site[1]+1< W && map[site[0]][site[1]+1]==count+1 ){
				count++ ;
				straight++ ;
				site[1]++ ;
				ok=1 ;
			}
			output('E',straight) ; straight=0 ;
			if (ok==0) break ;
		}
		printf("\n") ;
	}
}
