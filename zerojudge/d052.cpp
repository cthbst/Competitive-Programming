#include<stdio.h>
#include<vector>
using namespace std ;

const int INF = 1<<30 ;

void LIS(vector<int> &a ,vector<int> &I ,bool cmp(int,int) ){
    int n=a.size() ;
    I.resize(n) ;
    vector<int> lis ;
    int d= cmp(1,0)*2-1 ;
    lis.push_back(INF*d) ;
    for (int i=n-1 ;i>=0 ;i-- ){
        int L=0 ,R=lis.size() ;
        while (L!=R){
            int M=(L+R)>>1 ;
            if ( cmp(lis[M],a[i]) )R=M ;
            else L=M+1 ;
        }
        lis[L]=a[i] ;
        if (L==lis.size()-1)lis.push_back(INF*d) ;
        I[i]=L ;
    }
}

bool cmpI(int a ,int b ){ return a <= b ; }
bool cmpD(int a ,int b ){ return a >= b ; }

int main(){
    int T ; scanf("%d",&T ) ;

    int n ;
    while (T-- && scanf("%d",&n )){
        vector<int> a(n) ,I(n) ,D(n) ;
        //input -------------
        for (int &x :a){
            scanf("%d",&x) ;
        }
        //dp ----------------
        LIS (a,I,cmpI) ;
        LIS (a,D,cmpD) ;
        int ans=0 ;
        for (int i=0 ;i<n ;i++){
            ans=max(ans,I[i]+D[i]+1) ;
        }
        //output ------------
        printf("%d\n",ans) ;
    }
}
