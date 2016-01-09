#include<bits/stdc++.h>
using namespace std ;

const int maxn = 10000 ;
int n ,a[maxn] ;

vector<int> Prime ;
void build_prime(){
    static bool p[maxn] ;
    memset(p,1,sizeof(p)) ;
    for (int i=2 ;i<maxn ;i++ )if (p[i]){
        Prime.push_back(i) ;
        for (int j=i*i ;j<maxn ;j+=i)p[i]=0 ;
    }
}

int ans ,add ;
void check(int p){
    int re=0 ;
    for (int i=0 ,h=0 ;i<n ;i++ )if (re<add){
        if (h<a[i]) h = p*(int)ceil((double)a[i]/p) ;
        re+=h-a[i] ;
    }
    add=min(add,re) ;
}

int main(){
    build_prime() ;
    int T ; cin >>T ;

    while (T-- && scanf("%d",&n)){
        ans=0 ;
        //input -------------
        scanf("%d",&a[0]) ;
        for (int i=1 ;i<n ;i++ ){
            scanf("%d",&a[i]) ;
            if (a[i]<a[i-1]){
                ans+=a[i-1]-a[i] ;
                a[i]=a[i-1] ;
            }
        }

        //solve -------------
        add = n ;
        for (int p:Prime){
            if (p>a[n-1])break;
            check(p) ;
        }
        //output ------------
        printf("%d\n",ans+add) ;
    }
}
