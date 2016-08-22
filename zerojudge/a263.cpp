#include<stdio.h>

int day_of_year(int y ){
    if (y%4>0)return 365 ;
    if (y%100==0 && y%400>0)return 365 ;
    return 366 ;
}

int M[]={0,31,28,31,30,31,30,31,31,30,31,30,31} ;
int day_of_month(int y,int m){
    if (m!=2)return M[m] ;
    return 28+day_of_year(y)-365 ;
}

int Day(int y ,int m ,int d ){
    int sum=d ;
    for (int i=0 ;i<y ;i++ )sum+=day_of_year(i) ;
    for (int i=1 ;i<m ;i++ )sum+=day_of_month(y,i) ;
    return sum ;
}
int main(){
    int y1 ,m1 ,d1 ,y2 ,m2 ,d2 ;
    while (~scanf("%d%d%d%d%d%d",&y1 ,&m1 ,&d1 ,&y2 ,&m2 ,&d2) ){
        int Ans=Day(y1,m1,d1)-Day(y2,m2,d2) ;
        printf("%d\n",Ans>0?Ans:-Ans) ;
    }
}
