#include<stdio.h>

int main(){
    char c ;
    bool flag=0 ;
    while (c=getchar()){
        if (c==EOF)break ;
        if (c=='"'){
            if (flag==0)printf("``") ;
            else printf("''") ;

            flag=!flag ;
        }
        else {
            putchar(c) ;
        }
    }
}
