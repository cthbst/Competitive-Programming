#include<iostream>
using namespace std ;

int main(){
	int T ; cin >> T ;
	
	int a ,b ;
	for (int t=1 ;t<=T ;t++){
		cin >> a >> b ;
		
		int sum=0 ;
		for (int i=1 ;i*i<=b ;i++ ){
			if (i*i>=a){
				sum+=i*i ;
			}
		}

		cout << "Case "<< t <<": " << sum  <<endl ;
	}
}
