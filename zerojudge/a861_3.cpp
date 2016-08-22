#include<stdio.h>
#include<algorithm>
using namespace std ;
#include<string.h>
#define MAX_item 100000
int item[MAX_item ] ;
int food_line[1050] ,out[1050] ,count_food ;

int main(){
    int T ;
    scanf("%d",&T ) ;
    for (int t=0 ;t<T ;t++ ){
        memset(item,0,sizeof(item) ) ;
        memset(food_line,0,sizeof(food_line )) ;
        memset(out,0,sizeof(out )) ;
        count_food=0 ;
        
        int item_count ,food_count ;
        scanf("%d%d",&item_count,&food_count) ;
        
        //item_input---------------------------------------
        char input[100000] ;
        gets(input) ;
        int number ;
        for (int i=0 ;i<item_count ;i++ ){
            gets(input) ;
            char *pch=strchr(input,'m') ;
            sscanf(pch+1 ,"%d",&number ) ;
            pch=strchr(input,'$') ;
            sscanf(pch+1 ,"%d",&item[number] ) ;
        }
        
        //food_input---------------------------------------
        for (int i=0 ;i<food_count ;i++ ){
            gets(input) ;
            
            //food1234---------------------------
            char *pch=strchr(input,'d') ;
            sscanf(pch+1,"%d", &food_line[i]) ;
            //$1234------------------------------
            int cost ;
            pch=strchr(input,'$') ;
            sscanf(pch+1 ,"%d",&cost ) ;
            //item-------------------------------
            int t ,type ;
            pch=strchr(input,':') ;
            pch=strchr(pch+1 ,' ') ;
            while (pch!=NULL && cost>0){     
                  sscanf(pch+1,"%d" ,&t ) ;
                  pch=strchr(pch+1 ,'m') ;
                  sscanf(pch+1,"%d" ,&type ) ;
                  
                  if (item[type]==0){
                     cost*=(-1) ;
                     break ;
                  }
                  
                  cost-=t*item[type] ;
                  
                  pch=strchr(pch+1 ,' ') ;
            }
            if (cost>0 ){
               out[count_food++]=food_line[i] ;
            }
        }
        sort(out,out+count_food) ;
        if (!count_food ){
           printf("no such recipe.") ;
        }
        else {
             printf("food%d",out[0]) ;
             for (int i=1 ;i<count_food ;i++ ){
                printf("/food%d",out[i]) ;
             }
        }
        if (t<T-1)printf("\n")  ;
    }
}
