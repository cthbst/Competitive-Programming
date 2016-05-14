#include<iostream>
using namespace std ;

int main(){
    int x ;
    cin >>x ;

    if (x==0){
        cout << 0 <<endl ;
    }
    else {
        while (x%10==0){
            x/=10 ;
        }
        while (x>0){
            cout <<x%10 ;
            x/=10 ;
        }
        cout <<endl ;
    }
}
