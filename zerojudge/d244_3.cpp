#include<stdio.h>
#include<map>
using namespace std ;

map<int,int> T ;

int main(){
    int k ;
    while (~scanf("%d",&k ))T[k]++ ;

    for (auto it=T.begin() ;it!=T.end() ;it++ ){
        if (it->second%3!=0){
            printf("%d\n",it->first) ;
            break ;
        }
    }
}
