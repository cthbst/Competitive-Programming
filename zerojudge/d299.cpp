#include<stdio.h>
#include<algorithm>
using namespace std ;

int main(){
    int a[]={0,1,2,3,4,5,6,7,8,9} ;
    do {
        //01234 356 356 78934
        int FORTY = a[0]*10000+a[1]*1000+a[2]*100+a[3]*10+a[4] ;
        int TEN = a[3]*100+a[5]*10+a[6] ;
        int SIXTY = a[7]*10000+a[8]*1000+a[9]*100+a[3]*10+a[4] ;
        if (FORTY+2*TEN==SIXTY)
            printf("%05d + %03d + %03d = %05d\n",FORTY ,TEN ,TEN ,SIXTY ) ;
    }while (next_permutation(a,a+10)) ;
}
