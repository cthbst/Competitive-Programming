#include "lib1898.h"
#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100030;
int findSample(int n , int A[], int fa[], int cmd[]){
    static int B[maxn] ;
    memset(B,0,sizeof(B)) ;

    for (int i=n-1 ;i>0 ;i-- ){
        int u = fa[i] ;
        if (cmd[i]==0)A[u]+=B[i] ,B[u]+=A[i] ;
        if (cmd[i]==1)A[u]+=A[i] ,B[u]+=B[i] ;
        if (cmd[i]==2)A[u]=max(A[u]+B[i],B[u]+A[i]) ,B[u]+=B[i] ;
        A[u]=max(A[u],B[u]) ;
    }
    return A[0] ;
}

//int main(){}
