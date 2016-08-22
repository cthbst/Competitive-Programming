#include<stdio.h>
#include<string.h>

int a[10030] ;
bool vis[10030] ;

int main(){
	
	int T ,N ;
	scanf("%d",&T ) ;
	
	while (T-- && scanf("%d",&N ) ){
		
		memset(vis,0,sizeof(vis)) ;
		//input--------------------------------------------
		for (int i=0 ;i<N ;i++ )
			scanf("%d",&a[i]) ;
		//find---------------------------------------------
		int ans=0 ,C=0 ,sum=a[0];
		
		for (int i=1 ;i<N ;i++ ){
			sum+=a[i] ;
			if (sum==0 ){
				ans++ ;
				vis[i+1]=1 ;
			}
		}
		
		for (int m=1 ;m<N ;m++)if (!vis[m]){
			C=1 ,sum=a[m] ;
			
			for (int i=m+1 ;i<N ;i++ ){
				sum+=a[i] ;
				if (sum==0){
					C++ ;
					vis[(i+1)%N]=1 ;
				}
			}
			
			if (C>ans)ans=C ;
		}
		
		//output-------------------------------------------
		printf("%d\n",ans) ;
	} 
}
