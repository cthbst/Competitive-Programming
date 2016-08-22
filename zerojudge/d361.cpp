#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    char sa[105] ,sb[105] ;
    while (scanf("%s%s",sa ,sb )){
        if (sa[0]=='0' && sb[0]=='0')break ;
        if (sb[0]=='0' ){
			puts("1") ;
			continue ;
        }
        int a = sa[ strlen(sa)-1 ]-'0' ;
        int b ,lb=strlen(sb) ;
        if (lb==1)b=sb[0]-'0' ;
        else b=(sb[lb-2]-'0')*10+(sb[lb-1]-'0') ;
        if (b==0)b=100 ;
		b=(b-1)%4+1 ;
        printf("%d\n",( (int)pow(a,b) )%10) ;
    }
}
