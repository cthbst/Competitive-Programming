#include <iostream>

using namespace std ;

int main() {
	short A[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33} ;
	char in0 ;
	int in1 ;
	while (cin >>in0 >>in1 ){		
		int sum=in1%10 ;
		in1/=10 ;
		for (int i=1 ;i<9;i++ ){
			sum +=i*(in1%10) ;
			in1/=10 ;
		}
		sum+=(A[in0-65]%10)*9 ;
		sum+=(int)(A[in0-65]/10) ;
		cout <<(sum%10==0?"real":"fake") <<endl;
	}	
}
