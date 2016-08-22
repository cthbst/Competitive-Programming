#include<stdio.h>
#include<algorithm>
using namespace std ;

struct str{double x ,y ;};

double area(str a ,str b ,str c ){
    str v1=(str){b.x-a.x,b.y-a.y} ;
    str v2=(str){c.x-a.x,c.y-a.y} ;
    double re=(v1.x*v2.y-v1.y*v2.x)/2.0 ;
    if (re<0)return -re ;
    return re ;
}

str S[1000] ;

int main(){
    int N ;
    while (~scanf("%d",&N )){
        for (int i=0 ;i<N ;i++ )scanf("%lf %lf",&S[i].x ,&S[i].y ) ;

        double Ans=0.0 ;
        for (int i=0 ;i<N ;i++ )
            for (int j=i+1 ;j<N ;j++ )
                for (int k=j+1 ;k<N ;k++ )
                    Ans=max(Ans,area(S[i],S[j],S[k])) ;
        printf("%.6f\n",Ans) ;
    }
}
