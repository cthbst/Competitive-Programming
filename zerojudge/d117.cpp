#include <iostream>
#include <string>
#include <cmath>

short prime (int in0 ){
      short out =0 ;
      
      for (int i=2 ;i<=sqrt(in0);i++ ){
          if (in0%i==0){
             out=1;
             break;
          }
      }

      return out ;
}

using namespace std ;

int main() {
	string s ;
	while (cin >>s ){
		int sum =0;
		for (int i=0 ;i<s.size();i++){
			if ((int)(s.at(i))>96)
				sum+=(int)(s.at(i))-96 ;
			else 
				sum +=(int)(s.at(i))-38 ;
		}
		cout <<(prime(sum)?"It is not a prime word.":"It is a prime word.") <<endl ;
	}
	
}
