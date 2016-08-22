#include <iostream>
using namespace std ;

int pt (int a){
	int out=1 ;
	while (a--)
		out *=2 ;
	return out ;
}
void show(short a[],int in0){
	for (int i=in0-1;i>=0;i--){
		cout <<a[i];
	}
	cout <<endl ;
}
int main() {
	int in0 ;
	while (cin >>in0 ){
		short a[in0] ;
		for (int i=0 ;i<in0 ;i++ )
			a[i]=0 ;
		int k=pt(in0) ;
		while (k--){
			show(a,in0); 
			a[0]++ ;
			for (int i=0 ;;i++){
				if (a[i]>=2){a[i+1]++ ;a[i]-=2 ;}
				else break ;
			}
		}
	}
}
