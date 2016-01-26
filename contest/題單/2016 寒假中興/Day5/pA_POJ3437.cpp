#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

const int maxn = 10000 ;
char s[maxn*2+10] ;
int deep[maxn+1] ,cnt[maxn+1] ;

int main(){
    int T = 0 ;

    while (scanf("%s",s) && strcmp(s,"#")!=0 ){
        int h1=0 ,h2=0 ,h=0 ;

        memset(deep,0,sizeof(deep)) ;
        memset(cnt ,0,sizeof(cnt )) ;
        for (int i=0 ;s[i] ;i++ ){
            if (s[i]=='d')
                h++ ;
            else {  //s[i] = u
                deep[h-1] = max(deep[h-1],deep[h]+cnt[h]+1) ;
                cnt[h+1]=deep[h]=0 ;
                cnt[h--]++ ;
            }
            h1 = max(h1,h) ;
        }
        h2 = deep[0] ;
        //output ------------
        printf("Tree %d: %d => %d\n",++T ,h1 ,h2 ) ;
    }
}
