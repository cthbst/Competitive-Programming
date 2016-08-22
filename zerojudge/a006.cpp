#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    
    while (cin >>a >>b >>c ){
          
          if (b*b -4*a*c <0)           //無解 
             cout << "No real root";
          else if (b*b -4*a*c ==0)     //相同解 
               cout <<"Two same roots x=" <<-b /(2*a) ;
          else                         //二組解 
              cout << "Two different roots x1=" << (-b + sqrt(b*b-4*a*c)) / (2*a) 
                   << " , x2=" << (-b - sqrt(b*b-4*a*c)) / (2*a) ; 
          
          cout <<endl ;
          
    }
}
