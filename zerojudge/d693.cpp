#include <iostream>
using namespace std ;

int gcd(int in0,int in1){
	while (in0!=0&&in1!=0){
			if (in0>in1){
				in0%=in1 ; 
			}
			else {
				in1%=in0  ;
			}
	}
	return (in0?in0:in1)  ;
}

int main() {
	int N =0 ;
	
	while (cin >>N && N!=0 ){
		int a[N] ;
		for (int i=0 ;i<N;i++ )
			cin >>a[i] ;
		long long out =a[0]*a[1]/gcd(a[0],a[1]) ;
		for (int i=2 ;i<N;i++)
			out=out/gcd(out,a[i]) *a[i];
		cout <<out <<endl ;		
	}
	
}
