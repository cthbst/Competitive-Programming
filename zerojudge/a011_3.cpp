#include<stdio.h>
#include<string.h>
#include<math.h>

typedef long long int LL ; 
#define MAXN 1010 
LL v[MAXN][2] ;
unsigned long long int d[MAXN];
bool vis[MAXN] ;
int main(){
	int T ,N ;
	scanf("%d",&T ) ;
	while (T-- && scanf("%d",&N )){
		//input--------------------------------------------
		for (int i=0 ;i<N ;i++ )
			scanf("%lld%lld",&v[i][0] ,&v[i][1] ) ;
		//prim---------------------------------------------
		unsigned long long int ans=0 ;
		memset(d,63,sizeof(d)) ;
		for (int i=0 ;i<N ;i++ )d[i]*=3 ;
		
		memset(vis,0,sizeof(vis)) ;
		d[0]=0 ;
		
		int walk=0 ,next=0 ;
		for (int i=0 ;i<N ;i++ ){
			vis[walk]=1 ;
			
			for (int j=0 ;j<N ;j++ )if (!vis[j]){
				LL l=(v[walk][0]-v[j][0])*(v[walk][0]-v[j][0])+
					 (v[walk][1]-v[j][1])*(v[walk][1]-v[j][1]);
				if (d[j]>l)d[j]=l ;
				if (vis[next]==1 ||d[j]<d[next] )next=j ;
			}
			walk=next ;
			if (d[walk]>ans)ans=d[walk] ;
		}
		//output---------------------------------
		ans=ceil(sqrt(ans/4.0)) ;
		printf("%lld\n",ans) ;
		
	}
}
