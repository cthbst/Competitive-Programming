#include <iostream>

using namespace std ;

int main() {
	int in0 ,in1 ,k;
	cin >>k ;
	while (k--){
		cin >>in0 >>in1 ;
		int out=1 ;
		
		for (int i=1 ;i<in1 ;i++ ){
			out*=(in0-i) ;
			out/=i ;		
		}
		cout <<out <<endl ;		
	}
}
