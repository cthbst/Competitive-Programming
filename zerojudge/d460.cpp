#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int in;
    while (cin >>in ){
          if (in>=60)
             cout <<"399";
          else if (in>=18)
               cout <<"890" ;
          else if (in>=12)
               cout <<"790" ;
          else if (in>=6)
               cout <<"590" ;
          else 
               cout <<"0" ;
          cout <<endl ;
    }
    return EXIT_SUCCESS;
}
