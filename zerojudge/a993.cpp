#include<stdio.h>

int main(){
	int n ;
	while (~scanf("%d",&n)){
        int d=0 ;
        int cnt=0 ;
        while (1){
            while (d<n)d=d*10+1 ,cnt++ ;
            if (d%n==0)break ;
            d%=n ;
        }
        printf("%d\n",cnt) ;
	}
}
