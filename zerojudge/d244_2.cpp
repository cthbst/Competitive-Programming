#include<stdio.h>
#include<map>
using namespace std ;

map<int,int> T ;

int main(){
    int k ;
    while (~scanf("%d",&k )){
        T[k]++ ;
        if (T[k]==3){
            auto it=T.find(k) ;
            T.erase(it) ;
        }
    }
    printf("%d\n",T.begin()->first) ;
}
