#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    int in0 ;
    
    while (cin >>in0 ){
          cout <<(in0%2 ==0 ?in0 :in0-1 ) <<endl ;
    }
    
    return 0;
}
