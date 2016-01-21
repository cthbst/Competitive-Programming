#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;
typedef long double LD ;
const LD EPS = 1E-12 ;
const int maxn = 100030 ;

int n ;
LL A ,B ,c[maxn] ,sumC ;

LD Expected(LL start ,LL L ,LL R){  // start+sumC > L
    R = min(R,start+sumC) ;
    L = max(L,start) ;
    LL range = R-L ;    if (range<=0LL )return (LD)0.0 ;
    LD re = 0.0 ;

    int i=0 ;
    while (start+c[i]<=L )start+=c[i++] ;
    /*  start <= L < start+c[i] */
    if (start+c[i]>=R){
        /*  start <= L <R <=start+c[i]  */
        /*  re = (R+L)/2-start          */
        return (LD)(R+L)/2.0-start ;
    }
    /*  else    */
    /*  start <= L < start+c[i] <R */
    re = ( (LD)(start+c[i]+L)/2-start )*( (LD)(start+c[i]-L)/range ) ;
    start+=c[i++] ;
    while (start+c[i]<R){
        re+=(LD)c[i]*c[i]/range/2  ;
        start+=c[i++] ;
    }
    // start< R <=start +c[i]
    re+=(LD)(R-start)*(R-start)/range/2 ;
    return re ;
}

LD solve(){
    //input -----------------
    sumC=0 ;
    cin >> n >> A >> B ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%lld",&c[i]) ;
        sumC+=c[i] ;
    }
    //solve -----------------
    LL L = (LL)ceil ((LD)A/sumC)*sumC-sumC ;
    LL R = (LL)floor((LD)B/sumC)*sumC+sumC ;
    if (R-L==sumC)return Expected(L,A,B) ;

    LD re=(LD)0.0 ;
    re += Expected(L,A,B)*(L+sumC-A)/(B-A) ;
    re += Expected(0,0,sumC)*(R-L-sumC*2)/(B-A) ;
    re += Expected(R-sumC,A,B)*(B-R+sumC)/(B-A) ;

    return re ;
}

int main(){
    freopen("yachtzee.txt","r",stdin) ;
    freopen("pC_out.txt","w",stdout) ;
    int T; scanf("%d",&T ) ;

    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: %.9LF\n",t ,solve() ) ;
    }
}
