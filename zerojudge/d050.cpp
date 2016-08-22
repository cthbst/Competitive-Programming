#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
   int a;   
   while (cin >>a ){
         a-=15;
         cout << (a<0?a+24:a) <<endl ;
   }   return 0;
}
