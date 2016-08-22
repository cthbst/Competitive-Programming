#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int in,temp;
    while (cin >>in ){
          int a[in-1];
          cin >> a[0];
          in -=1 ;
          while (in){
                cin >>a[in];
                if (a[in]>a[0]){
                   temp =a[0];
                   a[0]=a[in];
                   a[in]=temp;                   
                }
                in--;       
          }
          cout << a[0];     
    }
    return EXIT_SUCCESS;
}
