#include<bits/stdc++.h>
using namespace std ;

int n ,t ,a[10] ;

int solve(){
    int re=0 ; t=0 ;
    scanf("%d",&n ) ;

    for (int i=0 ,ai ;i<n ;i++ ){
        scanf("%d",&ai ) ;
        if (t==0){
            a[t++]=ai ;
        }
        else if (a[t-1]>=ai){ // t>0  ,t = 1 ,2 ,3
            re+= 4-t ;
            a[(t=0)++]=ai ;
        }
        else if (a[t-1]+10>=ai){ //t>0 ,a[t-1]<ai
            a[t++]=ai ;
            if (t==4)t=0 ;
        }
        else { //t>0 ,a[t-1]<ai ,ai-a[t-1]>10
            while (t<4 && a[t-1]+10<ai){
                a[t]=a[t-1]+10 ; re++ ;
                t++ ;
            }
            if (t==4){
                a[(t=0)++]=ai ;
            }
            else {
                a[t++]=ai ;
                if (t==4)t=0 ;
            }
        }
    }
    if (t>0)re+=4-t ;
    return re ;
}

int main(){
    freopen("coding_contest_creation.txt","r",stdin) ;
    freopen("pA_out.txt","w",stdout) ;
    int T ; scanf("%d",&T ) ;

    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: %d\n",t ,solve() ) ;
    }
}
