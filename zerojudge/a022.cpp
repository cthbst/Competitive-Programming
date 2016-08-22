#include <iostream>
#include <string>

using namespace std ;

int main() {
	string s ;
	while (cin >>s ){
		short out=1 ;
		for (int i=0 ;i<s.size()/2;i++ ){
			if (s.at(i)!=s.at(s.size()-i-1)){
				out=0 ;
				break ;
			}
		}
		cout <<(out?"yes":"no") <<endl ;
	}
}
