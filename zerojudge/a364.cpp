#include<stdio.h>

void solve(int N ){
    for (int i=1 ;i<500 ;i++ ){
        for (int j=0 ;j<i ;j++ ){
            for (int k=0 ;k<j ;k++ ){
                if (i*(i-1)*(i-2)/6+j*(j-1)/2+k==N){
                    printf("%d%d%d\n",i,j,k) ;
                    return ;
                }
            }
        }
    }
}

int main(){
    int T ,N ;scanf("%d",&T ) ;

    while (T-- && scanf("%d",&N )){
        solve(N) ;
    }
}
