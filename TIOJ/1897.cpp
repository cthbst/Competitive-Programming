//#include "gondola.h"
#include "lib1897.h"

#include<bits/stdc++.h>
using namespace std ;

int valid(int n, int a[]){
    map<int,bool> memorize ;
    int base=-1 ;
    for (int i=0 ;i<n ;i++ )--a[i] ;
    for (int i=0 ;i<n ;i++ ){
        if (a[i]<n){
            if (base<0)base=i ;
            else if ((a[base]+i-base)%n!=a[i])return 0 ;
        }
        if (memorize[ a[i] ]==1)return 0 ;
        memorize[ a[i] ]=1 ;
    }
    return 1 ;
}

vector< pair<int,int> > item ;

int replacement(int n, int a[], int re[]){
    item.resize(n) ;
    for (int i=0 ;i<n ;i++ ){
        item[i].first = a[i] ;
        item[i].second= i ;
    }
    sort(item.begin(),item.end()) ;

    for (int i=0 ;i<n ;i++ )if (a[i]<=n){
        for (int j=0 ;j<n ;j++ )a[j]=(a[i]+(j-i)+n+n-1)%n+1 ;
        break ;
    }
    if (a[0]>n){
        for (int i=0 ;i<n ;i++ )a[i]=i+1 ;
    }

    int l=n+1 ;
    for (auto e:item)if (e.first>n){
        for (;l<=e.first;l++ ){
            re[l-n-1]=a[ e.second ] ;
            a[ e.second ]=l ;
        }
    }

    return item.back().first-n ;
}

const long long MOD = 1000000009 ;

long long POW (long long a ,long long n ){
    long long re=1 ;
    while (n>0){
        if (n&1)re=re*a%MOD ;
        n>>=1 ;
        a=a*a%MOD ;
    }
    return re ;
}

int countReplacement(int n, int a[]){
    if (valid(n,a)==0)return 0 ;
    for (int i=0 ;i<n ;i++ )++a[i] ;
    item.resize(n) ;
    long long ans = 1;
    for (int i=0 ;i<n ;i++ )item[i]=make_pair(a[i],i) ;
    sort(item.begin(),item.end()) ;
    if (item[0].first>n)ans=(long long)n ;
    int l=n ;
    for (int i=0 ;i<n ;i++ )if (item[i].first>n){
        ans = ans * POW((long long)(n-i),item[i].first-l-1) %MOD ;
        l=item[i].first ;
    }
    return (int)ans ;
}


/*
int main(){
    int n = 21 ;
    int a[]={   14, 15, 64, 17, 59,
                19, 20, 21,  1,  2,
                 3,  4,  5,  6,  7,
                 8,  9, 10, 11, 61,
                13} ;
    int b[100] ;
    printf("%d",countReplacement(n,a)) ;
    //int l = replacement(n,a,b) ;
    //for (int i=0 ;i<l ;i++ )printf("%d ",b[i]) ;
}
//*/
