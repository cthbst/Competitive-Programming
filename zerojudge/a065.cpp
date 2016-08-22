#include <iostream>
using namespace std ;

int main() {
	 char in[7]  ;
	 while (cin >>in[0] ){
	 		for (int i=1 ;i<7;i++ ){
	 			cin >>in[i] ;
	 			int k=(int)(in[i]-in[i-1]) ;
	 			cout <<(k>0 ?k:-k) ;
	 		}
	 		cout <<endl ;
	 }
	 	
}
