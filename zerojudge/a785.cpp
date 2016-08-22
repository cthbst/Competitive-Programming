#include<stdio.h>
#include<string.h>

char end[4]="aeo" ;
char suf[7]="aeiyow" ;
char out[4][7][3]={{"a","a" ,"ai","a","w" ,"w"} ,
				   {"y","ei","ei","y","ou","w"} ,
				   {"w","ou","oi","w","ou","w"} } ;


int main(){
	char in[1000] ;
	while (gets(in)){
		if (strcmp(in,"END")==0)break ;
		
		int m ;
		for (m=0 ;m<strlen(in);m++ )
			if (in[m]=='-')break ;
		
		for (int i=0 ;i<m-1 ;i++ )printf("%c",in[i]) ;
		
		int ml ,mr ;
		for (int i=0 ;i<3 ;i++ )if (in[m-1]==end[i])ml=i ;
		for (int i=0 ;i<7 ;i++ )if (in[m+1]==suf[i])mr=i ;
		printf("%s",out[ml][mr]) ;
		if (in[m+1]=='o' && in[m+2]=='u')m++ ;
		
		for (int i=m+2 ;i<strlen(in);i++ )printf("%c",in[i]) ;
		
		printf("\n") ;
	}
	
}
