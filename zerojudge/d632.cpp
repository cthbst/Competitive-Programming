#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std ;
struct str{
    char a[40] ;

    string operator + (const str B )const {
        char re[40] ;
        for (int i=31 ,c=0 ;i>=0 ;i-- ){
            c=c/2+this->a[i]+B.a[i]-'0'*2 ;
            re[i]='0'+c%2 ;
        }
        re[32]=0 ;
        return (string)re;
    }
};

int main(){
    str A ,B ;
    while (~scanf("%s%s",A.a ,B.a )){
        cout << A.a <<endl <<B.a <<endl ;
        cout <<"---------------------------------" <<endl ;
        cout << (A+B) <<endl ;
        puts("****End of Data******************") ;
    }
}
