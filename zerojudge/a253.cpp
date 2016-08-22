#include<stdio.h>
#include<map>
using namespace std ;

map<int,int> S ;

int main(){
    for (int i=0 ;i<2 ;i++){
        int idx ,num ;
        while (scanf("%d",&idx) && idx!=-1){
			scanf("%d",&num) ;
            S[idx]+=num ;
        }
    }
    for (auto x : S ){
        if (x.second==0)continue ;
        printf("%d %d\n",x.first ,x.second ) ;
    }
}
