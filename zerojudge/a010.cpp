#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int num,div,plus,i;
	int a[500000];
	while (scanf("%d",&num)!=EOF){
		for (int i=0 ;i<500000;i++ )
			a[i]=0 ;
		
		for (div=2;div<=num;div++){
        	if (num%div==0){
				while (1){
					a[div]++;
				 	num=num/div ;
					if (num%div!=0){
						break;
					}	
				}
		  	}
		  	if (a[div]>1)
		  		printf("%d^%d",div,a[div]); 
		  	if (a[div]==1)
		  		printf("%d",div);
		  	
		  	if (a[div]>0 && num>1)printf(" * ") ;
	    }
	    printf("\n") ;
	}
	
	return 0;
}
