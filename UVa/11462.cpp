#include<bits/stdc++.h>
using namespace std ;

int n ,cnt[130] ;

int main(){
    while (~scanf("%d",&n) && n!=0 ){
        memset(cnt,0,sizeof(cnt)) ;
        for (int i=0 ,ai ;i<n ;i++ ){
            scanf("%d",&ai ) ;
            cnt[ai]++ ;
        }

        for (int i=0 ;i<=100 ;i++ ){
            while (cnt[i]>0){
                printf("%d",i ) ;
                cnt[i]-- ,n-- ;
                if (n)printf(" ") ;
            }
        }
        puts("") ;
    }
}
