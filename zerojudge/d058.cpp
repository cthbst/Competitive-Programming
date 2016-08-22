#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int in;
    while (cin >>in ){
          if (in ==0 )
             cout << "0" ;
          else 
               cout <<(in >0 ?"1" :"-1" ) ;
          cout <<endl ;
    }
    return EXIT_SUCCESS;
}
