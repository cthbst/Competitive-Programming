#include<stdio.h>
#include<string.h>
bool vis[10000] ;
int T=65 ;

void walk(int floor ,int *element){
	if (floor==3){
		vis[ (element[0]+element[1])*element[2]+element[0]*element[1] ]=1 ;
	}
	else if (floor==2){
		for (int i=element[floor-1]+1 ;i<=T-3+floor+1;i++ ){
			element[floor]=i ;
			walk(floor+1,element) ;
		}
	}
	else if (floor==1){
		for (int i=element[floor-1]+1 ;i<=T-3+floor+1;i++ ){
			element[floor]=i ;
			walk(floor+1,element) ;
		}
	}
	else {
		for (int i=1 ;i<=T-3+floor+1;i++ ){
			element[floor]=i ;
			walk(floor+1,element) ;
		}
	}
}

int main(){
	int set[]={0,1,2,3,4,5,6,7,8,9,10,12,13,15,16,18,21,22,24,25,28,30,33,37,40,42,45,48,57,58,60,70,72,78,85,88,93,102,105,112,120,130,133,165,168,177,190,210,232,240,253,273,280,312,330,345,357,385,408,462,520,760,840,1320,1365,1848,2277};
	/*	
	freopen("set.txt","w",stdout) ;
	memset(vis,0,sizeof(vis)) ;
	int f[3] ;
	walk(0,f) ;
	for (int i=1 ,t=0 ;t<=65;i++ ){
		if (!vis[i]){
			printf("%d,",i) ;
			t++ ;
		}
	}
	*/
	int n;
	while (~scanf("%d",&n))printf("%d\n",set[n]) ;
}
