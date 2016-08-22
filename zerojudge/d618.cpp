#include<stdio.h>
#include<string.h>

int main(){
    char order[130] ;
    int T ;scanf("%d",&T ) ;

    while (T-- && scanf("%s",order) ){
        char S='1' ;
        for (int i=0 ,l=strlen(order) ;i<l ;i++ ){
            if ((S=='2') && (order[i]=='1'))S=order[i] ;
            else if ((S=='3') && (order[i]=='4'))S=order[i] ;
            else if ((S=='4') && (order[i]=='3'))S=order[i] ;
            else if ((S=='3'||S=='4') && (order[i]=='1'))S=order[i] ;
            else if (S=='1'||S=='5'||S=='6'||S=='7')S=order[i] ;
        }
        printf("%c\n",S) ;
    }
}
