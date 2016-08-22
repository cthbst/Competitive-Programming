#include <iostream>
#include <cmath>

using namespace std ;

int main() {
	int in0 ;
	while (cin >>in0 ){
		for (int i=2 ;i<=sqrt(in0);i++ ){
			if (in0%i==0){
				cout <<i ;
				int i2 =0 ;
				while (in0%i==0){
					i2++ ;
					in0/= i;
				}
				if (in0==1){
					cout <<"^" <<i2 <<endl ;
				}
				else if (i2>1 ){
					cout <<"^" <<i2 <<" * ";
				}
				else if (i2==1&in0>1){
					cout <<" * " ;
				}
				
			}
		}
		if (in0>1)
			cout <<in0 <<endl ;
	}
}
