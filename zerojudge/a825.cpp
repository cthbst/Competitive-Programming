/**********************************************************************************/
/*  Problem: a825 "100學年度桃竹苗區資訊學科能力競賽 3.小四數學" from 100學年度桃竹苗區資訊學科能力競賽*/
/*  Language: CPP (1576 Bytes)                                                    */
/*  Result: AC(4ms, 264KB) judge by this@ZeroJudge                                */
/*  Author: cthbst at 2013-11-04 14:36:26                                         */
/**********************************************************************************/


#include<stdio.h>
#include<string.h>
int MAX=0 ,n ,number[9],yes[9];
long long int sort(int *in,bool a){
    int walk_number[9] ,count=0 ;
    //find-----------------------------------------------------------
    for (int i=0 ;i<n;i++ ){
        if (in[i]==a )walk_number[count++]=number[i] ;         
    }
    //sort-----------------------------------------------------------
    for (int i=0 ;i<count;i++ )
        for (int j=i ;j<count;j++ )
            if (walk_number[i]<walk_number[j]){
               int t=walk_number[i] ;
               walk_number[i]=walk_number[j] ;
               walk_number[j]=t ;
            }
    //sum------------------------------------------------------------
    long long int out =0 ;
    for (int i=0 ;i<count ;i++ ){
        out=out*10+walk_number[i] ;
    }
    //return---------------------------------------------------------
    return out ;
}
//遞迴--------------------------------------------------------------- 
void walk(int k ,int *a){
     if (k<0){
        int m=sort(a,1)*sort(a,0) ;
        if (m>MAX)MAX=m ;
     }
     if (k>=0){
        a[k]=0 ;walk(k-1,a) ;
        a[k]=1 ;walk(k-1,a) ;
     } 
}
int main(){
    //input----------------------------------------------------------
    scanf("%d",&n) ;
    for (int i=0 ;i<n;i++ )scanf("%d",&number[i]) ;
    //cooking--------------------------------------------------------
    memset(yes,0,sizeof(yes)) ;
    walk(n-1,yes) ; 
    //output---------------------------------------------------------
    printf("%d",MAX) ;
}
