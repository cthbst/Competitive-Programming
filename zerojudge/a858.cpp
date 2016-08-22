#include<stdio.h>


int main(){
    int n ;
    scanf("%d",&n) ;
    int ans = 0 ;
    for (int i=0 ;i<n ;i++ ){
        int a=0 ,b=0 ;
        for (int j=0 ,ai ;j<n ;j++ ){
            scanf("%d",&ai ) ;
            if (ai==1)a++ ;
            else if (ai==2)b++ ;
        }
        ans+=a*b ;
    }

    ans=n*(n-1)*(n-2)/6-ans/2 ;
    printf("%d\n",ans) ;
}
