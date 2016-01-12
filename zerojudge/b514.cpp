#include<bits/stdc++.h>
using namespace std ;

int main(){
    int T ; cin >> T ;

    int a ,b ,c ,d ,e ,f ;
    while (T-- && cin >> a >> b >> c >> d >> e >>f ){
        int delta = a*e-b*d ;
        cout << (c*e-b*f)/delta <<" " << (a*f-c*d)/delta <<endl ;
    }
}
