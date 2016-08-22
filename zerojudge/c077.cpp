#include<stdio.h>
#include<string.h>
int C[30][8] ;

int main(){
    //set_C -----------------
    memset(C,0,sizeof(C)) ;
    C[0][0]=1 ;
    for (int i=0 ;i<=27 ;i++ ){
        for (int j=0 ;j<=6;j++ ){
            C[i+1][j+1]+=C[i][j] ;
            C[i+1][j  ]+=C[i][j] ;
        }
    }
    //slove -----------------
    char in[10] ;
    
    while (~scanf("%s",&in ) ){
          int Ans=0 ,L=strlen(in) ;
          bool ok=1 ;
          for (int i=0 ;i<L ;i++ )Ans+=C[26][i] ;
          
          int a=(int)('a') ;
          for (int i=0 ;i<L && ok ;i++ ){
              if (a>in[i])ok=0 ;
              Ans+=C[ 'z'-a+1 ][ L-i ]-C[ 'z'-in[i]+1 ][ L-i ] ;
              a=in[i]+1 ;
          }
          printf("%d\n",ok?Ans:0)  ;
    }
    
}
