#include<stdio.h>
#include<string.h>

const int maxN=671065 ;
bool p[maxN] ;

int main(){
	//build -----------------
	memset(p,1,sizeof(p)) ;
	p[0]=p[1]=0 ;
	for (int i=2 ;i<maxN ;i++ )if (p[i]){
		for (int j=i+i ;j<maxN ;j+=i){
			p[j]=0 ;
		}
	}

	//solve -----------------
	int n ;
	while (~scanf("%d",&n)){
		if (p[n]){
			puts("It's a prime!!!") ;
		}
		else {
			puts("It's not a prime!!!") ;
		}
	}
}
