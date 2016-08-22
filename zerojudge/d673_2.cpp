#include<stdio.h>
#include<string.h>

int main(){
	char m[30] ,n[30] ;
	while (scanf("%s %s",m,n) && m[0]!='0' &&  n[0]!='0'){
		if (strlen(m)>strlen(n))
			printf("Unfair\n") ;
		else {
			if (strlen(m)<strlen(n))
				printf("Fair\n") ;
			else {
				int k= 1 ;
				for (int i=0 ;i<strlen(n);i++ ){
					if (m[i]>n[i]){
						k=0 ;
						break ;
					}
					if (m[i]<n[i]){
						break ;
					}
				}
				if (k==1) printf("Fair\n") ;
				else printf("Unfair\n") ;
			}
		}
		
	}
	return 0 ;
}
