#include <iostream>

int pd0 (char in0 ,char in1 ){
    if (in0 =='8' ){    //站 
       if (in1 =='8' )  //再站 
          return 5 ;
       else             //變坐 
            return 2 ;
    }
    else {              //坐 
         if (in1 =='1' )//再坐 
            return 1 ;
         else           //變站 
              return 7 ; 
    }
}

using namespace std;
int main(void)
{
    int in0 ;
    
    cin >>in0 ;
    char in[in0][5][5] ;
    int out[in0-1] ;
    
    for (int i=0 ;i<5;i++ )
        for (int i1=0 ;i1<5;i1++ )
            cin >>in[0][i][i1] ;
    
    for (int i=1 ;i<in0;i++ ){
        out[i-1] =0 ;
        for (int i1=0 ;i1<5;i1++ )
            for (int i2=0 ;i2<5;i2++ ){
                cin >>in[i][i1][i2] ;
                out[i-1] +=pd0(in[i-1][i1][i2],in[i][i1][i2]) ;
            }   
        
    }
    
    for (int i=0 ;i<in0-1;i++)
        cout <<out[i] <<endl ;
    
    
    return 0;
}
