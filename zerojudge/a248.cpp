#include <iostream>

using namespace std ;

int main() {
	int a ,b ,N ;
	while (cin >>a >>b >>N){
		cout <<a/b <<".";
		a%=b ;
		while (N--){
			a*=10 ;
			cout <<a/b ;
			a%=b ;
		}
		cout <<endl ;
	}
}
