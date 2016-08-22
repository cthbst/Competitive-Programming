#include<stdio.h>
#include<set>
using namespace std ;

int main(){
	int M ,N ;
	while (~scanf("%d%d",&M ,&N ))while (M--){
		set<int> S[2] ;
		S[0].insert(0) ;
		for (int i=0 ,in ;i<N ;i++ ){
			int w=i%2 ,q=(i+1)%2 ;
			scanf("%d",&in) ;
			set<int>::iterator it=S[w].begin() ;
			for (it ;it!=S[w].end() && *it>=in ;++it ){
				S[q].insert( *it +in ) ;
				if (*it-in>=0)S[q].insert( *it -in ) ;
			}
			for (it ;it!=S[w].end() ;++it ){
				S[q].insert( *it +in ) ;
				S[q].insert( *it -in ) ;
			}
			
			S[w].clear() ;
		}
		
		int c1=S[N%2].size() ;
		S[N%2].insert(0) ;
		int c2=S[N%2].size() ;
		
		if (c1==c2){
			printf("Yes\n") ;
		}
		else {
			printf("No\n") ;
		}
	}
}
