#include<stdio.h>
#include<string.h>
#include<sstream>
#include<iostream>
using namespace std ;

typedef long long int LL ;

char in[100000] ;
int main(){
    while (cin.getline(in,sizeof(in))){
        stringstream s ;
        s << in ;

        LL sum=0 ,a ;
        while (s>>a){
            sum+=a ;
        }
        printf("%lld\n",sum) ;
    }
}
