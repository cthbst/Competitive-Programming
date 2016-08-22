#include<stdio.h>
#include<string.h>

int next[1030] ;
char aph[1030] ;

int main(){
    int T ,N ; scanf("%d",&T ) ;
    
    while (T-- && scanf("%d",&N ) ){
          int a ,b ; 
          char c[5] ;
          memset(next ,-1 ,sizeof(next) ) ;
          
          scanf("%d%s%d",&a ,&c ,&b ) ;
          next[a]=b ;
          aph[a]=c[0] ;
          int start=a ;
          
          for (int i=1 ;i<N ;i++ ){
              scanf("%d%s%d",&a ,&c ,&b ) ;
              next[a]=b ;
              aph[a]=c[0] ;
          }
          
          while (next[start]!=0 ){
                printf("%c",aph[start]) ;
                start =next[start] ;
          }
          printf("\n") ;
    }  
        
}
