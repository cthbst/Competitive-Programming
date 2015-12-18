#include<bits/stdc++.h>
using namespace std ;

int main(){
    int a[3] ,x[3] ;
    for (int i=0 ;i<3 ;i++ )cin >> a[i] ;
    for (int i=0 ;i<3 ;i++ )cin >> x[i] ;

    for (int i=0 ;i<3 ;i++ )if (a[i]<x[i]){
        for (int j=0 ;j<3 ;j++ )if (i!=j){
            if (a[j]-x[j]<2)continue ;
            int del = (a[j]-x[j])/2 ;
            del = min(del,x[i]-a[i]) ;
            a[i]+=del ;
            a[j]-=del*2 ;
        }
    }

    bool ok=1 ;
    for (int i=0 ;i<3 ;i++ ){
        if (a[i]<x[i])ok=0 ;
    }

    puts(ok?"Yes":"No") ;
}
