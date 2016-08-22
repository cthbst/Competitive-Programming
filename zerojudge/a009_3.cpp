#include <stdio.h>
#include <string.h>
int main(void)
{
    char code[200];
    int i,length;    
    while(scanf("%s",code)==1)
    {
      length = strlen(code);                     
      for(i=0;i<strlen(code);i++)
      {
        code[i]+=('*'-'1') ;       
      }
      printf("%s\n",code)  ;
    }  
    return 0;
}
