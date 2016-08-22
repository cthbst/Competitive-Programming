#include <iostream>
using namespace std ;

int to_L(int a){
	int L =0 ;
	while (a){
		L+=a%10 ;
		a/=10 ;
	}
	return (L<10?L:to_L(L)) ;
}

int main() {
	int N ;
	cin >>N ;
	while (N--){
		int in0 ;
		cin >>in0 ;
		cout <<to_L(in0) <<", "<<(to_L(in0)==2?"Yes":"No") <<endl ;
	}
}
