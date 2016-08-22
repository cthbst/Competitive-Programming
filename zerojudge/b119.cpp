#include<stdio.h>
#include<math.h>


int main(){
    int S ,T ,N ;

    while (~scanf("%d%d%d",&S ,&T ,&N )) {
        //set cost ----------
        int cost[300] ,i=1 ,v ;
        for (i ,v=round(S*0.7);i<=round(T*0.2);i++ )
            cost[i]=v ;
        for (i ,v=round(S*0.8);i<=round(T*0.4);i++ )
            cost[i]=v ;
        for (i ,v=round(S*0.9);i<=round(T*0.6);i++ )
            cost[i]=v ;
        for (i ,v=round(S); i<=T ;i++ )
            cost[i]=v ;

        //count -------------
        int Ans=-round(S*T*0.3) ,num=1 ;

        for (int p=0 ,in ;p<N ;p++ ){
            scanf("%d",&in ) ;
            for (int i=0 ;i<in ;i++ ){
                Ans+=cost[num+i] ;
            }
            num+=in ;
        }
        //output ------------
        printf("%d\n",Ans) ;
    }
}
