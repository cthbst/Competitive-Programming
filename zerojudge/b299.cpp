#include<stdio.h>

int main(){
    int T ;
    scanf("%d",&T ) ;

    int N ,M ;
    while (T-- && scanf("%d%d",&N ,&M )){
		bool ok=1 ;
        for (int i=0 ,wi ;i<M;i++){
			scanf("%d",&wi ) ;
			if (N>wi)ok=0 ;
        }
        if (ok){
			puts("YEEES!!! INKER!") ;
        }
        else {
			puts("NOOOO!!! JACKY XX!") ;
        }
    }
}
