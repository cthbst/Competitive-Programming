#include<stdio.h>
#include<string.h>

int abs(int x){
    if (x<0)return -x ;
    return x ;
}

char s[100030] ;

int main(){
    while (~scanf("%s",s)){
        int ans=0 ,cnt=0 ,i ;
        for (i=0 ;s[i]>0;i++ )if(s[i]=='y'){
            ans+=abs(cnt++*3-i) ;
        }
        printf("%d\n",ans ) ;
    }
}
