#include <iostream>

using namespace std;

int main()
{
    short in[10] ;
    
    for (short i=0 ;i<10;i++ )
              cin >>in[i] ;
    
              
    int pt0 ;
    
    cin >>pt0 ;
    
    pt0+=30 ;
    
    
    short out =0 ;
    
    for (short i=0 ;i<10;i++ )
        if (in[i] <=pt0 ){
           out++ ;
        }
          
    cout <<out <<endl ;
}
