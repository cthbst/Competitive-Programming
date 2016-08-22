#include <iostream>

using namespace std;

int main(){    
    char input[10010]={0};
    
    while (cin >>input){
          int sum=0 ;
          
          for (int i=0 ;input[i];i++ ){            
              sum+=input[i]-'0' ;
              sum=sum%3 ;
          }
          cout <<(sum?"no":"yes")<<endl ;
    }
}
