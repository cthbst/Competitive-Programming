#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[])
{
    int in0 ;
    
    cin >>in0 ;
    for (int i=0 ;i<in0;i++){
        int in[2] ,sum =0 ;
        
        cin >>in[0] >>in[1] ;
        for (double i1 =in[0] ;i1 < in[1];i1++ ){
            if (sqrt(i1) ==int(sqrt(i1)) ){
               sum +=i1 ;
            }
        }
        cout <<"Case "<<i +1 <<": "<<sum <<endl ;
    }
    return 0;
}
