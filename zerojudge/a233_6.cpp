#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

typedef long long int LL ;
vector<LL> a ,d ;

#include<ctype.h>

LL getint(){
    char c;
    do c = getchar(); while(!isdigit(c));
    LL result = 0;
    do{
        result = 10 * result + c - 48;
        c = getchar();
    } while(isdigit(c));
    return result;
}


int main(){
    int T ;scanf("%d",&T ) ;

    int N ,M ;
    while (T-- && scanf("%d%d",&N ,&M )){
        //input -------------
        a.resize(N) ;
        for (int i=0 ;i<N ;i++ ){
            a[i]=getint() ;
        }
        //solve -------------
        sort(a.begin(),a.end()) ;
        d.resize(N-1) ;
        for (int i=0 ;i<N-1 ;i++ ){
            d[i]=a[i+1]-a[i] ;
        }
        sort(d.begin(),d.end()) ;

        //output ------------
        LL Ans=0 ;
        for (int i=0 ;i<N-M ;i++ ){
            Ans+=d[i] ;
        }
        printf("%lld\n",Ans) ;
    }
}
