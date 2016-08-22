#include<stdio.h>
#include<string.h>
#include<map>
using namespace std ;

int main(){
	//freopen("in.txt","r",stdin) ;
    char wrong[]="1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./" ;
    char right[]="`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,." ;
	map<char,char> trans ;
    for (int i=0 ;i<strlen(wrong);i++)trans[ wrong[i] ]=right[i] ;

    char c ;
    while (c=getchar()){
		if (c==EOF)break ;
		if (trans[c]!=0)putchar( trans[c] ) ;
		else putchar(c) ;
    }
}
