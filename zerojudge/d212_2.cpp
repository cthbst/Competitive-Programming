#include<stdio.h>
#include<string.h>
#define MAX 2010
char view[MAX][MAX] ;
void pushfront(int i ,char in){
     int l =strlen(view[i-1]) ;
     view[i][0]=in ;
     for (int j=0 ;j<=l ;j++ ){
         view[i][j+1] = view[i-1][j] ;
     }
}
void pushback(int i ,char in){
     strcpy(view[i] , view[i-1] ) ;
     int l =strlen(view[i-1]) ;
     view[i][l+1]='\0' ;
     view[i][l]=in ;
}
int main()
{
    int T ;
    scanf("%d",&T) ;
    while (T--){
          memset(view ,0 ,sizeof(view) )  ;
          
          int N ;
          scanf("%d",&N) ;
          
          for (int i=0 ;i<N ;i++ ){
              char in1[15] ,in2[5] ;
              scanf("%s%s",&in1,&in2) ;
              
              if (in1[0]=='u'){
                 int k ;
                 sscanf(in2,"%d",&k) ;
                 strcpy(view[i] , view[i-k-1]) ;
              }
              else if (in1[4]=='f'){
                   pushfront( i ,in2[0]) ;
              }
              else {
                   pushback ( i ,in2[0]) ;
              }
              printf("%s\n",view[i]) ;
          }
          
    }
}
