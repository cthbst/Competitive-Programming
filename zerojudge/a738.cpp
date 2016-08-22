#include<iostream>
using namespace std ;

int main(){
	int in0 =0,in1=0 ;
	while (cin >>in0 >>in1 &&in0!='eof'&&in1!='eof'){
		while (in0!=0&&in1!=0){
			if (in0>in1){
				in0%=in1 ; 
			}
			else {
				in1%=in0  ;
			}
		}
		cout <<(in0?in0:in1) <<endl ;
	}	
}
