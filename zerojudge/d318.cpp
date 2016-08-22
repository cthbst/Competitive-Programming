#include<stdio.h>
#include<stack>
using namespace std;

int main(){
    int n ;
    while (scanf("%d",&n)){
        if (n<0)break ;
        stack<int> sta ;
        do {
            sta.push(n%3) ;
            n/=3 ;
        }while (n) ;
        while (!sta.empty()){
            printf("%d",sta.top()) ;
            sta.pop() ;
        }
        puts("") ;
    }
}
