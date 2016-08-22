#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack> 
using namespace std ;
#define MAX 1000000
int t[MAX] ;

void walk(int inn){
	long long int n=inn ;
	stack<long long int>S ;
	
	while (n>MAX||t[n]==0){
		S.push(n) ;
		if (n%2)n=3*n+1 ;
		else n/=2 ;
	}
	
	for (int i=t[n]+1 ;!S.empty();++i ){
		if (S.top()<MAX)t[ S.top() ]=i ;
		S.pop() ;
	}
}

int main(){
	memset(t,0,sizeof(t)) ;
	t[1]=1 ;
	
	for (int i=MAX-1 ;i>1;i-- )if (t[i]==0 ){
		walk(i) ;
	}
	
	int I ,J ;
	while (~scanf("%d%d",&I ,&J )){
		int L=0 ;
		if (I<=J){
			for (int i=I ;i<=J ;i++ )if (t[i]>L )L=t[i] ;
		}
		else {
			for (int i=J ;i<=I ;i++ )if (t[i]>L )L=t[i] ;
		}
		
		//output-------------------------------------------
		printf("%d %d %d\n",I ,J ,L ) ;
	} 
}
