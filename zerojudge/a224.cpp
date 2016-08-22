#include <iostream>
#include <cstring>
using namespace std ;

int to_array(char a ){
	int pt=(int)a-'a' ;
	if (pt<0) pt=a-'A' ;
	
	return (pt>=0&&pt<=25?pt:26) ;	
}

int main() {
	char input[1010] ;
	while (cin >>input){
		int a[27] ;
		for (int i=0 ;i<27;i++ )
			a[i]=0 ;
		for (int i=0 ;i<strlen(input);i++ )
			a[to_array(input[i])]++ ;
		int out =0 ;
		for (int i=0 ;i<26;i++ )
			out+=a[i]%2 ;
		cout <<(out<=1?"yes !":"no...") <<endl ;
			
	}
	
}
