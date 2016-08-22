#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

typedef struct {
	int M[230] ;
}str;
str S[10030] ;

int N ,M ;
bool cmp(str a,str b) {
	for (int i=0 ;i<M ;i++ )
		if (a.M[i]!=b.M[i])return a.M[i]<b.M[i] ;
	return 0 ;
}

int main(){
	memset(S,0,sizeof(S)) ;
	//input----------------------------
	scanf("%d%d",&N ,&M ) ;
	for (int i=0 ;i<N ;i++ )
		for (int j=0 ;j<M ;j++ )
			scanf("%d",&S[i].M[j]) ;
	//sort-----------------------------
	sort(S,S+N,cmp) ; 
	//output---------------------------	
	for (int i=0 ;i<N ;i++ ){
		for (int j=0 ;j<M ;j++ )
			printf("%d ",S[i].M[j]) ;
		printf("\n") ;
	}
}
