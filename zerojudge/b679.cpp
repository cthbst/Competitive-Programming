#include<bits/stdc++.h>
using namespace std ;

typedef unsigned long long int ULL ;

bool test(ULL n ,ULL M){
    return n*(n+1)/2 >= M ;
}

int main(){
    ULL M ;
    while (cin >>M ){
        ULL l=0 ,r=(1LL)<<31 ;

        while (l!=r){
            ULL m=(l+r)/2 ;
            if (test(m,M)){
				r=m ;
            }
            else {
				l=m+1 ;
            }
        }

        cout << l <<endl ;
    }
}
