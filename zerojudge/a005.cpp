#include<iostream>
using namespace std ;

int main(){
    int Tasks ;
    int a[5] ;

    cin >> Tasks ;
    while (Tasks--){
        //input -------------
        for (int i=0 ;i<4 ;i++ )
            cin >> a[i] ;

        //solve -------------
        if (a[1]-a[0]==a[2]-a[1])   // 等差數列
            a[4]=a[3]*2-a[2] ;
        else                        // 等比數列
            a[4]=a[3]*a[3]/a[2] ;

        //output ------------
        for (int i=0 ;i<4 ;i++ )
            cout << a[i] << " " ;
        cout << a[4] << endl ;
    }
}
