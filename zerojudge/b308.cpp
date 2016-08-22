#include<stdio.h>
#include<algorithm>
using namespace std ;

const int INF = 1<<29 ;

int coin[5]={1,5,10,50,100} ;

bool can_pay(int a[5],int Pay){
    for (int i=4 ;i>=0 ;i--)if (Pay>=coin[i]){
        int c=min(a[i],Pay/coin[i]) ;
        Pay-=c*coin[i] ;
    }
    return Pay==0 ;
}
int pay_cnt(int b[5],int Pay){
    int re=0 ;
    for (int i=4 ;i>=0 ;i--){
        int c=min(b[i],Pay/coin[i]) ;
        Pay-=c*coin[i] ;
        re+=c ;
    }
    if (Pay>0)return INF ;
    return re ;
}

int main(){
    int T ;scanf("%d",&T ) ;

    int a[5] ,b[5] ,M ;
    while (T--){
        for (int i=0 ;i<5 ;i++ ) scanf("%d",&a[i]) ;
        for (int i=0 ;i<5 ;i++ ) scanf("%d",&b[i]) ;
        scanf("%d",&M ) ;

        int mA=0 ,mB=0 ;
        for (int i=0 ;i<5 ;i++ ) mA+=a[i]*coin[i] ;
        for (int i=0 ;i<5 ;i++ ) mB+=b[i]*coin[i] ;

        if (mA<M){
            puts("I HAVE MAGIC!") ;
            continue ;
        }
        if ( can_pay(a,M) ){
            puts("0") ;
            continue ;
        }
        int ans=INF ;
        for (int i=M ;i<=mA;i++ )if ( can_pay(a,i) ){
            ans=min(ans, pay_cnt(b,i-M) ) ;
        }

        if (ans==INF )puts("YOU ARE MAGICIAN!") ;
        else printf("%d\n",ans ) ;
    }
}
