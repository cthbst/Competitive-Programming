#include<iostream>
using namespace std ;

char d[]="12312312312312312341231234" ;
char in[10000] ;

int main(){
    int T ;
    scanf("%d",&T ) ;

    cin.getline(in,10000) ;
    for (int time=1 ;time<=T ;time++ ){
        cin.getline(in,10000) ;
        int ans=0 ;
        for (int i=0 ;in[i];i++ ){
            if (in[i]==' ')ans++ ;
            else ans+=d[ in[i]-'a' ]-'0' ;
        }
        printf("Case #%d: %d\n",time ,ans ) ;
    }
}
