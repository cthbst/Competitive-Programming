#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int in1 ,in2 ;
    cin >>in1 >>in2 ;
    if (in1>=17){
       cout <<"Off School" ;
    }
    else if (in1<=7){
         if (in1==7 && in2<30){
            cout <<"Off School" ;
         }
         else if (in1<7){
              cout <<"Off School" ;
              
         }
         else {
              cout <<"At School" ;
         }
         
    }
    else {
         cout <<"At School" ;
    }
    cout <<endl ;
    return EXIT_SUCCESS;
}
