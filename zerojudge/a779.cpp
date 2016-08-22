#include<stdio.h>
#include<string.h>

#define MAXL 1000
char a[MAXL] ,b[MAXL] ;
int len= 0 ; 
int main(){
	while (gets(a)){
		len=0 ;
		for (int i=0 ,l=strlen(a);i<l ;i++ ){
			//printf("%d ",a[i]) ;
			if (a[i]<='Z' && a[i]>='A')      b[len++]=a[i]-'A'+'a' ;
			else if (a[i]<='z' && a[i]>='a' )b[len++]=a[i] ;
			else if (a[i]<='9' && a[i]>='0') b[len++]=a[i] ;
		}
		b[len]='\0' ;
		
		int ok=1 ;
		for (int i=0 ,l=len/2 ;i<=l ;i++ ){
			if (b[i]!=b[len-i-1]){
				ok=0 ;
				break ;
			}
		}
		printf("%s\n",a) ;
		if (ok==1)printf("-- is a palindrome\n") ;
		else printf("-- is not a palindrome\n") ;
	} 
		
}
