#include<stdio.h>

int main(){
	int M ,N ,P ,R ;
	
	while (scanf("%d%d%d%d",&M ,&N ,&P ,&R ) ){
		if (M==0 && N==0 && P==0 && R==0 )break ;
		int MO=1 ;
		while (P--)MO*=10 ;
		
		if (M==N){
			for (int i=0 ;i<R ;i++ )
				M=N=(N*M)%MO ;
			printf("Draw with %d.\n",M) ;
		}	
		else {
			bool win=M<N ;
			for (int i=0 ;i<R ;i++ ){
				if (win==0)N=(N*M)%MO ;
				else M=(N*M)%MO ;
				win=!win ;
			}
			if (win==0 )printf("The king of childish won the game with %d.\n",M ) ;
			else printf("The ghost of childish won the game with %d.\n",N) ;
		}
	}
}
