#include<stdio.h>
#include<string.h>

int main(){
    char a[20] ,b[20] ;
    while (scanf("%s%s",a,b)){
        if (strcmp(a,"Game")==0 && strcmp(b,"Over")==0 ){
            puts("螢火的蹤跡") ;
            break ;
        }
        if (strcmp(a,"Scissors")==0 && strcmp(b,"Stone")==0 ){
            puts("靈夢獲勝") ;
        }
        if (strcmp(a,"Stone")==0 && strcmp(b,"Scissors")==0 ){
            puts("紫獲勝") ;
        }
        if (strcmp(a,"Scissors")==0 && strcmp(b,"Paper")==0 ){
            puts("紫獲勝") ;
        }
        if (strcmp(a,"Paper")==0 && strcmp(b,"Scissors")==0 ){
            puts("靈夢獲勝") ;
        }
        if (strcmp(a,"Stone")==0 && strcmp(b,"Paper")==0 ){
            puts("靈夢獲勝") ;
        }
        if (strcmp(a,"Paper")==0 && strcmp(b,"Stone")==0 ){
            puts("紫獲勝") ;
        }
    }
}
