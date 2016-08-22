#include <iostream>
#include <cstring>
using namespace std ;

int main() {
	int K ;
	cin >>K ;
	for (short i=0 ;i<K;i++ ){
		char name[110] ;
		int M ,no_see=0;
		cin >>name >>M;
		
		cout <<"DATA SET #"<<i+1<<":\n";
		
		for (short j=0 ;j<strlen(name);j++){
			if ((int)name[j]==35) no_see=j;
		}
		
		
		char test[110] ;
		while (M--){
			int OK=1 ;
			cin >>test ;
			//if (strlen(name)-1<strlen(test)) OK=0 ;
			for (int j=0 ;j<no_see && OK!=0;j++ ){
				if(name[j]!=test[j]) OK=0 ;
			}
			cout <<endl ;
			for (int j=0 ;strlen(name)-1-j>no_see&&OK!=0 ;j++)
				if (name[strlen(name)-1-j]!=test[strlen(test)-1-j]) OK=0 ;
			cout <<(OK==1?"POSSIBLE":"IMPOSSIBLE")<<endl ;
		}
			
				
	}
}
