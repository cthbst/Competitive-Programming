#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n ;

    char people[]="UGYTI" ;
	while (cin>>n){
		cout << people[n%5] <<endl ;
	}
}
