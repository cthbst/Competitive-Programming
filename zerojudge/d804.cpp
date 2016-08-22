#include<stdio.h>
#include<algorithm>
using namespace std ;

int food[100010] ;

bool cmp(int a,int b){
	return a>b ;
}

int main(){
	int N ,M ;
	while (~scanf("%d%d",&N ,&M )){
		for (int i=0 ;i<N ;i++ )scanf("%d",&food[i]) ;
		sort(food,food+N,cmp ) ; 
		
		for (int i=1 ;i<N ;i++ ) food[i]+=food[i-1] ;
		
		int ans=lower_bound(food,food+N,M)-food+1 ;
		
		if (ans>N )printf("OAQ\n") ;
		else printf("%d\n",ans) ;
	}
	
}
