#include<stdio.h>
#include<string.h>
#define N 510
#define K 110
bool OK[2][N*K] ;

int main(){
	int n, k;
	while (~scanf("%d%d",&n ,&k )){
		memset(OK,0,sizeof(OK)) ;
		OK[0][0]=1 ;
		
		int sum= 0 ;
		for (int i=1 ,in ;i<=n ;i++ ){
			scanf("%d",&in ) ;
			sum+=in ;
			
			//dp---------------------------------
			int l=(i+1)%2 ,r=i%2 ;
			for (int j=0 ,t=sum/2 ; j<=t ;j++ ){
				if (OK[l][j]==1 ) {
					if (j-in>=0)OK[r][j-in]=1 ;
					OK[r][j+in]=1 ;
					OK[r][j]=1 ;
				}
			}
		}
		//output---------------------------------
		int ans ;
		for (ans=sum/2;OK[n%2][ans]==0;ans--) ;
		printf("%d %d\n",ans ,sum-ans ) ;
	}
}
